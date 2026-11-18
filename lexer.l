%{
#include "tokens.h"
#include "compiler_context.h"
#include <cstdio>
#include <cstring>
#include <string>

extern CompilerContext contexto_compilador;
%}

%option noyywrap
%option yylineno

%%

"//"[^\n]* { 
    contexto_compilador.avancar_coluna(yyleng);
}

"/*" {
    int c;
    contexto_compilador.avancar_coluna(2);
    while ((c = yyinput()) != 0) {
        if (c == '\n') {
            contexto_compilador.nova_linha();
        } else if (c == '*') {
            int proximo = yyinput();
            if (proximo == '/') {
                contexto_compilador.avancar_coluna(2);
                break; 
            } else {
                unput(proximo);
                contexto_compilador.avancar_coluna(1);
            }
        } else {
            contexto_compilador.avancar_coluna(1);
        }
    }
}

[ \t\r]+ { 
    contexto_compilador.avancar_coluna(yyleng);
}

\n { 
    contexto_compilador.nova_linha();
}

"package"     { contexto_compilador.avancar_coluna(yyleng); return TOKEN_PACKAGE; }
"import"      { contexto_compilador.avancar_coluna(yyleng); return TOKEN_IMPORT; }
"enum"        { contexto_compilador.avancar_coluna(yyleng); return TOKEN_ENUM; }
"datatype"    { contexto_compilador.avancar_coluna(yyleng); return TOKEN_DATATYPE; }
"genset"      { contexto_compilador.avancar_coluna(yyleng); return TOKEN_GENSET; }
"specializes" { contexto_compilador.avancar_coluna(yyleng); return TOKEN_SPECIALIZES; }
"relation"    { contexto_compilador.avancar_coluna(yyleng); return TOKEN_RELATION; }
"where"       { contexto_compilador.avancar_coluna(yyleng); return TOKEN_WHERE; }
"general"     { contexto_compilador.avancar_coluna(yyleng); return TOKEN_GENERAL; }
"specifics"   { contexto_compilador.avancar_coluna(yyleng); return TOKEN_SPECIFICS; }
"disjoint"    { contexto_compilador.avancar_coluna(yyleng); return TOKEN_DISJOINT; }
"overlapping" { contexto_compilador.avancar_coluna(yyleng); return TOKEN_OVERLAPPING; }
"complete"    { contexto_compilador.avancar_coluna(yyleng); return TOKEN_COMPLETE; }
"incomplete"  { contexto_compilador.avancar_coluna(yyleng); return TOKEN_INCOMPLETE; }

"number"|"string"|"boolean"|"date"|"time"|"datetime"|"int" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_NATIVE_TYPE;
}

"event"|"situation"|"process"|"category"|"mixin"|"phaseMixin"|"roleMixin"|"historicalRoleMixin"|"kind"|"collective"|"quantity"|"quality"|"mode"|"intrisicMode"|"intrinsicMode"|"extrinsicMode"|"subkind"|"phase"|"role"|"historicalRole"|"relator" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_STEREOTYPE_CLASS;
}

"material"|"derivation"|"comparative"|"mediation"|"characterization"|"externalDependence"|"componentOf"|"memberOf"|"subCollectionOf"|"subQualityOf"|"instantiation"|"termination"|"participational"|"participation"|"historicalDependence"|"creation"|"manifestation"|"bringsAbout"|"triggers"|"composition"|"aggregation"|"inherence"|"value"|"formal"|"constitution" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_STEREOTYPE_RELATION;
}

"ordered"|"const"|"derived"|"subsets"|"redefines" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_META_ATTRIBUTE;
}

"{"|"}"|"("|")"|"["|"]"|"*"|"@"|":"|";"|"," {
    contexto_compilador.avancar_coluna(yyleng);
    return yytext[0]; 
}

"<>--"|"--<>" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_AGGREGATION_SYMBOL;
}

"--" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_ASSOCIATION_SYMBOL;
}

"<o>--"|"--<o>" {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_COMPOSITION_SYMBOL;
}

"\.\." {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_RANGE;
}

[a-zA-Z]+DataType {
    contexto_compilador.avancar_coluna(yyleng);
    yylval.sval = strdup(yytext);
    return TOKEN_NEW_TYPE;
}

[0-9]+ {
    contexto_compilador.avancar_coluna(yyleng);
    return TOKEN_NUMBER;
}

[a-zA-Z_]+[0-9]+ { 
    contexto_compilador.avancar_coluna(yyleng);
    yylval.sval = strdup(yytext);
    return TOKEN_INSTANCE_NAME;
}

[A-Z][a-zA-Z_]* { 
    contexto_compilador.avancar_coluna(yyleng);
    yylval.sval = strdup(yytext);
    return TOKEN_CLASS_NAME;
}

[a-zA-Z]+(_[a-zA-Z]+)* { 
    contexto_compilador.avancar_coluna(yyleng);
    yylval.sval = strdup(yytext);
    return TOKEN_NAME; 
}

[a-zA-Z_][a-zA-Z0-9_]* {
    contexto_compilador.reportar_erro_lexico(
        std::string("Identificador malformado '") + yytext + "'",
        "Nomes com números misturados no meio não são permitidos na convenção TONTO."
    );
    contexto_compilador.avancar_coluna(yyleng);
}

. {
    contexto_compilador.reportar_erro_lexico(
        std::string("Caractere inválido '") + yytext + "'"
    );
    contexto_compilador.avancar_coluna(yyleng);
}

%%