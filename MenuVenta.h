#ifndef ENTREGABLE1_MENUVENTA_H
#define ENTREGABLE1_MENUVENTA_H

#include "ListaVentas.h"
#include "MenuClientes.h"

class MenuVenta
{
private:

    ListaVentas listaRam;
    ListProd listaProductos;

public:

    MenuVenta();

    void mainMenu();
    void addVenta();
    void modifyVenta();
    void deleteVenta();
    void searchVenta();
    void showAllVenta();
    void write();
    void read();

};

#endif //ENTREGABLE1_MENUVENTA_H
