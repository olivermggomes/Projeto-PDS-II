#include <iostream>
#include <string>
#include <unordered_map>

class Avaliacao {
public:
    Cliente ClienteAvaliador;

    Avaliacao(int Nota, Cliente Avaliador) : nota(Nota), ClienteAvaliador(Avaliador) {
        if (Nota <= NOTA_MAX && Nota >= 0) {
        } else {
            throw std::invalid_argument("A nota fornecida está fora do intervalo válido.");
        }
    }

    virtual std::string ImprimirAval() const{
        std::string retorno = "Nota: " + std::to_string(nota) + "\n Avaliador: " + ClienteAvaliador.login;
        return retorno;
    }

protected:
    int nota;
    const int NOTA_MAX = 5;
};

class AvaliacaoEspecialista : public Avaliacao {
public:
    std::string descricao;

    std::string ImprimirAval() const override {
        std::string retorno = "Nota: " + std::to_string(nota) + "\n Avaliador: " + ClienteAvaliador.login + "\n Descricao: " + descricao;
        return retorno;
    }
};
