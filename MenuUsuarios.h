// Created by hugo 

#ifndef ENTREGABLE1_MENUUSUARIOS_H
#define ENTREGABLE1_MENUUSUARIOS_H

#include "ListaUsuarios.h"

class MenuUsuarios /// no se permitirá la modificación de usuarios
{
private:
    ListaUsuarios listaRam;

public:
    MenuUsuarios();

    void addUser();
    void deleteUser();
    void write();
    void read();
    void showAllUsers();
    std::string findUser(std::string name, std::string pass);

    void mainMenu();
};

#endif //ENTREGABLE1_MENUUSUARIOS_H
