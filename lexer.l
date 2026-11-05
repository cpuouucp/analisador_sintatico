%{

#include "tokens.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

extern int linha_atual;
extern int coluna_atual;

%}

%option noyywrap
%option yylineno

%%

// --- ESPAÇOS E COMENTÁRIOS ---
"//"[^\n]* { coluna_atual += yyleng; }
[ \t]+     { coluna_atual += yyleng; }
\n         { linha_atual++; coluna_atual = 1; }

"/*" {
    int c;
    coluna_atual += 2;
    while ((c = yyinput()) != 0) {
        if (c == '\n') { linha_atual++; coluna_atual = 1; }
        else if (c == '*') {
            int proximo = yyinput();
            if (proximo == '/') { coluna_atual += 2; break; }
            else { unput(proximo); coluna_atual++; }
        } else { coluna_atual++; }
    }
}

// --- PALAVRAS-CHAVE ESTRUTURAIS ---
"package"     { coluna_atual += yyleng; return TOKEN_PACKAGE; }
"import"      { coluna_atual += yyleng; return TOKEN_IMPORT; }
"enum"        { coluna_atual += yyleng; return TOKEN_ENUM; }
"datatype"    { coluna_atual += yyleng; return TOKEN_DATATYPE; }
"genset"      { coluna_atual += yyleng; return TOKEN_GENSET; }
"specializes" { coluna_atual += yyleng; return TOKEN_SPECIALIZES; }

// --- TIPOS NATIVOS ---
"number"|"string"|"boolean"|"date"|"time"|"datetime" {
    coluna_atual += yyleng;
    return TOKEN_NATIVE_TYPE;
}

// --- ESTEREÓTIPOS DE CLASSE E RELAÇÃO ---
"event"|"situation"|"process"|"category"|"mixin"|"phaseMixin"|"roleMixin"|"historicalRoleMixin"|"kind"|"collective"|"quantity"|"quality"|"mode"|"intrisicMode"|"extrinsicMode"|"subkind"|"phase"|"role"|"historicalRole" {
    coluna_atual += yyleng;
    return TOKEN_STEREOTYPE_CLASS;
}

"material"|"derivation"|"comparative"|"mediation"|"characterization"|"externalDependence"|"componentOf"|"memberOf"|"subCollectionOf"|"subQualityOf"|"instantiation"|"termination"|"participational"|"participation"|"historicalDependence"|"creation"|"manifestation"|"bringsAbout"|"triggers"|"composition"|"aggregation"|"inherence"|"value"|"formal"|"constitution" {
    coluna_atual += yyleng;
    return TOKEN_STEREOTYPE_RELATION;
}

// --- META-ATRIBUTOS ---
"ordered"|"const"|"derived"|"subsets"|"redefines" {
    coluna_atual += yyleng;
    return TOKEN_META_ATTRIBUTE;
}

// --- SÍMBOLOS E PONTUAÇÃO ---
"{"|"}"|"("|")"|"["|"]"|"*"|"@"|":"|";"|"," {
    coluna_atual += yyleng;
    return yytext[0]; 
}

"<>--"|"--<>"|"\.\."|"<o>--"|"--<o>"|"--" {
    coluna_atual += yyleng;
    return TOKEN_SPECIAL_SYMBOL;
}

// --- IDENTIFICADORES E PADRÕES ESPECÍFICOS ---

/* Tipos Customizados (Terminam com DataType) */
[a-zA-Z]+DataType {
    coluna_atual += yyleng;
    yylval.sval = strdup(yytext);
    return TOKEN_NEW_TYPE;
}

/* Números inteiros */
[0-9]+ {
    coluna_atual += yyleng;
    return TOKEN_INT_NUMBER;
}

/* Instâncias (Terminam com número) */
[a-zA-Z_]+[0-9]+ { 
    coluna_atual += yyleng;
    yylval.sval = strdup(yytext);
    return TOKEN_INSTANCE_NAME;
}

/* Classes (Obrigigatoriamente iniciam com Letra Maiúscula) */
[A-Z][a-zA-Z_]* { 
    coluna_atual += yyleng;
    yylval.sval = strdup(yytext);
    return TOKEN_CLASS_NAME;
}

/* Pacotes, Atributos e Relações (Nomes gerais com sublinhado opcional) */
[a-zA-Z]+(_[a-zA-Z]+)* { 
    coluna_atual += yyleng;
    yylval.sval = strdup(yytext);
    return TOKEN_NAME; 
}

[a-zA-Z_][a-zA-Z0-9_]* {
    /* Esta regra vai engolir QUALQUER palavra inteira (letras/números misturados) */
    /* que não tenha se encaixado perfeitamente nas regras válidas acima (como C4sa) */
    cout << "\n";
    cout << "❌ Erro Léxico na Linha " << linha_atual << ", Coluna " << coluna_atual 
         << ": Identificador malformado '" << yytext << "'" << endl;
    cout << "   💡 Sugestão: Nomes com números misturados no meio não são permitidos na convenção TONTO." << endl;
    coluna_atual += yyleng;
}

// --- ERRO LÉXICO ---
. {
    cout << "❌ Erro Léxico na Linha " << linha_atual << ", Coluna " << coluna_atual 
         << ": Caractere inválido '" << yytext << "'" << endl;
    coluna_atual += yyleng;
}

%%