#include "lib/adm.hpp"
#include "lib/usuario.hpp"

//construtor e destrutor

Adm::Adm(std::string _nome, std::string _email, std::string _senha, int _id, bool _adm) : Usuario(_nome, _email, _senha, _id, _adm) {};

Adm::~Adm() {};

//get

//set

//funcoes
