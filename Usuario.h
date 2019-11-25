#ifndef ENTREGABLE1_USUARIO_H
#define ENTREGABLE1_USUARIO_H

#include "MenuVenta.h" //para heredar los includes nadamas
#include "listProd.h"
#include <string.h>
#include <stdio.h>
#include <openssl/sha.h> // sha 256


class Usuario
{
private:

    std::string nombre;
    std::string tipoUsuario; // admin, base, root. solo root puede crear usuarios
    std::string password;

public:

    Usuario();

    void setNombre(std::string name);
    void setTipoUsuario(std::string type);
    void setPassword(std::string pass);

    std::string getName();
    std::string getTipoUsuario();
    std::string getPassword();

    std::string toString();
    std::string hashPass(std::string plainPass);

};

#endif //ENTREGABLE1_USUARIO_H