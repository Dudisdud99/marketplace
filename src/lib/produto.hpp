#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <vector>

class Produto {
	public:

		Produto(std::string nome, std::string descricao, std::string categoria, int id, float preco);

		~Produto();

		//get

		std::string getNome();

		std::string getDescricao();

		std::string getCategoria();

		int getId();

		float getPreco();

		//set

		void setNome(std::string nome);

		void setDescricao(std::string descricao);

		void setCategoria(std::string categoria);

		void setId(int id);

		void setPreco(float preco);

		//funcoes

	private:

		std::string nome;
		std::string descricao;
		std::string categoria;
		int id;
		float preco;
};

#endif