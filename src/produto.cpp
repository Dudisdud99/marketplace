#include "lib/produto.hpp"

Produto::Produto(std::string nome, std::string descricao, std::string categoria, int id, float preco, int usuarioId) {
	this->nome = nome;
	this->descricao = descricao;
	this->categoria = categoria;
	this->id = id;
	this->preco = preco;
	this->usuarioId = usuarioId;
}

Produto::~Produto() {}

//get

int Produto::getUsuarioId() {
	return this->usuarioId;
}

std::string Produto::getNome() {
	return this->nome;
}

std::string Produto::getDescricao() {
	return this->descricao;
}

std::string Produto::getCategoria() {
	return this->categoria;
}

int Produto::getId() {
	return this->id;
}

float Produto::getPreco() {
	return this->preco;
}

//set

void Produto::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

void Produto::setDescricao(std::string descricao) {
	this->descricao = descricao;
}

void Produto::setId(int id) {
	this->id = id;
}

void Produto::setNome(std::string nome) {
	this->nome = nome;
}

void Produto::setPreco(float preco) {
	this->preco = preco;
}

//funcoes

void Produto::exibirDados(std::vector<Produto*>& produtos) {
	std::cout << "\n---------------------------\n";
	std::cout << "Nome: " << this->nome << "\n";
	std::cout << "Id: " << this->id << "\n";
	std::cout << "Descricao: " << this->descricao << "\n";
	std::cout << "Categoria: " << this->categoria << "\n";
	std::cout << "Preco: " << this->preco << "\n";
	std::cout << "UsuarioId: " << this->usuarioId << "\n";
}