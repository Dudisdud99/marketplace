#include <iostream>
#include <vector>

class Produto;

class Anuncio {
public:

	Anuncio(int usuarioId, int idAnuncio);

	~Anuncio();

	//get

	int getUsuarioId();

	std::string getTitulo();

	std::string getDescricao();

	std::string getCategoria();

	int getId();

	int getVisualizacoes();

	int getLikes();

	int getDislikes();

	int getDenuncias();

	std::vector<std::string> getComentarios();

	bool getBanido();

	int getProdutoId();

	bool getComprado();

	//set

	void setUsuarioId(int usuarioId);

	void setTitulo(std::string titulo);

	void setDescricao(std::string descricao);

	void setCategoria(std::string categoria);

	void setId(int id);

	void setVisualizacoes(int visualizacoes);

	void setLikes(int likes);

	void setDislikes(int dislikes);

	void setDenuncias(int denuncias);

	void setComentarios(std::string comentario);

	void setBanido(bool banido);

	void setProdutoId(int produtoId);

	void setComprado(bool comprado);

	//funcoes

	void exibirDados(std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);

private:

	std::string titulo;
	std::string descricao;
	std::string categoria;
	int usuarioId;
	int produtoId;
	int id;
	int visualizacoes;
	int likes;
	int dislikes;
	int denuncias;
	std::vector<std::string> comentarios;
	bool banido, comprado;
};