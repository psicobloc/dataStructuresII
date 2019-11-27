// Created by hugo on 25/08/19.

#ifndef ENTREGABLE1_MENUPROV_H
#define ENTREGABLE1_MENUPROV_H

#include "listProv.h"

class MenuProv
{
private:
    ListaProv listaRAM;



public:

    MenuProv();
    void mainMenu();
    void addProv();
    void modifyProv();
    void deleteProv();
    void searchProv();
    void showAllProv();
    void write();
    void read();

};

#endif //ENTREGABLE1_MENUPROV_H
