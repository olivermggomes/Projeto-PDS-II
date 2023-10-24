#include <iostream>
#include <string>
#include "Avaliacao.cpp"
#include <unordered_map>

class Midia
{

public:

    void AdicionarView()
    {
        this->visualizacoes++;
    }

    std::string Descricao()
    {

        std::string retorno = "Nome: " + nome + "\n Idioma: " + idioma + "\n Genero: " + genero + "\n Data: " + data;

        return retorno;
    }

    void ReceberAvaliacao(Avaliacao recebida)
    {

        if (this->Avaliacoes.find(recebida.ClienteAvaliador.login) != Avaliacoes.end())
        {
            Avaliacoes.emplace(recebida.ClienteAvaliador.login, recebida);
        }
    }

    std::string nome;
    std::string idioma;
    std::string genero;
    std::string data;
    std::string ID;
    int visualizacoes;
    std::unordered_map<std::string, Avaliacao> Avaliacoes;
};

class Serie : public Midia
{

    int NumEpisodios;
};

class Filme : public Midia
{

    int DuracaoMinutos;
};

