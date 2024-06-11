#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <vector>
#include <iostream>

class Usuario;
class Adm;

namespace Login {
	void login(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif