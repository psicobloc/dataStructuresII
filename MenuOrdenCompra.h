// Created by Hugo.

#ifndef ENTREGABLE1_MENUORDENCOMPRA_H
#define ENTREGABLE1_MENUORDENCOMPRA_H

#include "ListaOrdenCompra.h"
#include "listProd.h"
#include "listProv.h"


class MenuOrdenCompra {
private:
ListaOrdenCompra listaRam;
ListProd listaProductos;   //Productos.txt
ListaProv listaProvedores; //proveedores.txt

    void addOrden();
    void modifyOrden();
    void deleteOrden();
    void searchOrden();
    void showAllOrden();
    void write();
    void read();

public:

    MenuOrdenCompra();

    void mainMenu();

};
#endif //ENTREGABLE1_MENUORDENCOMPRA_H
