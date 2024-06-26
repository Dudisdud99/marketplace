#include "lib/login.hpp"
#include "lib/usuario.hpp"
#include "lib/adm.hpp"
#include "lib/anuncio.hpp"

#include <iostream>
#include <vector>

void Login::login(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto) {
    std::string login, senha;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> login;

        std::cout << "Digite a senha: ";
        std::cin >> senha;

        bool achouUsuario = false;
        bool banido = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getNome() == login && usuario->getSenha() == senha) {
                achouUsuario = true;
                if (usuario->getAdm()) {
                    if(usuario->getBanido()) {
						std::cout << "\nUsuario banido\n";
                        banido = true;
						break;
					}
                    else {
                        std::cout << "\nAdiminstrador logado\n";
                        static_cast<Adm*>(usuario)->inicioUsuario(usuarios, anuncios, idAnuncio, idProduto);
                        break;
                    }
                }
                std::cout << "\nUsuario logado\n";
                usuario->inicioUsuario(usuarios, anuncios, idAnuncio, idProduto);
                break;
            }
        }
        if (banido) {
            break;
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