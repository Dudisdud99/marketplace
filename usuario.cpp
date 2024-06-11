#include "lib/usuario.hpp"

Usuario::Usuario(std::string nome, std::string email, std::string senha, int id, bool adm) {
	this->nome = nome;
	this->email = email;
	this->senha = senha;
	this->id = id;
	this->adm = adm;
}