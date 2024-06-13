#include "lib/login.hpp"
#include "lib/usuario.hpp"
#include "lib/adm.hpp"
#include "lib/anuncio.hpp"

#include <iostream>
#include <vector>

void Login::login(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {
    std::string login, senha;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> login;

        std::cout << "Digite a senha: ";
        std::cin >> senha;

        bool achouUsuario = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getNome() == login && usuario->getSenha() == senha) {
                achouUsuario = true;
                if (usuario->getAdm()) {
                    std::cout << "\nAdiminstrador logado\n";
                    usuario->inicioUsuario(usuarios, anuncios, idAnuncio);
                    break;
                }
                std::cout << "\nUsuario logado\n";
                usuario->inicioUsuario(usuarios, anuncios, idAnuncio);
                break;
            }
        }

        if (achouUsuario == false) {
            std::cout << "\nUsuario ou senha invalidos\n";
            continue;
        }
        else {
            break;
        }
    }
}