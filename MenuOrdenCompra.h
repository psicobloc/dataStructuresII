// Created by Hugo.

#ifndef ENTREGABLE1_MENUORDENCOMPRA_H
#define ENTREGABLE1_MENUORDENCOMPRA_H

#include "ListaOrdenCompra.h"
#include "listProd.h"
#include "listProv.h"

///codigo de usuario debe ser codigo de empleado, dejar el nombre user code para login solamente

class MenuOrdenCompra {
private:
ListaOrdenCompra listaRam;
ListProd listaProductos;   //Productos.txt
ListaProv listaProvedores; //proveedores.txt



public:

    MenuOrdenCompra();

    void mainMenu();
    void addOrden();
    void modifyOrden();
    void deleteOrden();
    void searchOrden();
    void showAllOrden();
    void write();
    void read();


};
#endif //ENTREGABLE1_MENUORDENCOMPRA_H
