#include "compiler_context.h"
#include <iostream>
#include <cstdio>

CompilerContext contexto_compilador;

extern FILE* yyin;
extern int yyparse();

CompilerContext::CompilerContext()
    : arquivo_atual("entrada_padrao"), linha_atual(1), coluna_atual(1), 
      coluna_token(1), total_erros(0), contexto_atual("inicializacao") {}

void CompilerContext::iniciar_novo_arquivo(const std::string& nome_arquivo) {
    arquivo_atual = nome_arquivo;
    linha_atual = 1;
    coluna_atual = 1;
    coluna_token = 1;
    contexto_atual = "pacote";
}

void CompilerContext::avancar_coluna(int quantidade) {
    coluna_token = coluna_atual;
    coluna_atual += quantidade;
}

void CompilerContext::nova_linha() {
    linha_atual++;
    coluna_atual = 1;
    coluna_token = 1;
}

bool CompilerContext::processar_arquivo(const std::string& caminho) {
    FILE* arquivo = fopen(caminho.c_str(), "r");
    if (!arquivo) {
        std::cerr << "❌ Erro: Não foi possível abrir o arquivo '" << caminho << "'" << std::endl;
        return false;
    }
    
    yyin = arquivo;
    iniciar_novo_arquivo(caminho);
    std::cout << "📂 Analisando o arquivo: " << caminho << "\n" << std::endl;
    
    int resultado = yyparse();
    fclose(arquivo);
    return (resultado == 0);
}

bool CompilerContext::processar_entrada_padrao() {
    std::cout << "⌨️ Modo interativo ativado. Digite a ontologia TONTO (Ctrl+D para terminar):" << std::endl;
    yyin = stdin;
    iniciar_novo_arquivo("entrada_padrao");
    return (yyparse() == 0);
}

void CompilerContext::set_contexto(const std::string& novo_contexto) {
    contexto_atual = novo_contexto;
}

const std::string& CompilerContext::get_contexto() const {
    return contexto_atual;
}

int CompilerContext::get_total_erros() const {
    return total_erros;
}

void CompilerContext::reportar_erro_lexico(const std::string& mensagem, const std::string& sugestao) {
    total_erros++;
    std::cerr << "\n❌ Erro Léxico em [" << arquivo_atual << "] na Linha " << linha_atual << ", Coluna " << coluna_token
              << ": " << mensagem << std::endl;
    if (!sugestao.empty()) {
        std::cerr << "💡 Sugestão: " << sugestao << std::endl;
    }
}

void CompilerContext::reportar_erro_sintatico(const std::string& detalhe_tecnico) {
    total_erros++;
    std::cerr << "\n❌ Erro Sintático em [" << arquivo_atual << "] na Linha " << linha_atual << ", Coluna " << coluna_token
              << " [Contexto: " << contexto_atual << "]" << std::endl;
    std::cerr << "ℹ️  Detalhe técnico: " << detalhe_tecnico << std::endl;

    if (contexto_atual == "pacote") {
        std::cerr << "💡 Sugestão: A ontologia TONTO deve iniciar com a declaração de um pacote (ex: package meu_pacote)." << std::endl;
    } else if (contexto_atual == "classe") {
        std::cerr << "💡 Sugestão: Verifique se a classe possui estereótipo válido, nome com inicial maiúscula, chaves '{ }' e relações/atributos bem formados." << std::endl;
    } else if (contexto_atual == "atributo") {
        std::cerr << "💡 Sugestão: Atributos devem seguir o formato 'nome_minusculo : tipo'." << std::endl;
    } else if (contexto_atual == "datatype") {
        std::cerr << "💡 Sugestão: Blocos 'datatype' requerem um nome válido e atributos tipados no formato 'nome : tipo'." << std::endl;
    } else if (contexto_atual == "enum") {
        std::cerr << "💡 Sugestão: Enumerações exigem 'enum Nome { Instancia01, Instancia02 }'." << std::endl;
    } else if (contexto_atual == "genset") {
        std::cerr << "💡 Sugestão: Generalizações exigem 'genset Nome' ou blocos equivalentes de taxonomia." << std::endl;
    } else if (contexto_atual == "relacao") {
        std::cerr << "💡 Sugestão: Relações exigem '@estereotipo relation ClasseOrigem [card] -- [card] ClasseDestino'." << std::endl;
    } else {
        std::cerr << "💡 Sugestão: Reveja a sintaxe deste bloco no manual EBNF da linguagem TONTO." << std::endl;
    }
}

TabelaSimbolos& CompilerContext::get_tabela() {
    return tabela_de_simbolos;
}

const TabelaSimbolos& CompilerContext::get_tabela() const {
    return tabela_de_simbolos;
}