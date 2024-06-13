#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <vector>
#include <iostream>

class Usuario;
class Anuncio;
class Adm;

namespace Login {
	void login(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);
}

#endif