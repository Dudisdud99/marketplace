#ifndef ADM_HPP
#define ADM_HPP

#include <iostream>
#include <vector>

#include "usuario.hpp"

class Anuncio;

class Adm:public Usuario {
	public:

		Adm(std::string nome, std::string email, std::string senha, int id, bool adm);

		~Adm();

		//funcoes

		void inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto);

		void opcoesAdm(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void mostrarAnunciosTodos(std::vector<Anuncio*>& anuncios, std::vector<Usuario*>& usuarios);

		void mostrarAnuncio(std::vector<Anuncio*>& anuncios);

		void mostrarAnunciosOp(std::vector<Anuncio*>& anuncios, int id);

		void mostrarUsuariosTodos(std::vector<Anuncio*>& anuncios,std::vector<Usuario*>& usuarios);

		void mostrarUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void mostrarUsuariosOp(std::vector<Usuario*>& usuarios, int id);

};

#endif