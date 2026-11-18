#pragma once

#include <string>
#include "symbols_table.h"

class CompilerContext {
private:
    std::string arquivo_atual;
    int linha_atual;
    int coluna_atual;
    int coluna_token;
    int total_erros;
    std::string contexto_atual;
    TabelaSimbolos tabela_de_simbolos;

public:
    CompilerContext();
    ~CompilerContext() = default;

    void iniciar_novo_arquivo(const std::string& nome_arquivo);
    void avancar_coluna(int quantidade);
    void nova_linha();
    bool processar_arquivo(const std::string& caminho);
    bool processar_entrada_padrao();

    void set_contexto(const std::string& novo_contexto);
    const std::string& get_contexto() const;
    int get_total_erros() const;

    void reportar_erro_lexico(const std::string& mensagem, const std::string& sugestao = "");
    void reportar_erro_sintatico(const std::string& detalhe_tecnico);

    TabelaSimbolos& get_tabela();
    const TabelaSimbolos& get_tabela() const;
};

extern CompilerContext contexto_compilador;