#include <iostream>
#include <vector>

#include "lib/usuario.hpp"
#include "lib/inicio.hpp"
#include "lib/anuncio.hpp"
#include "lib/produto.hpp"

int main() {

    std::vector<Usuario*> usuarios;
    std::vector<Anuncio*> anuncios;

    std::string senhaAdm = "admin";

    int idUsuario = 0;
    int idAnuncio = 0;
    int idProduto = 0;

    Inicio::inicio(usuarios, idUsuario, senhaAdm, anuncios, idAnuncio, idProduto);

    for (auto it = usuarios.begin(); it != usuarios.end(); ) {
        delete* it;
        *it = nullptr;
        it = usuarios.erase(it);
    }
    usuarios.clear();

    for (auto it = anuncios.begin(); it != anuncios.end(); ) {
        delete* it;
        *it = nullptr;
        it = anuncios.erase(it);
    }
    usuarios.clear();

    return 0;
}