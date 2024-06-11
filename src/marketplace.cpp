#include <iostream>
#include <vector>

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Adm*> adms;

    std::string senhaAdm = "admin";

    int idUsuario = 0;

    Inicio::inicio(usuarios, adms, idUsuario, senhaAdm);

    /*for (auto it = usuarios.begin(); it != usuarios.end(); ) {
        delete* it;
        *it = nullptr;
        it = usuarios.erase(it);
    }
    usuarios.clear();

    for (auto it = livros.begin(); it != livros.end(); ) {
        delete* it;
        *it = nullptr;
        it = livros.erase(it);
    }
    livros.clear();

    for (auto it = adms.begin(); it != adms.end(); ) {
        delete* it;
        *it = nullptr;
        it = adms.erase(it);
    }
    adms.clear();*/

    return 0;
}