#include "symbols_table.h"
#include <iostream>
#include <iomanip>
#include <utility>

EscopoClasse::EscopoClasse(std::string nome, std::string categoria)
    : nome(std::move(nome)), categoria(std::move(categoria)) {}

void EscopoClasse::adicionar_atributo(const std::string& atributo) {
    atributos.push_back(atributo);
}

void EscopoClasse::adicionar_relacao_interna(const std::string& destino) {
    relacoes_internas.push_back(destino);
}

EscopoPacote::EscopoPacote(std::string nome)
    : nome(std::move(nome)) {}

EscopoClasse& EscopoPacote::adicionar_classe(const std::string& nome_cls, const std::string& categoria_cls) {
    classes.emplace_back(nome_cls, categoria_cls);
    return classes.back();
}

void EscopoPacote::adicionar_datatype(const std::string& nome_dt) {
    datatypes.push_back(nome_dt);
}

void EscopoPacote::adicionar_enum(const std::string& nome_enum) {
    enums.push_back(nome_enum);
}

void EscopoPacote::adicionar_genset(const std::string& nome_gs) {
    gensets.push_back(nome_gs);
}

void EscopoPacote::adicionar_relacao_externa(const std::string& descricao) {
    relacoes_externas.push_back(descricao);
}

void TabelaSimbolos::inserir_simbolo(const std::string& nome, const std::string& categoria) {
    tabela_dispersao[nome] = categoria;
}

void TabelaSimbolos::registrar_pacote(const std::string& nome, bool is_import) {
    qtd_pacotes++;
    if (!is_import) {
        lista_pacotes.emplace_back(nome);
        pacote_atual = &lista_pacotes.back();
        classe_atual = nullptr;
        inserir_simbolo(nome, "Declaração de Pacote Ontológico");
    } else {
        lista_imports.push_back(nome);
        inserir_simbolo(nome, "Importação de Pacote Ontológico");
    }
}

void TabelaSimbolos::iniciar_classe(const std::string& nome, const std::string& categoria) {
    if (pacote_atual == nullptr) {
        registrar_pacote("pacote_padrao", false);
    }
    qtd_classes++;
    classe_atual = &pacote_atual->adicionar_classe(nome, categoria);
    inserir_simbolo(nome, categoria);
}

void TabelaSimbolos::finalizar_classe() {
    classe_atual = nullptr;
}

void TabelaSimbolos::registrar_atributo(const std::string& nome, const std::string& categoria, const std::string& tipo_extra, const std::string& cat_extra) {
    qtd_relacoes++;
    inserir_simbolo(nome, categoria);

    if (!tipo_extra.empty() && !cat_extra.empty()) {
        inserir_simbolo(tipo_extra, cat_extra);
    }

    if (classe_atual != nullptr) {
        classe_atual->adicionar_atributo(nome);
    }
}

void TabelaSimbolos::registrar_relacao_interna(const std::string& classe_destino) {
    qtd_relacoes++;
    inserir_simbolo(classe_destino, "Relação Interna");

    if (classe_atual != nullptr) {
        classe_atual->adicionar_relacao_interna(classe_destino);
    }
}

void TabelaSimbolos::registrar_relacao_externa(const std::string& classe_origem, const std::string& classe_destino, const std::string& nome_relacao) {
    qtd_relacoes++;
    std::string descricao = classe_origem + " -- " + classe_destino;

    if (!nome_relacao.empty()) {
        inserir_simbolo(nome_relacao, "Relação Externa Nomeada");
        descricao = nome_relacao + " (" + descricao + ")";
    } else {
        inserir_simbolo(classe_origem, "Relação Externa (Origem/Relator)");
        inserir_simbolo(classe_destino, "Classe Ontológica (Destino)");
    }

    if (pacote_atual != nullptr) {
        pacote_atual->adicionar_relacao_externa(descricao);
    }
}

void TabelaSimbolos::registrar_enum(const std::string& nome) {
    qtd_enum++;
    inserir_simbolo(nome, "Classe Enumerada (Enum)");
    if (pacote_atual != nullptr) {
        pacote_atual->adicionar_enum(nome);
    }
}

void TabelaSimbolos::registrar_datatype(const std::string& nome) {
    qtd_datatypes++;
    inserir_simbolo(nome, "Type Complexo (Datatype)");
    if (pacote_atual != nullptr) {
        pacote_atual->adicionar_datatype(nome);
    }
}

void TabelaSimbolos::registrar_genset(const std::string& nome, const std::string& classe_geral) {
    qtd_gensets++;
    inserir_simbolo(nome, "Generalization Set");
    if (!classe_geral.empty()) {
        inserir_simbolo(classe_geral, "Classe Geral (Genset)");
    }
    if (pacote_atual != nullptr) {
        pacote_atual->adicionar_genset(nome);
    }
}

void TabelaSimbolos::imprimir_tabela_dispersao() const {
    std::cout << "\n======================================================================\n";
    std::cout << "             TABELA DE DISPERSÃO (TABELA DE SÍMBOLOS - HASH)          \n";
    std::cout << "======================================================================\n";
    std::cout << std::left << std::setw(35) << "IDENTIFICADOR / LEXEMA" << " | " << "CATEGORIA / TOKEN\n";
    std::cout << "----------------------------------------------------------------------\n";
    for (const auto& par : tabela_dispersao) {
        std::cout << std::left << std::setw(35) << par.first << " | " << par.second << "\n";
    }
    std::cout << "======================================================================\n";
}

void TabelaSimbolos::imprimir_tabela_sintese() const {
    std::cout << "\n======================================================================\n";
    std::cout << "                   TABELA DE SÍNTESE DA ONTOLOGIA                     \n";
    std::cout << "======================================================================\n";
    std::cout << std::left << std::setw(45) << "CONCEITO / CONSTRUTO" << " | " << "QUANTIDADE\n";
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(46) << "Pacotes Ontológicos (package + import)" << " | " << qtd_pacotes << "\n";
    std::cout << std::left << std::setw(46) << "Classes Ontológicas Reconhecidas" << " | " << qtd_classes << "\n";
    std::cout << std::left << std::setw(47) << "Relações, Cardinalidade e Atributos" << " | " << qtd_relacoes << "\n";
    std::cout << std::left << std::setw(45) << "Classes Enumeradas (enum)" << " | " << qtd_enum << "\n";
    std::cout << std::left << std::setw(45) << "Tipos de Dados Complexos (datatype)" << " | " << qtd_datatypes << "\n";
    std::cout << std::left << std::setw(45) << "Generalization Sets (genset)" << " | " << qtd_gensets << "\n";
    std::cout << "======================================================================\n";

    std::cout << "\n------------------- VISÃO DETALHADA POR PACOTE -----------------------\n";

    if (!lista_imports.empty()) {
        std::cout << "\n📥 PACOTES IMPORTADOS (" << lista_imports.size() << "): ";
        for (size_t i = 0; i < lista_imports.size(); ++i) {
            std::cout << lista_imports[i] << (i + 1 < lista_imports.size() ? ", " : "");
        }
        std::cout << "\n";
    }

    for (const auto& pkg : lista_pacotes) {
        std::cout << "\n📦 PACOTE DECLARADO: " << pkg.get_nome() << "\n";
        std::cout << "----------------------------------------------------------------------\n";

        std::cout << "  🔹 CLASSES (" << pkg.get_classes().size() << "):\n";
        for (const auto& cls : pkg.get_classes()) {
            std::cout << "     • " << std::left << std::setw(26) << cls.get_nome()
                      << " | Atributos: " << cls.get_atributos().size()
                      << " | Relações Internas: " << cls.get_relacoes_internas().size() << "\n";

            if (!cls.get_atributos().empty()) {
                std::cout << "         └─ Atributos: ";
                for (size_t i = 0; i < cls.get_atributos().size(); ++i) {
                    std::cout << cls.get_atributos()[i] << (i + 1 < cls.get_atributos().size() ? ", " : "");
                }
                std::cout << "\n";
            }

            if (!cls.get_relacoes_internas().empty()) {
                std::cout << "         └─ Relações Internas com: ";
                for (size_t i = 0; i < cls.get_relacoes_internas().size(); ++i) {
                    std::cout << cls.get_relacoes_internas()[i] << (i + 1 < cls.get_relacoes_internas().size() ? ", " : "");
                }
                std::cout << "\n";
            }
        }

        if (!pkg.get_relacoes_externas().empty()) {
            std::cout << "\n  🔗 RELAÇÕES EXTERNAS (" << pkg.get_relacoes_externas().size() << "):\n";
            for (const auto& ext : pkg.get_relacoes_externas()) {
                std::cout << "     • " << ext << "\n";
            }
        }

        if (!pkg.get_datatypes().empty()) {
            std::cout << "\n  🧱 DATATYPES (" << pkg.get_datatypes().size() << "): ";
            for (size_t i = 0; i < pkg.get_datatypes().size(); ++i) {
                std::cout << pkg.get_datatypes()[i] << (i + 1 < pkg.get_datatypes().size() ? ", " : "");
            }
            std::cout << "\n";
        }

        if (!pkg.get_enums().empty()) {
            std::cout << "  📋 ENUMS (" << pkg.get_enums().size() << "): ";
            for (size_t i = 0; i < pkg.get_enums().size(); ++i) {
                std::cout << pkg.get_enums()[i] << (i + 1 < pkg.get_enums().size() ? ", " : "");
            }
            std::cout << "\n";
        }

        if (!pkg.get_gensets().empty()) {
            std::cout << "  🌳 GENSETS (" << pkg.get_gensets().size() << "): ";
            for (size_t i = 0; i < pkg.get_gensets().size(); ++i) {
                std::cout << pkg.get_gensets()[i] << (i + 1 < pkg.get_gensets().size() ? ", " : "");
            }
            std::cout << "\n";
        }
        std::cout << "----------------------------------------------------------------------\n";
    }
}