%{
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

extern int yylex();
extern int linha_atual;
extern int coluna_atual;
extern FILE* yyin;

string contexto_atual = "inicializacao";

// Contadores para a Tabela de Síntese
int quantidade_pacotes = 0;
int quantidade_classes = 0;
int quantidade_relacoes = 0;
int quantidade_enum = 0;
int quantidade_dataypes = 0;
int quantidade_gensets = 0;

// Requisito 2: Tabela de Dispersão (Symbol Table)
unordered_map<string, string> tabela_de_simbolos;

void inserir_simbolo(const string& nome, const string& categoria) {
    tabela_de_simbolos[nome] = categoria;
}

// Requisito 5b: Relatório de erros da ontologia com sugestões
void yyerror(const char *s) {
    cerr << "\n❌ Erro Sintático na Linha " << linha_atual << ", Coluna " << coluna_atual 
         << " [Contexto: " << contexto_atual << "]" << endl;
    cerr << "   Detalhe técnico: " << s << endl;

    if (contexto_atual == "pacote") {
        cerr << "   💡 Sugestão: A ontologia TONTO deve iniciar com a declaração de um pacote (ex: package meu_pacote)." << endl;
    } 
    else if (contexto_atual == "classe") {
        cerr << "   💡 Sugestão: Verifique se a classe possui um estereótipo válido seguido de um nome com inicial maiúscula e chaves '{ }'." << endl;
    } 
    else if (contexto_atual == "datatype") {
        cerr << "   💡 Sugestão: Blocos 'datatype' requerem um nome válido e atributos tipados no formato 'nome : tipo'." << endl;
    }
    else if (contexto_atual == "enum") {
        cerr << "   💡 Sugestão: Enumerações exigem 'enum Nome { Instancia1, Instancia2 }'." << endl;
    }
    else {
        cerr << "   💡 Sugestão: Reveja a sintaxe deste bloco no manual EBNF da linguagem TONTO." << endl;
    }
}
%}

%union {
    char* sval;
}

%token TOKEN_PACKAGE TOKEN_IMPORT TOKEN_ENUM TOKEN_DATATYPE TOKEN_GENSET TOKEN_SPECIALIZES
%token TOKEN_NATIVE_TYPE TOKEN_STEREOTYPE_CLASS TOKEN_STEREOTYPE_RELATION TOKEN_META_ATTRIBUTE
%token TOKEN_SPECIAL_SYMBOL TOKEN_INT_NUMBER

%token <sval> TOKEN_CLASS_NAME
%token <sval> TOKEN_NAME          
%token <sval> TOKEN_INSTANCE_NAME
%token <sval> TOKEN_NEW_TYPE

%%

programa:
    { contexto_atual = "pacote"; }
    declaracao_pacote 
    { contexto_atual = "corpo_ontologia"; }
    lista_elementos
    {
        cout << "\n✅ Análise sintática e construção da tabela de símbolos concluídas com sucesso!" << endl;
    }
;

declaracao_pacote:
    TOKEN_PACKAGE TOKEN_NAME
    {
        quantidade_pacotes++;
        inserir_simbolo($2, "Pacote Ontológico");
        free($2);
    }
    | TOKEN_IMPORT TOKEN_NAME
    {
        inserir_simbolo($2, "Importação de Pacote");
        free($2);
    }
;

lista_elementos:
    lista_elementos elemento
    | /* vazio */
;

elemento:
    regra_classe
    | regra_enum
    | regra_datatype
    | regra_genset
    | relacao_externa
    | declaracao_pacote
;

regra_classe:
    { contexto_atual = "classe"; }
    TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME
    {
        quantidade_classes++;
        inserir_simbolo($3, "Classe Ontológica (Simples)");
        free($3);
    }
    | { contexto_atual = "classe"; }
      TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME '{' atributos_opt '}'
    {
        quantidade_classes++;
        inserir_simbolo($3, "Classe Ontológica (com Atributos)");
        free($3);
    }
    | { contexto_atual = "classe"; }
      TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME TOKEN_SPECIALIZES TOKEN_CLASS_NAME
    {
        quantidade_classes++;
        inserir_simbolo($3, "Classe Ontológica (Especializada)");
        free($3);
        free($5); 
    }
;

atributos_opt:
    atributos_opt atributo
    | /* vazio */
;

atributo:
    TOKEN_NAME ':' TOKEN_NATIVE_TYPE
    {
        quantidade_relacoes++;
        inserir_simbolo($1, "Atributo Interno");
        free($1);
    }
    | TOKEN_NAME ':' TOKEN_CLASS_NAME
    {
        quantidade_relacoes++;
        inserir_simbolo($1, "Associação de Classe");
        free($1);
        free($3);
    }
;

regra_enum:
    { contexto_atual = "enum"; }
    TOKEN_ENUM TOKEN_CLASS_NAME '{' lista_instancias '}'
    {
        quantidade_enum++;
        inserir_simbolo($3, "Enumeração");
        free($3);
    }
;

lista_instancias:
    TOKEN_INSTANCE_NAME { free($1); }
    | TOKEN_CLASS_NAME { free($1); }
    | lista_instancias ',' TOKEN_INSTANCE_NAME { free($3); }
    | lista_instancias ',' TOKEN_CLASS_NAME { free($3); }
;

regra_datatype:
    { contexto_atual = "datatype"; }
    TOKEN_DATATYPE TOKEN_CLASS_NAME '{' atributos_opt '}'
    {
        quantidade_dataypes++;
        inserir_simbolo($3, "DataType Complexo");
        free($3);
    }
;

regra_genset:
    { contexto_atual = "genset"; }
    TOKEN_GENSET TOKEN_CLASS_NAME
    {
        quantidade_gensets++;
        inserir_simbolo($3, "Generalization Set");
        free($3);
    }
;

relacao_externa:
    '@' TOKEN_STEREOTYPE_RELATION TOKEN_NAME TOKEN_CLASS_NAME
    {
        quantidade_relacoes++;
        inserir_simbolo($3, "Relação Externa");
        free($3);
        free($4);
    }
;

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* ficheiro = fopen(argv[1], "r");
        if (!ficheiro) {
            cerr << "❌ Erro: Não foi possível abrir o ficheiro '" << argv[1] << "'" << endl;
            return 1;
        }
        yyin = ficheiro;
        cout << "📂 A analisar o ficheiro: " << argv[1] << "\n" << endl;
    } else {
        cout << "⌨️  Modo interativo ativado. Digite a ontologia TONTO (Ctrl+D para terminar):" << endl;
        yyin = stdin;
    }

    yyparse();

    // Requisito 2 & 5a: Relatório 1 - Tabela de Dispersão (Symbol Table)
    cout << "\n=================================================================" << endl;
    cout << "          TABELA DE DISPERSÃO (TABELA DE SÍMBOLOS - HASH)        " << endl;
    cout << "=================================================================" << endl;
    cout << left << setw(35) << "IDENTIFICADOR (CHAVE)" << " | " << "CATEGORIA / ESTEREÓTIPO" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (const auto& par : tabela_de_simbolos) {
        cout << left << setw(35) << par.first << " | " << par.second << endl;
    }
    cout << "=================================================================" << endl;

    // Requisito 5a: Relatório 2 - Tabela de Síntese dos Construtos
    cout << "\n=================================================================" << endl;
    cout << "                 TABELA DE SÍNTESE DA ONTOLOGIA                  " << endl;
    cout << "=================================================================" << endl;
    cout << left << setw(40) << "CONCEITO / CONSTRUTO" << " | " << "QUANTIDADE" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << left << setw(40) << "Pacotes ontológicos" << " | " << quantidade_pacotes << endl;
    cout << left << setw(40) << "Classes reconhecidas" << " | " << quantidade_classes << endl;
    cout << left << setw(40) << "Relações e atributos" << " | " << quantidade_relacoes << endl;
    cout << left << setw(40) << "Enumerações (enum)" << " | " << quantidade_enum << endl;
    cout << left << setw(40) << "Tipos de dados (datatype)" << " | " << quantidade_dataypes << endl;
    cout << left << setw(40) << "Generalization Sets (genset)" << " | " << quantidade_gensets << endl;
    cout << "=================================================================" << endl;

    return 0;
}