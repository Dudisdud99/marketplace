#include "lib/cadastro.hpp"
#include "lib/login.hpp"
#include "lib/usuario.hpp"
#include "lib/adm.hpp"

void Cadastro::cadastro(std::vector<Usuario*>& usuarios, int& idUsuario, std::string senhaAdm, std::vector<Anuncio*>& anuncios) {

    std::string nomeUsuario, senha, email, codigo;
    bool adm = false;
    int opcao;

    while (true) {

        std::cout << "\n---------------------------\n";
        std::cout << "\nVoce esta cadastrando um administrador ou usuario (1 - Admin, 2 - Usuario): ";
        std::cin >> opcao;

        if (opcao == 1){

            for (int i = 0; i <= 5; i++) {

                std::cout << "\nDigite o codigo de administrador: ";
                std::cin >> codigo;

                if (codigo == senhaAdm) {
                    adm = true;
                    break;  
                }
                else {
				    std::cout << "\nCodigo invalido\n";
				    continue;
			    }
            }

            if (adm) {
				break;
			}
			else {
				std::cout << "\nNumero de tentativas excedido\n";
				break;
			}
		}
		else if (opcao == 2){
			break;
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
    }

    while (true) {

        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> nomeUsuario;

        bool existeUser = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getNome() == nomeUsuario) {
                existeUser = true;
                break;
            }   
        }

        if (existeUser) {
            std::cout << "\nUsuario ja existe\n";
            continue;
        }
        else {
            break;
        }
    }

    std::cout << "Digite seu email: ";
    std::cin >> email;

    std::cout << "Digite a senha: ";
    std::cin >> senha;

    if (adm) {
		int tipo = 1;
		Adm* adm = new Adm(nomeUsuario, email, senha, idUsuario, tipo);
		usuarios.push_back(adm);
		std::cout << "\nAdministrador cadastrado com sucesso!!!\n";
	}
    else {
        int tipo = 2;
        Usuario* usuario = new Usuario(nomeUsuario, email, senha, idUsuario, tipo);
        usuarios.push_back(usuario);
        std::cout << "\nUsuario cadastrado com sucesso!!!\n";
    }

    idUsuario += 1;
}
