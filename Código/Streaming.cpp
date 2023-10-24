#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Cliente.cpp"

class Streaming {
public:
    std::unordered_map<std::string, Cliente> clientesCadastrados;
    ListaMidia midiasCadastradas;

    Streaming() {
        // Construtor da classe Streaming.
    }

    Cliente entrar(const std::string& Login, const std::string& Senha) {
        // Verifica se o cliente existe e retorna o cliente.
        if (clientesCadastrados.count(Login) > 0) {
            Cliente cliente = clientesCadastrados[Login];
            return cliente;
        }
        return Cliente(); // Retorna um Cliente vazio se não encontrado.
    }

    bool Confirmar(const std::string& Senha, const std::string& Login) {
        // Verifica se o usuário inseriu a senha e login corretamente.
        if (entrar(Login, Senha).login == Login) {
            return true;
        }
        return false;
    }

    void cadastrar(const std::string& Login, const std::string& Senha, const std::string& Nome) {
        // Cria um usuário e insere ele na lista de usuários cadastrados.
        if (!Confirmar(Senha, Login)) {
            Cliente novoCliente(Nome, Login, Senha);
            clientesCadastrados[Login] = novoCliente;
        } else {
            throw std::exception();
        }
    }

    // Implemente os outros métodos da classe Streaming.

    std::string Top10Midias() {
        // Analisa quais são as 10 mídias com 100 ou mais visualizações com melhor avaliação.
        return "";
    }

    std::string porcentagemClientes15Aval() {
        // Retorna a porcentagem total de clientes que assistiram pelo menos 15 mídias.
        return "";
    }

    std::string clienteComMaisAvaliacoes() {
        // Retorna o cliente com mais avaliações dentro dos clientes cadastrados.
        return "";
    }

    std::string clienteComMaisMidiasVistas() {
        // Retorna o cliente com mais mídias vistas dentro dos clientes cadastrados.
        return "";
    }

    std::string midiasComMaisViews() {
        // Analisa quais são as 10 mídias com mais visualizações.
        return "";
    }

    std::string midiascomMelhorAvaliacoesPorGenero(const std::string& Genero) {
        // Analisa quais são as 10 mídias com a melhor média de avaliações e que tenham sido vistas pelo menos 100 vezes, separados por gênero.
        return "";
    }

    std::string maisVistasPorGenero(const std::string& Genero) {
        // Analisa quais são as 10 mídias com mais visualizações, separados por gênero.
        return "";
    }
};

int main() {
    // Exemplo de uso da classe Streaming.
    Streaming streaming;
    Cliente cliente = streaming.entrar("usuario123", "senha123");
    if (!cliente.login.empty()) {
        std::cout << "Cliente encontrado: " << cliente.login << std::endl;
    } else {
        std::cout << "Cliente não encontrado." << std::endl;
    }

    return 0;
}
