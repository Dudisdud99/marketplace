#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <vector>
#include <iostream>

class Usuario;
class Anuncio;
class Adm;

namespace Cadastro {
	void cadastro(std::vector<Usuario*>& usuarios, int& idUsuario, std::string senhaAdm, std::vector<Anuncio*>& anuncios);
}

#endif