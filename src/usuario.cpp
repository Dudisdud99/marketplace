#include "lib/usuario.hpp"
#include "lib/anuncio.hpp"
#include "lib/produto.hpp"

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

void Usuario::inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto) {

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
			minhaConta(usuarios, anuncios, idAnuncio, idProduto);
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
	std::string nomeProduto;
	int quantidade = 0;
	int contador = 0;

	if (anuncios.size() <= 0) {
		std::cout << "\nNao ha anuncios\n";
		return;
	}

	for (int i = 0; i < anuncios.size(); i++) {
		if(anuncios[i]->getBanido() || anuncios[i]->getComprado()) {
			contador++;
			continue;
		}
		else {
			int idProduto = anuncios[i]->getProdutoId();

			auto it2 = std::find_if(produtos.begin(), produtos.end(), [&idProduto](Produto* produto) {
				return produto->getId() == idProduto;
			});

			if (it2 != produtos.end()) {
				quantidade = (*it2)->getQuantidade();
				nomeProduto = (*it2)->getNome();
			}

			if (quantidade != 0) {
				id = anuncios[i]->getUsuarioId();

				auto it = std::find_if(usuarios.begin(), usuarios.end(), [&id](Usuario* usuario) {
					return usuario->getId() == id;
				});

				if (it != usuarios.end()) {
					dono = (*it)->getNome();
				}
				else {
					std::cout << "\nAnuncio abaixo nao encontrado\n" << std::endl;
				}

				std::cout << "\nTitulo: " << anuncios[i]->getTitulo() << "\n";
				std::cout << "Id: " << anuncios[i]->getId() << "\n";
				std::cout << "Dono: " << dono << "\n";
				std::cout << "Descricao: " << anuncios[i]->getDescricao() << "\n";
				std::cout << "Categoria: " << anuncios[i]->getCategoria() << "\n";
				std::cout << "Visualizacoes: " << anuncios[i]->getVisualizacoes() << "\n";
				std::cout << "Produto: " << nomeProduto << "\n";
			}
			else {
				continue;
			}
		}
	}

	if (contador == anuncios.size()) {
		std::cout << "\nNao ha anuncios\n";
		return;
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
			return;
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
			(*it)->exibirDados(anuncios, produtos);
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
			return;
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
	int idProduto;

	auto it = std::find_if(anuncios.begin(), anuncios.end(), [&idAnuncio](Anuncio* anuncio) {
		return anuncio->getProdutoId() == idAnuncio;
	});

	if (it != anuncios.end()) {
		(*it)->setComprado(true);
		idProduto = (*it)->getProdutoId();
		compras.push_back(*it);
		std::cout << "\nCompra realizada\n" << std::endl;
	}
	else {
		std::cout << "\nAnuncio nao encontrado\n" << std::endl;
	}

	auto it2 = std::find_if(produtos.begin(), produtos.end(), [&idProduto](Produto* produto) {
		return produto->getId() == idProduto;
	});

	if (it2 != produtos.end()) {
		(*it2)->setQuantidade((*it2)->getQuantidade() - 1);
	}
	else {
		std::cout << "\nProduto nao encontrado\n" << std::endl;
	}
}

//minha conta

void Usuario::minhaConta(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto) {
	
	while (true) {

		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Meus dados\n";
		std::cout << "2 - Anuncios\n";
		std::cout << "3 - Produtos\n";
		std::cout << "4 - Carrinho\n";
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
		else if (opcao == 3) {
			meusProdutos(usuarios);
			opcoesMeusProdutos(usuarios, idProduto);
		}
		else if (opcao == 4) {
			minhasCompras(anuncios);
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::minhasCompras(std::vector<Anuncio*>& anuncios) {

	std::cout << "\n---------------------------\n";
	std::cout << "\nMinhas compras:\n";

	if (compras.size() <= 0) {
		std::cout << "\nNao ha anuncios\n";
	}
	else {
		for (int i = 0; i < anuncios.size(); i++) {
			if (anuncios[i]->getComprado() && anuncios[i]->getUsuarioId() == this->id) {
				anuncios[i]->exibirDados(anuncios, produtos);
			}
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

	if (anuncios.size() == 0) {
		std::cout << "\nNao ha anuncios\n";
	}
	else {
		for (int i = 0; i < anuncios.size(); i++) {
			if (anuncios[i]->getUsuarioId() == this->id) {
				anuncios[i]->exibirDados(anuncios, produtos);
			}
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

	int idProduto;

	meusProdutos(usuarios);

	if(produtos.size() == 0){
		std::cout << "\nNao ha produtos\n";
		return;
	}

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "\nQual produto deseja adicionar (id): ";
		std::cin >> idProduto;

		auto it = std::find_if(produtos.begin(), produtos.end(), [&idProduto](Produto* produtos) {
			return produtos->getId() == idProduto;
		});

		if (it != produtos.end()) {
			std::cout << "\nProduto adicionado\n";
			break;
		}
		else {
			std::cout << "\nProduto nao encontrado\n";
		}
	}

	Anuncio* anuncio = new Anuncio(this->id, idAnuncio);
	anuncio->setTitulo(titulo);
	anuncio->setDescricao(descricao);
	anuncio->setCategoria(categoria);
	anuncio->setProdutoId(idProduto);
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

		auto it = std::find_if(anuncios.begin(), anuncios.end(), [&id](Anuncio* anuncio) {
			return anuncio->getId() == id;
			});

		if (it != anuncios.end()) {
		}
		else {
			std::cout << "\nAnuncio nao encontrado\n";
			continue;
		}

		std::cout << "\nTitulo: ";
		std::cin >> titulo;
		std::cout << "Descricao: ";
		std::cin >> descricao;
		std::cout << "Categoria: ";
		std::cin >> categoria;

		int idProduto;

		meusProdutos(usuarios);

		while (true) {

			std::cout << "\n---------------------------\n";
			std::cout << "\nQual produto deseja adicionar: ";
			std::cin >> idProduto;

			auto it = std::find_if(produtos.begin(), produtos.end(), [&idProduto](Produto* produtos) {
				return produtos->getId() == idProduto;
				});

			if (it != produtos.end()) {
				std::cout << "\nProduto adicionado\n";
				break;
			}
			else {
				std::cout << "\nProduto nao encontrado\n";
			}
		}

		anuncios[id]->setTitulo(titulo);
		anuncios[id]->setDescricao(descricao);
		anuncios[id]->setCategoria(categoria);
		anuncios[id]->setProdutoId(idProduto);

		std::cout << "\nAnuncio editado\n";
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

void Usuario::meusProdutos(std::vector<Usuario*>& usuarios) {

	std::cout << "\n---------------------------\n";
	std::cout << "\nMeus produtos:\n";

	if (produtos.size() == 0) {
			std::cout << "\nNao ha produtos\n";
	}
	else{
		for (int i = 0; i < produtos.size(); i++) {
			if (produtos[i]->getQuantidade() > 0) {
				produtos[i]->exibirDados(produtos);
			}
			else {
				std::cout << "\nProduto fora de estoque\n";
			}
		}
	}
}

void Usuario::opcoesMeusProdutos(std::vector<Usuario*>& usuarios, int& idProduto) {

	while (true) {
		int opcao;

		std::cout << "\n---------------------------\n";
		std::cout << "\n1 - Modificar produto\n";
		std::cout << "2 - Adicionar produto\n";
		std::cout << "3 - Remover produto\n";
		std::cout << "0 - Sair\n";
		std::cout << "\nsua opcao: ";

		std::cin >> opcao;

		if (opcao == 1) {
			editarProduto(usuarios);
		}
		else if (opcao == 2) {
			criarProduto(usuarios, idProduto);
		}
		else if (opcao == 3) {
			excluirProduto(usuarios);
		}
		else if (opcao == 0) {
			break;
		}
		else {
			std::cout << "\nOpcao invalida\n";
		}
	}
}

void Usuario::criarProduto(std::vector<Usuario*>& usuarios, int& idProduto) {

	std::string nome;
	std::string descricao;
	std::string categoria;
	float preco;
	int quantidade;

	std::cout << "\n---------------------------\n";
	std::cout << "\nNome: ";
	std::cin >> nome;
	std::cout << "Descricao: ";
	std::cin >> descricao;
	std::cout << "Categoria: ";
	std::cin >> categoria;
	std::cout << "Preco: ";
	std::cin >> preco;
	std::cout << "Quantidade: ";
	std::cin >> quantidade;

	Produto* produto = new Produto(nome, descricao, categoria, idProduto, preco, this->id, quantidade);
	produtos.push_back(produto);

	idProduto++;
}

void Usuario::editarProduto(std::vector<Usuario*>& usuarios) {

	int id;
	std::string nome;
	std::string descricao;
	std::string categoria;
	float preco;
	int quantidade;

	while (true) {

		std::cout << "\n---------------------------\n";
		std::cout << "Digite o id do produto: ";
		std::cin >> id;

		auto it = std::find_if(produtos.begin(), produtos.end(), [&id](Produto* produto) {
			return produto->getId() == id;
		});

		if (it != produtos.end()) {

			std::cout << "\nNome: ";
			std::cin >> nome;
			std::cout << "Descricao: ";
			std::cin >> descricao;
			std::cout << "Categoria: ";
			std::cin >> categoria;
			std::cout << "Preco: ";
			std::cin >> preco;
			std::cout << "Quantidade: ";
			std::cin >> quantidade;

			produtos[id]->setNome(nome);
			produtos[id]->setDescricao(descricao);
			produtos[id]->setCategoria(categoria);
			produtos[id]->setPreco(preco);
			produtos[id]->setQuantidade(quantidade);

			std::cout << "\nProduto editado\n";

			break;
		}
		else {
			std::cout << "\nProduto nao encontrado\n";
			continue;
		}
	}
}

void Usuario::excluirProduto(std::vector<Usuario*>& usuarios) {

	while (true) {

		int id;

		std::cout << "\n---------------------------\n";
		std::cout << "\nId do produto: ";
		std::cin >> id;

		auto it = std::find_if(produtos.begin(), produtos.end(), [&id](Produto* produto) {
			return produto->getId() == id;
		});

		if (it != produtos.end()) {

			delete* it;
			*it = nullptr;
			it = produtos.erase(it);
			std::cout << "\nProduto excluido\n" << std::endl;
			break;
		}
		else {
			std::cout << "\nProduto nao encontrado\n" << std::endl;
		}
	}
}