// Created by Hugo.

#ifndef ENTREGABLE1_MENUCLIENTES_H
#define ENTREGABLE1_MENUCLIENTES_H

#include "Cliente.h"
#include "ListaClientes.h"
#include "NodoCliente.h"
#include "ListaInvertida.h"

class MenuClientes
{
private:
    Cliente clienteRAM;
    ListaClientes ListaClientesRAM;
    ListaInvertida invertidaRAM;

public:
    MenuClientes();

    void setClienteRam(Cliente);
    Cliente getClienteRam();

    void create(); /// escribir index.txt y clientes.txt
    void show();   /// leer index, despues leer clientes
    void update(); /// modificar index y clientes ----.txt
    void deleteC();/// eliminar del index y de clientes ---.txt

    void mainMenu();
    void cargarLista();
    void mostrarLista();

    void mostrarClientesPorEdo(std::string edo);
    void mostrarLlistaInvertida();

};

#endif //ENTREGABLE1_MENUCLIENTES_H