#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <vector>
#include <iostream>

class Usuario;
class Adm;

namespace Cadastro {
	void cadastro(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif