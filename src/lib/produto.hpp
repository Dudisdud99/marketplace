#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <vector>

class Produto {
	public:

		Produto(std::string nome, std::string descricao, std::string categoria, int id, float preco, int usuarioId, int quantidade);

		~Produto();

		//get

		int getUsuarioId();

		std::string getNome();

		std::string getDescricao();

		std::string getCategoria();

		int getId();

		float getPreco();

		int getQuantidade();

		//set

		void setNome(std::string nome);

		void setDescricao(std::string descricao);

		void setCategoria(std::string categoria);

		void setId(int id);

		void setPreco(float preco);

		void setQuantidade(int quantidade);

		//funcoes

		void exibirDados(std::vector<Produto*>& produtos);

	private:

		std::string nome;
		std::string descricao;
		std::string categoria;
		int id;
		int usuarioId;
		int quantidade;
		float preco;
};

#endif