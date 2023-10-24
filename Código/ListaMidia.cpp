#include <iostream>
#include <unordered_map>
#include <vector>

class ListaMidia {
private:
    std::unordered_map<std::string, Midia> listaDeMidias;

public:
    ListaMidia() {}

    std::string toString() {
        std::string retorno = "";

        for (const auto& entry : listaDeMidias) {
            const Midia& atual = entry.second;
            retorno += "\n Nome: " + atual.nome + " || Identificação: " + atual.ID + "\n";
        }

        return retorno;
    }

    bool isVazia() {
        return listaDeMidias.empty();
    }

    Midia* Buscar(const std::string& ID) {
        if (listaDeMidias.find(ID) != listaDeMidias.end()) {
            return &listaDeMidias[ID];
        }
        return nullptr;
    }

    int tamanhoLista() {
        return listaDeMidias.size();
    }

    std::vector<Midia> Buscar(const std::string& nome, const std::string& idioma, const std::string& genero, const std::string& id) {
        std::vector<Midia> ListaRetorno;

        for (const auto& entry : listaDeMidias) {
            const Midia& analisada = entry.second;
            bool nomeMatch = nome.empty() || analisada.nome.find(nome) != std::string::npos;
            bool idiomaMatch = idioma.empty() || analisada.idioma.find(idioma) != std::string::npos;
            bool generoMatch = genero.empty() || analisada.genero.find(genero) != std::string::npos;
            bool idMatch = id.empty() || analisada.ID == id;

            if (nomeMatch && idiomaMatch && generoMatch && idMatch) {
                ListaRetorno.push_back(analisada);
            }
        }

        return ListaRetorno;
    }

    void AdicionarMidia(const std::string& Id, const Midia& Adicionada) {
        listaDeMidias[Id] = Adicionada;
    }

    void RemoverMidia(const std::string& Id) {
        listaDeMidias.erase(Id);
    }

    bool Contem(const std::string& Id) {
        return listaDeMidias.find(Id) != listaDeMidias.end();
    }

std::string imprimirAvaliacoes(Cliente avaliador) {
    std::string retorno = "";

    for (const auto& entry : listaDeMidias) {
        const Midia& Midia = entry.second;

        auto it = Midia.Avaliacoes.find(avaliador.login);
        if (it != Midia.Avaliacoes.end()) {
            retorno += "\n Mídia: " + Midia.nome + " || Avaliação: " + it->second.ImprimirAval();
        }
    }

    return retorno;
}

};