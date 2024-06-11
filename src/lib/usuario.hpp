#include <iostream>
#include <vector>

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

	private:

		std::string nome;
		std::string email;
		std::string senha;

		int id;

		bool adm;
};