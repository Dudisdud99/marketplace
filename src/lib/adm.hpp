#ifndef ADM_HPP
#define ADM_HPP

#include <iostream>
#include <vector>

#include "usuario.hpp"

class Adm:public Usuario {
public:

	Adm(std::string nome, std::string email, std::string senha, int id, bool adm);

	~Adm();

	//get

	//funcoes

private:
};

#endif