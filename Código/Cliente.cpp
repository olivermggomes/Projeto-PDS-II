#include <string>
#include "ListaMidia.cpp"
#include "Midia.cpp"

class Cliente {
public:
    std::string nome;
    std::string login;
    std::string senha;
    ListaMidia MidiasAssistidas;
    ListaMidia MidiasFuturas;
    ListaMidia MidiasAvaliadas;
    const int QUANTIDADE_PARA_ESPECIALISTA = 5;

    void init(std::string nome, std::string login, std::string senha) {
        this->login = login;
        this->senha = senha;
        this->nome = nome;
    }

    Cliente(std::string nome, std::string login, std::string senha) {
        init(nome, login, senha);
    }

    bool podeSerEspecialista() {
        return this->MidiasAvaliadas.tamanhoLista() >= QUANTIDADE_PARA_ESPECIALISTA;
    }

    void assistir(Midia& assistida) {
        if (!MidiasAssistidas.Contem(assistida.ID)) {
            assistida.AdicionarView();
            MidiasAssistidas.AdicionarMidia(assistida.ID, assistida);

            if (MidiasFuturas.Contem(assistida.ID)) {
                MidiasFuturas.RemoverMidia(assistida.ID);
            }
        }
    }

    void planejarParaAssistir(Midia& planejada) {
        if (!MidiasFuturas.Contem(planejada.ID))
            MidiasFuturas.AdicionarMidia(planejada.ID, planejada);
    }

    void Avaliar(Midia& MidiaAvaliada, int nota, std::string Descricao) {
        if (!this->MidiasAvaliadas.Contem(MidiaAvaliada.ID)) {
            Avaliacao novaAval(nota, *this);
            MidiaAvaliada.ReceberAvaliacao(novaAval);
            this->MidiasAvaliadas.AdicionarMidia(MidiaAvaliada.ID, MidiaAvaliada);
        }
    }

    std::string imprimirAvaliacoes() {
        return this->MidiasAvaliadas.imprimirAvaliacoes(*this);
    }
};

class ClienteEspecialista : Cliente{
    


};