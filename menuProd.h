// Created by hugo on 28/08/19.
#ifndef ENTREGABLE1_MENUPROD_H
#define ENTREGABLE1_MENUPROD_H

#include "listProd.h"

class MenuProd {

private:
    ListProd listaRAM;

    void addProd();
    void modifyProd();
    void deleteProd();
    void searchProd();
    void showAllProd();
    void write();
    void read();

public:

    MenuProd();
    void mainMenu();

};

#endif //ENTREGABLE1_MENUPROD_H
