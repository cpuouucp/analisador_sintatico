#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class EscopoClasse {
private:
    std::string nome;
    std::string categoria;
    std::vector<std::string> atributos;
    std::vector<std::string> relacoes_internas;

public:
    EscopoClasse(std::string nome, std::string categoria);

    void adicionar_atributo(const std::string& atributo);
    void adicionar_relacao_interna(const std::string& destino);

    const std::string& get_nome() const { return nome; }
    const std::string& get_categoria() const { return categoria; }
    const std::vector<std::string>& get_atributos() const { return atributos; }
    const std::vector<std::string>& get_relacoes_internas() const { return relacoes_internas; }
};

class EscopoPacote {
private:
    std::string nome;
    std::vector<EscopoClasse> classes;
    std::vector<std::string> datatypes;
    std::vector<std::string> enums;
    std::vector<std::string> gensets;
    std::vector<std::string> relacoes_externas;

public:
    explicit EscopoPacote(std::string nome);

    EscopoClasse& adicionar_classe(const std::string& nome, const std::string& categoria);
    void adicionar_datatype(const std::string& nome);
    void adicionar_enum(const std::string& nome);
    void adicionar_genset(const std::string& nome);
    void adicionar_relacao_externa(const std::string& descricao);

    const std::string& get_nome() const { return nome; }
    const std::vector<EscopoClasse>& get_classes() const { return classes; }
    const std::vector<std::string>& get_datatypes() const { return datatypes; }
    const std::vector<std::string>& get_enums() const { return enums; }
    const std::vector<std::string>& get_gensets() const { return gensets; }
    const std::vector<std::string>& get_relacoes_externas() const { return relacoes_externas; }
};

class TabelaSimbolos {
private:
    std::unordered_map<std::string, std::string> tabela_dispersao;
    std::vector<EscopoPacote> lista_pacotes;
    std::vector<std::string> lista_imports;

    EscopoPacote* pacote_atual = nullptr;
    EscopoClasse* classe_atual = nullptr;

    int qtd_pacotes = 0;
    int qtd_classes = 0;
    int qtd_relacoes = 0;
    int qtd_enum = 0;
    int qtd_datatypes = 0;
    int qtd_gensets = 0;

public:
    TabelaSimbolos() = default;
    ~TabelaSimbolos() = default;

    void inserir_simbolo(const std::string& nome, const std::string& categoria);
    void registrar_pacote(const std::string& nome, bool is_import = false);

    void iniciar_classe(const std::string& nome, const std::string& categoria);
    void finalizar_classe();

    void registrar_atributo(const std::string& nome, const std::string& categoria, const std::string& tipo_extra = "", const std::string& cat_extra = "");
    void registrar_relacao_interna(const std::string& classe_destino);
    void registrar_relacao_externa(const std::string& classe_origem, const std::string& classe_destino, const std::string& nome_relacao = "");

    void registrar_enum(const std::string& nome);
    void registrar_datatype(const std::string& nome);
    void registrar_genset(const std::string& nome, const std::string& classe_geral = "");

    void imprimir_tabela_dispersao() const;
    void imprimir_tabela_sintese() const;
};