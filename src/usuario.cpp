#include "lib/usuario.hpp"
#include "lib/anuncio.hpp"

//construtor e destrutor

Usuario::Usuario(std::string nome, std::string email, std::string senha, int id, bool adm) {
	this->nome = nome;
	this->email = email;
	this->senha = senha;
	this->id = id;
	this->adm = adm;
	this->banido = false;
}

Usuario::~Usuario() {

}

//get

std::string Usuario::getNome() {
	return this->nome;
}

std::string Usuario::getEmail() {
	return this->email;
}

std::string Usuario::getSenha() {
	return this->senha;
}

int Usuario::getId() {
	return this->id;
}

bool Usuario::getAdm() {
	return this->adm;
}

bool Usuario::getBanido() {
	return this->banido;
}

//set

void Usuario::setNome(std::string nome) {
	this->nome = nome;
}

void Usuario::setEmail(std::string email) {
	this->email = email;
}

void Usuario::setSenha(std::string senha) {
	this->senha = senha;
}

void Usuario::setId(int id) {
	this->id = id;
}


void Usuario::setAdm(bool adm) {
	this->adm = adm;
}

void Usuario::setBanido(bool banido) {
	this->banido = banido;
}

//inicio

void Usuario::inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {

	int opcao;

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Comunidadde\n";
		std::cout << "2 - Minha conta\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			comunidade(usuarios,anuncios);
		}
		else if (opcao == 2) {
			minhaConta(usuarios, anuncios, idAnuncio);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

//comunidade

void Usuario::comunidade(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	std::cout << "\n---------------------------\n";
	std::cout << "\nAnuncios da comunidade\n";

	int id;
	std::string dono;

	for (int i = 0; i < anuncios.size(); i++) {

		if(anuncios[i]->getBanido()){
			continue;
		}
		else {
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
			verAnuncio(anuncios, usuarios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::verAnuncio(std::vector<Anuncio*>& anuncios, std::vector<Usuario*>& usuarios) {

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
			opcoesComunidadeAnuncio(anuncios, id, usuarios);
			break;
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n" << std::endl;
		}
	}

}

void Usuario::opcoesComunidadeAnuncio(std::vector<Anuncio*>& anuncios, int id, std::vector<Usuario*>& usuarios) {

	while (true) {

		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Comentar\n";
		std::cout << "2 - Avaliar\n";
		std::cout << "3 - Denunciar\n";
		std::cout << "4 - Comprar\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			comentar(anuncios, id);
		}
		else if (opcao == 2) {
			avaliar(anuncios, id);
		}
		else if (opcao == 3) {
			denunciar(anuncios, id);
		}
		else if (opcao == 4) {
			comprar(anuncios, id, usuarios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::comentar(std::vector<Anuncio*>& anuncios, int id) {

	std::string comentario;

	std::cout << "\n---------------------------\n";
	std::cout << "\nDigite seu comentario: ";
	std::cin >> comentario;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
		return anuncio->getId() == id;
	});

	if (it != anuncios.end()) {
		(*it)->setComentarios(comentario);
		std::cout << "\nComentario adicionado\n" << std::endl;
	}
	else {
		std::cout << "\nAnuncio nao encontrado\n" << std::endl;
	}
}

void Usuario::avaliar(std::vector<Anuncio*>& anuncios, int id) {

	std::string avaliacao;

	std::cout << "\n---------------------------\n";
	std::cout << "\n1 - Like\n";
	std::cout << "2 - Deslike\n";
	std::cout << "0 - Sair\n";
	std::cout << "\nsua opcao: ";
	std::cin >> avaliacao;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
		return anuncio->getId() == id;
	});

	if (it != anuncios.end()) {
		if (avaliacao == "1") {
			(*it)->setLikes((*it)->getLikes() + 1);
			std::cout << "\nLike adicionado\n" << std::endl;
		}
		else if (avaliacao == "2") {
			(*it)->setDislikes((*it)->getDislikes() + 1);
			std::cout << "\nDeslike adicionado\n" << std::endl;
		}
		else {
			std::cout << "\nOpcao invalida\n" << std::endl;
		}
	}
	else {
		std::cout << "\nAnuncio nao encontrado\n" << std::endl;
	}
}

void Usuario::denunciar(std::vector<Anuncio*>& anuncios, int id) {

	std::string denuncia;

	std::cout << "\n---------------------------\n";
	std::cout << "\nDigite sua denuncia: ";
	std::cin >> denuncia;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
		return anuncio->getId() == id;
	});

	if (it != anuncios.end()) {
		(*it)->setDenuncias((*it)->getDenuncias() + 1);
		std::cout << "\nDenuncia adicionada\n" << std::endl;
	}
	else {
		std::cout << "\nAnuncio nao encontrado\n" << std::endl;
	}
}

void Usuario::comprar(std::vector<Anuncio*>& anuncios, int id, std::vector<Usuario*>& usuarios) {

	int idAnuncio = id;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&idAnuncio](Anuncio* anuncio) {
		return anuncio->getId() == idAnuncio;
	});

	if (it != anuncios.end()) {
		
	}
	else {
		std::cout << "\nAnuncio nao encontrado\n" << std::endl;
	}
}

//minha conta

void Usuario::minhaConta(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {
	
	while (true) {

		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Meus dados\n";
		std::cout << "2 - Anuncios\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 0) {
			break;
		}
		else if (opcao == 1) {
			meusDados(usuarios, anuncios);
		}
		else if (opcao == 2) {
			meusAnuncios(usuarios, anuncios);
			opcoesMeusAnuncios(usuarios, anuncios, idAnuncio);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::meusDados(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	std::cout << "\n---------------------------\n";
	std::cout << "\nNome:" << this->nome << "\n";
	std::cout << "Email: " << this->email << "\n";
	std::cout << "Senha: " << this->senha << "\n";
	std::cout << "Id: " << this->id << "\n";
	std::cout << "Tipo de conta: ";
	if (this->adm) {
		std::cout << "Adiminstrador\n";
	}
	else {
		std::cout << "Usuario\n";
	}
}

void Usuario::meusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	std::cout << "\n---------------------------\n";
	std::cout << "\nMeus anuncios:\n";

	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncios[i]->getUsuarioId() == this->id) {
			anuncios[i]->exibirDados(anuncios);
		}
	}
}

void Usuario::opcoesMeusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {

	while (true) {
		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Modificar anuncio\n";
		std::cout << "2 - Adicionar anuncio\n";
		std::cout << "3 - Remover anuncio\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 1) {
			editarAnuncio(usuarios, anuncios);
		}
		else if (opcao == 2) {
			criarAnuncio(usuarios, anuncios, idAnuncio);
		}
		else if (opcao == 3) {
			excluirAnuncio(usuarios, anuncios);
		}
		else if (opcao == 0) {
			break;
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::criarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio) {

	std::string titulo;
	std::string descricao;
	std::string categoria;

	std::cout << "\n---------------------------\n";
	std::cout << "\nTitulo: ";
	std::cin >> titulo;
	std::cout << "Descricao: ";
	std::cin >> descricao;
	std::cout << "Categoria: ";
	std::cin >> categoria;

	Anuncio* anuncio = new Anuncio(this->id);
	anuncio->setTitulo(titulo);
	anuncio->setDescricao(descricao);
	anuncio->setCategoria(categoria);
	anuncio->setId(idAnuncio);
	anuncios.push_back(anuncio);

	idAnuncio++;
}

void Usuario::editarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	int id;
	std::string titulo;
	std::string descricao;
	std::string categoria;

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\nId do anuncio: ";
		std::cin >> id;
		std::cout << "\nTitulo: ";
		std::cin >> titulo;
		std::cout << "Descricao: ";
		std::cin >> descricao;
		std::cout << "Categoria: ";
		std::cin >> categoria;

		auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
			return anuncio->getId() == id;
		});

		if (it != anuncios.end()) {

			anuncios[id]->setTitulo(titulo);
			anuncios[id]->setDescricao(descricao);
			anuncios[id]->setCategoria(categoria);

			std::cout << "\nAnuncio editado\n";

			break;
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n";
		}
	}
}

void Usuario::excluirAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios) {

	while (true) {

		int id;

		std::cout << "\n---------------------------\n";
		std::cout << "\nId do anuncio: ";
		std::cin >> id;

		auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
			return anuncio->getId() == id;
		});

		if (it != anuncios.end()) {

			delete* it;
			*it = nullptr;
			it = anuncios.erase(it);
			std::cout << "\nAnuncio excluido\n" << std::endl;
			break;
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n" << std::endl;
		}
	}
}