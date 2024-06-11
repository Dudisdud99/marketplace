#ifndef INICIO_HPP
#define INICIO_HPP

#include <vector>
#include <iostream>

class Usuario;
class Adm;

namespace Inicio {
	void inicio(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif