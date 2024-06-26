#include "lib/anuncio.hpp"
#include "lib/produto.hpp"

//construtor e destrutor

Anuncio::Anuncio(int usuarioId, int idAnuncio) {
	this->usuarioId = usuarioId;
	this->visualizacoes = 0;
	this->likes = 0;
	this->dislikes = 0;
	this->denuncias = 0;
	this->banido = false;
	this->id = idAnuncio;
}

Anuncio::~Anuncio() {

}

//get

int Anuncio::getUsuarioId() {
	return this->usuarioId;
}

std::string Anuncio::getTitulo() {
	return this->titulo;
}

std::string Anuncio::getDescricao() {
	return this->descricao;
}

std::string Anuncio::getCategoria() {
	return this->categoria;
}

int Anuncio::getId() {
	return this->id;
}

int Anuncio::getVisualizacoes() {
	return this->visualizacoes;
}

int Anuncio::getLikes() {
	return this->likes;
}

int Anuncio::getDislikes() {
	return this->dislikes;
}

int Anuncio::getDenuncias() {
	return this->denuncias;
}

std::vector<std::string> Anuncio::getComentarios() {
	return this->comentarios;
}

bool Anuncio::getBanido() {
	return this->banido;
}

int Anuncio::getProdutoId() {
	return this->produtoId;
}

//set

void Anuncio::setUsuarioId(int usuarioId) {
	this->usuarioId = usuarioId;
}

void Anuncio::setTitulo(std::string titulo) {
	this->titulo = titulo;
}

void Anuncio::setDescricao(std::string descricao) {
	this->descricao = descricao;
}

void Anuncio::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

void Anuncio::setId(int id) {
	this->id = id;
}

void Anuncio::setVisualizacoes(int visualizacoes) {
	this->visualizacoes = visualizacoes;
}

void Anuncio::setLikes(int likes) {
	this->likes = likes;
}

void Anuncio::setDislikes(int dislikes) {
	this->dislikes = dislikes;
}

void Anuncio::setDenuncias(int denuncias) {
	this->denuncias = denuncias;
}

void Anuncio::setComentarios(std::string comentario) {
	this->comentarios.push_back(comentario);
}

void Anuncio::setBanido(bool banido) {
	this->banido = banido;
}

void Anuncio::setProdutoId(int produtoId) {
	this->produtoId = produtoId;
}

//funcoes

void Anuncio::exibirDados(std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {

	std::cout << "\nTitulo: " << this->getTitulo() << "\n";
	std::cout << "ID: " << this->getId() << "\n";
	std::cout << "Descricao: " << this->getDescricao() << "\n";
	std::cout << "Categoria: " << this->getCategoria() << "\n";
	std::cout << "Visualizacoes: " << this->getVisualizacoes() << "\n";
	std::cout << "Likes: " << this->getLikes() << "\n";
	std::cout << "Dislikes: " << this->getDislikes() << "\n";
	std::cout << "Denuncias: " << this->getDenuncias() << "\n";
	std::cout << "Comentarios: ";
	std::vector<std::string> comentarios = this->getComentarios();
	for (int j = 0; j < comentarios.size(); j++) {
		std::cout << comentarios[j] << "; ";
	}
	std::cout << "\n";
	
	int idProduto = this->produtoId;

	auto it = std::find_if(produtos.begin(), produtos.end(), [&idProduto](Produto* produto) {
		return produto->getId() == idProduto;
	});

	if (it != produtos.end()) {
		std::cout << "Produto: " << (*it)->getNome() << "\n";
	}
}
