// Created by Hugo.

#ifndef ENTREGABLE1_MENUFACTURAS_H
#define ENTREGABLE1_MENUFACTURAS_H

#include "ListaFacturas.h"
#include "listProd.h"
#include "ListaClientes.h"
//#include "ListaInvertida.h"
///ventas

class MenuFacturas
{
private:
ListaFacturas listaRam;
ListProd listaProductos;
//lista de clientes ram?

public:
    MenuFacturas();

    void mainMenu();

    void addFactura();
    void modifyFactura();
    void deleteFactura();
    void searchFactura();
    void showAllFactura();
    void write();
    void read();

};

#endif //ENTREGABLE1_MENUFACTURAS_H