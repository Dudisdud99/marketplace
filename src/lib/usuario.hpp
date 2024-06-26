#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <vector>

class Anuncio;
class Produto;

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

		bool getBanido();

		//set

		void setNome(std::string nome);

		void setEmail(std::string email);

		void setSenha(std::string senha);

		void setId(int id);

		void setAdm(bool adm);

		void setBanido(bool banido);

		//funcoes

		void inicioUsuario(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto);

		void comunidade(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void verAnuncio(std::vector<Anuncio*>& anuncios, std::vector<Usuario*>& usuarios);

		void opcoesComunidadeAnuncio(std::vector<Anuncio*>& anuncios, int id, std::vector<Usuario*>& usuarios);

		void comentar(std::vector<Anuncio*>& anuncios, int id);

		void avaliar(std::vector<Anuncio*>& anuncios, int id);

		void denunciar(std::vector<Anuncio*>& anuncios, int id);

		void comprar(std::vector<Anuncio*>& anuncios, int id, std::vector<Usuario*>& usuarios);

		void minhaConta(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio, int& idProduto);

		void meusDados(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void meusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void opcoesMeusAnuncios(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void criarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios, int& idAnuncio);

		void editarAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void excluirAnuncio(std::vector<Usuario*>& usuarios, std::vector<Anuncio*>& anuncios);

		void meusProdutos(std::vector<Usuario*>& usuarios);

		void opcoesMeusProdutos(std::vector<Usuario*>& usuarios, int& idProduto);

		void criarProduto(std::vector<Usuario*>& usuarios, int& idProduto);

		void editarProduto(std::vector<Usuario*>& usuarios);

		void excluirProduto(std::vector<Usuario*>& usuarios);

		std::vector<Produto*> produtos;

	private:

		std::string nome;
		std::string email;
		std::string senha;
		int id;
		bool adm;
		bool banido;
};

#endif