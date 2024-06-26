#ifndef INICIO_HPP
#define INICIO_HPP

#include <vector>
#include <iostream>

class Usuario;
class Anuncio;
class Adm;

namespace Inicio {
	void inicio(std::vector<Usuario*>& usuarios, int& idUsuario, std::string senhaAdm, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto);
}

#endif