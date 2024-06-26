#include "lib/inicio.hpp"
#include "lib/cadastro.hpp"
#include "lib/login.hpp"
#include "lib/usuario.hpp"

void Inicio::inicio(std::vector<Usuario*>& usuarios, int& idUsuario, std::string senhaAdm, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto) {
    int opcao;

    std::cout << "\nBem-vindo ao marketplace\n";

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\n\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            Cadastro::cadastro(usuarios, idUsuario, senhaAdm, anuncios);
        }
        else if (opcao == 2) {
            Login::login(usuarios, anuncios, idAnuncio, idProduto);
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
}