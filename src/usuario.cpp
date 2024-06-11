#include "lib/usuario.hpp"

//construtor e destrutor

Usuario::Usuario(std::string nome, std::string email, std::string senha, int id, bool adm) {
	this->nome = nome;
	this->email = email;
	this->senha = senha;
	this->id = id;
	this->adm = adm;
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

//funcoes
