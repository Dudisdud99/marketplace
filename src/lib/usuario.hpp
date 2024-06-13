#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <vector>

class Anuncio;

class Usuario {
	public:

		Usuario(std::string nome, std::string email, std::string senha, int id, bool adm);

		~Usuario();

		//get

		std::string getNome();

		std::string getEmail();

		std::string getSenha();

		int getId();

		bool getAdm();

		//set

		void setNome(std::string nome);

		void setEmail(std::string email);

		void setSenha(std::string senha);

		void setId(int id);

		void setAdm(bool adm);

		//funcoes

		void inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void comunidade(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void verAnuncio(std::vector<Anuncio*>& anuncios);

		void opcoesComunidadeAnuncio(std::vector<Anuncio*>& anuncios, int id);

		void comentar(std::vector<Anuncio*>& anuncios, int id);

		void avaliar(std::vector<Anuncio*>& anuncios, int id);

		void denunciar(std::vector<Anuncio*>& anuncios, int id);

		void minhaConta(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void meusDados(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void meusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void opcoesMeusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void criarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void editarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void excluirAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

	private:

		std::string nome;
		std::string email;
		std::string senha;
		int id;
		bool adm;
};

#endif