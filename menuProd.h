// Created by hugo on 28/08/19.
#ifndef ENTREGABLE1_MENUPROD_H
#define ENTREGABLE1_MENUPROD_H

#include "listProd.h"

class MenuProd {

private:
    ListProd listaRAM;



public:

    MenuProd();
    void mainMenu();
    void setList(ListProd& lista);
    void modifyProd();
    void showAllProd();
    void searchProd();
    void read();
    void addProd();

    void deleteProd();


    void write();


};

#endif //ENTREGABLE1_MENUPROD_H
