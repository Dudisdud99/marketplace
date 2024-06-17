#include "lib/adm.hpp"
#include "lib/usuario.hpp"
#include "lib/anuncio.hpp"

//construtor e destrutor

Adm::Adm(std::string _nome, std::string _email, std::string _senha, int _id, bool _adm) : Usuario(_nome, _email, _senha, _id, _adm) {};

Adm::~Adm() {};

//funcoes

void Adm::inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {

	int opcao;

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Comunidadde\n";
		std::cout << "2 - Minha conta\n";
		std::cout << "3 - Opcoes adm\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			comunidade(usuarios, anuncios);
		}
		else if (opcao == 2) {
			minhaConta(usuarios, anuncios, idAnuncio);
		}
		else if (opcao == 3) {
			opcoesAdm(usuarios, anuncios, idAnuncio);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Adm::opcoesAdm(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {

	int opcao;

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Ver usuarios\n";
		std::cout << "2 - Ver anuncios\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			mostrarUsuariosTodos(anuncios, usuarios);
		}
		else if (opcao == 2) {
			mostrarAnunciosTodos(anuncios, usuarios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}

}

void Adm::mostrarUsuariosTodos(std::vector<Anuncio*>& anuncios, std::vector<Usuario*>& usuarios) {
	std::cout << "\n---------------------------\n";

	int id;
	std::string dono;

	for (int i = 0; i < usuarios.size(); i++) {

		std::cout << "\nNome: " << usuarios[i]->getNome() << "\n";
		std::cout << "Email: " << usuarios[i]->getEmail() << "\n";
		std::cout << "ID: " << usuarios[i]->getId() << "\n";
		std::cout << "Adm: " << usuarios[i]->getAdm() << "\n\n";

	}

	while (true) {

		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Visualizar usuario\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			mostrarUsuario(usuarios, anuncios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Adm::mostrarUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	while (true) {

		int id;

		std::cout << "\n---------------------------\n";
		std::cout << "\nId do usuario: ";
		std::cin >> id;

		auto it = std::find_if(usuarios.begin(), usuarios.end(), [&id](Usuario* usuario) {
			return usuario->getId() == id;
		});

		if (it != usuarios.end()) {
			(*it)->meusDados(usuarios, anuncios);
			mostrarUsuariosOp(usuarios, id);
			break;
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n" << std::endl;
		}
	}

}

void Adm ::mostrarUsuariosOp(std::vector<Usuario*>& usuarios, int id) {

	int idUsuario = id;

	int opcao;

	auto it = std::find_if(usuarios.begin(), usuarios.end(), [&idUsuario](Usuario* usuario) {
		return usuario->getId() == idUsuario;
	});

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Banir usuario\n";
		std::cout << "2 - Desbanir usuario\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			(*it)->setBanido(true);
			std::cout << "\nUsuario banido\n";
		}
		else if (opcao == 2) {
			(*it)->setBanido(false);
			std::cout << "\nUsuario desbanido\n";
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Adm::mostrarAnunciosTodos(std::vector<Anuncio*>& anuncios, std::vector<Usuario*> &usuarios) {
	std::cout << "\n---------------------------\n";

	int id;
	std::string dono;

	for (int i = 0; i < anuncios.size(); i++) {

		id = anuncios[i]->getUsuarioId();

		auto it = std::find_if(usuarios.begin(), usuarios.end(), [&id](Usuario* usuario) {
			return usuario->getId() == id;
			});

		if (it != usuarios.end()) {
			dono = (*it)->getNome();
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n" << std::endl;
		}

		std::cout << "\nTitulo: " << anuncios[i]->getTitulo() << "\n";
		std::cout << "Id: " << anuncios[i]->getId() << "\n";
		std::cout << "Dono: " << dono << "\n";
		std::cout << "Descricao: " << anuncios[i]->getDescricao() << "\n";
		std::cout << "Categoria: " << anuncios[i]->getCategoria() << "\n";
		std::cout << "Visualizacoes: " << anuncios[i]->getVisualizacoes() << "\n";
	}

	while (true) {

		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Visualizar anuncio\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			mostrarAnuncio(anuncios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Adm::mostrarAnuncio(std::vector<Anuncio*>& anuncios) {

	while (true) {

		int id;

		std::cout << "\n---------------------------\n";
		std::cout << "\nId do anuncio: ";
		std::cin >> id;

		auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
			return anuncio->getId() == id;
			});

		if (it != anuncios.end()) {
			(*it)->setVisualizacoes((*it)->getVisualizacoes() + 1);
			(*it)->exibirDados(anuncios);
			mostrarAnunciosOp(anuncios, id);
			break;
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n" << std::endl;
		}
	}

}

void Adm::mostrarAnunciosOp(std::vector<Anuncio*>& anuncios, int id) {

	int idAnuncio = id;

	int opcao;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&idAnuncio](Anuncio* anuncio) {
		return anuncio->getId() == idAnuncio;
	});

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Banir anuncio\n";
		std::cout << "2 - Desbanir anuncio\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			(*it)->setBanido(true);
			std::cout << "\nAnuncio banido\n";
		}
		else if (opcao == 2) {
			(*it)->setBanido(false);
			std::cout << "\nAnuncio desbanido\n";
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}
