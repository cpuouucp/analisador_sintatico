%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "compiler_context.h"

using namespace std;

extern int yylex();

void yyerror(const char *s) {
    contexto_compilador.reportar_erro_sintatico(s);
}
%}

%union {
    char* sval;
}

%token TOKEN_PACKAGE TOKEN_IMPORT TOKEN_ENUM TOKEN_DATATYPE TOKEN_GENSET TOKEN_SPECIALIZES TOKEN_RELATION
%token TOKEN_WHERE TOKEN_GENERAL TOKEN_SPECIFICS TOKEN_NATIVE_TYPE TOKEN_STEREOTYPE_CLASS
%token TOKEN_STEREOTYPE_RELATION TOKEN_META_ATTRIBUTE TOKEN_AGGREGATION_SYMBOL TOKEN_ASSOCIATION_SYMBOL TOKEN_COMPOSITION_SYMBOL
%token TOKEN_RANGE TOKEN_NUMBER TOKEN_DISJOINT TOKEN_OVERLAPPING TOKEN_COMPLETE TOKEN_INCOMPLETE

%token <sval> TOKEN_NEW_TYPE TOKEN_INSTANCE_NAME TOKEN_CLASS_NAME TOKEN_NAME

%type <sval> nome_pacote tipo_atributo

%%

programa:
    declaracao_pacote lista_elementos
    {
        cout << "\n✅ Análise sintática e construção da tabela de símbolos concluídas com sucesso!" << endl;
    }
;

declaracao_pacote:
    TOKEN_PACKAGE nome_pacote
    {
        contexto_compilador.set_contexto("pacote");
        contexto_compilador.get_tabela().registrar_pacote($2, false);
        free($2);
    }
    | TOKEN_IMPORT nome_pacote
    {
        contexto_compilador.set_contexto("pacote");
        contexto_compilador.get_tabela().registrar_pacote($2, true);
        free($2);
    }
;

nome_pacote:
    TOKEN_NAME { $$ = $1; }
    | TOKEN_CLASS_NAME { $$ = $1; }
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
    TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME
    {
        contexto_compilador.set_contexto("classe");
        contexto_compilador.get_tabela().iniciar_classe($2, "Classe Ontológica (Simples)");
        contexto_compilador.get_tabela().finalizar_classe();
        free($2);
    }
    | TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME '{'
      {
          contexto_compilador.set_contexto("classe");
          contexto_compilador.get_tabela().iniciar_classe($2, "Classe Ontológica (com Escopo)");
      }
      corpo_classe_opt '}'
      {
          contexto_compilador.get_tabela().finalizar_classe();
          free($2);
      }
    | TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME TOKEN_SPECIALIZES lista_classes_mae
    {
        contexto_compilador.set_contexto("classe");
        contexto_compilador.get_tabela().iniciar_classe($2, "Classe Ontológica (Especializada)");
        contexto_compilador.get_tabela().finalizar_classe();
        free($2);
    }
    | TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME TOKEN_SPECIALIZES lista_classes_mae '{'
      {
          contexto_compilador.set_contexto("classe");
          contexto_compilador.get_tabela().iniciar_classe($2, "Classe Ontológica (Especializada com Escopo)");
      }
      corpo_classe_opt '}'
      {
          contexto_compilador.get_tabela().finalizar_classe();
          free($2);
      }
;

lista_classes_mae:
    lista_classes_mae ',' TOKEN_CLASS_NAME { free($3); }
    | TOKEN_CLASS_NAME { free($1); }
;

corpo_classe_opt:
    corpo_classe_opt item_classe
    | /* vazio */
;

item_classe:
    atributo
    | relacao_interna
;

atributo:
    TOKEN_NAME ':' tipo_atributo cardinalidade_opt meta_atributos_opt
    {
        contexto_compilador.set_contexto("atributo");
        contexto_compilador.get_tabela().registrar_atributo($1, "Atributo Interno");
        free($1);
        free($3);
    }
;

tipo_atributo:
    TOKEN_NATIVE_TYPE { $$ = strdup("nativo"); }
    | TOKEN_CLASS_NAME { $$ = $1; }
    | TOKEN_NEW_TYPE { $$ = $1; }
    | TOKEN_NAME { $$ = $1; }
;

meta_atributos_opt:
    '{' lista_meta '}'
    | /* vazio */
;

lista_meta:
    lista_meta TOKEN_META_ATTRIBUTE
    | TOKEN_META_ATTRIBUTE
;

regra_enum:
    TOKEN_ENUM TOKEN_CLASS_NAME '{' lista_instancias '}'
    {
        contexto_compilador.set_contexto("enum");
        contexto_compilador.get_tabela().registrar_enum($2);
        free($2);
    }
;

lista_instancias:
    lista_instancias ',' nome_instancia
    | nome_instancia
;

nome_instancia:
    TOKEN_INSTANCE_NAME { free($1); }
    | TOKEN_CLASS_NAME { free($1); }
    | TOKEN_NAME { free($1); }
;

regra_datatype:
    TOKEN_DATATYPE TOKEN_NEW_TYPE '{' atributos_opt '}'
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype($2);
        free($2);
    }
    | TOKEN_DATATYPE TOKEN_CLASS_NAME '{' atributos_opt '}'
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype($2);
        free($2);
    }
    | TOKEN_DATATYPE TOKEN_NAME '{' atributos_opt '}'
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype($2);
        free($2);
    }
;

atributos_opt:
    atributos_opt atributo
    | /* vazio */
;

regra_genset:
    genset_declaracao
;

genset_declaracao:
    TOKEN_GENSET TOKEN_CLASS_NAME '{' TOKEN_GENERAL TOKEN_CLASS_NAME TOKEN_SPECIFICS classes_especializadas '}'
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset($2, $5);
        free($2);
        free($5);
    }
    | TOKEN_GENSET '{' TOKEN_GENERAL TOKEN_CLASS_NAME TOKEN_SPECIFICS classes_especializadas '}'
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset("GensetBloco", $4);
        free($4);
    }
    | genset_restricao TOKEN_CLASS_NAME TOKEN_WHERE classes_especializadas TOKEN_SPECIALIZES TOKEN_CLASS_NAME
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset($2, $6);
        free($2);
        free($6);
    }
    | genset_restricao TOKEN_NAME TOKEN_WHERE classes_especializadas TOKEN_SPECIALIZES TOKEN_CLASS_NAME
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset($2, $6);
        free($2);
        free($6);
    }
;

genset_restricao:
    TOKEN_DISJOINT genset_completude 
    | TOKEN_OVERLAPPING genset_completude
    | genset_completude
;

genset_completude:
    TOKEN_COMPLETE TOKEN_GENSET
    | TOKEN_INCOMPLETE TOKEN_GENSET
    | TOKEN_GENSET
;

classes_especializadas:
    classes_especializadas ',' TOKEN_CLASS_NAME 
    {
        free($3);
    }
    | TOKEN_CLASS_NAME
    {
        free($1);
    }
;

relacao_interna:
    '@' TOKEN_STEREOTYPE_RELATION cardinalidade_opt simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME
    {
        contexto_compilador.set_contexto("relacao");
        contexto_compilador.get_tabela().registrar_relacao_interna($6);
        free($6);
    }
    | '@' TOKEN_STEREOTYPE_RELATION cardinalidade_opt simbolo_relacao TOKEN_NAME simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME
    {
        contexto_compilador.set_contexto("relacao");
        contexto_compilador.get_tabela().registrar_relacao_interna($8);
        free($5);
        free($8);
    }
;

relacao_externa:
    '@' TOKEN_STEREOTYPE_RELATION TOKEN_RELATION relacao_classes
    {
        contexto_compilador.set_contexto("relacao");
    }
    | '@' TOKEN_STEREOTYPE_RELATION TOKEN_NAME relacao_classes
    {
        contexto_compilador.set_contexto("relacao");
    }
;

relacao_classes:
    TOKEN_CLASS_NAME cardinalidade_opt simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME
    {
        contexto_compilador.get_tabela().registrar_relacao_externa($1, $5);
        free($1);
        free($5);
    }
    | TOKEN_CLASS_NAME cardinalidade_opt simbolo_relacao TOKEN_NAME simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME
    {
        contexto_compilador.get_tabela().registrar_relacao_externa($1, $7, $4);
        free($1);
        free($4);
        free($7);
    }
;

cardinalidade_opt:
    '[' TOKEN_NUMBER ']'
    | '[' TOKEN_NUMBER TOKEN_RANGE '*' ']'
    | '[' '*' TOKEN_RANGE TOKEN_NUMBER ']'
    | '[' TOKEN_NUMBER TOKEN_RANGE TOKEN_NUMBER ']'
    | '[' '*' TOKEN_RANGE '*' ']'
    | '[' '*' ']'
    | '[' ']'
    | /* vazio */
;

simbolo_relacao:
    TOKEN_AGGREGATION_SYMBOL
    | TOKEN_ASSOCIATION_SYMBOL
    | TOKEN_COMPOSITION_SYMBOL
;

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            contexto_compilador.processar_arquivo(argv[i]);
        }
    } else {
        contexto_compilador.processar_entrada_padrao();
    }

    contexto_compilador.get_tabela().imprimir_tabela_dispersao();
    contexto_compilador.get_tabela().imprimir_tabela_sintese();

    return 0;
}