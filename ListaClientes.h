// Created by Hugo.

#ifndef ENTREGABLE1_LISTACLIENTES_H
#define ENTREGABLE1_LISTACLIENTES_H

#include "NodoCliente.h"
class ListaClientes
{
private:
    NodoCliente* header;

public:
    ListaClientes();
    ListaClientes(ListaClientes& lista);
    ~ListaClientes();

    bool isEmpty();
    bool isValidPos(NodoCliente* nodo);

    void insertData(NodoCliente* prevNode, Cliente& clnt);
    void copyAll(ListaClientes& lst);
    void deleteData(NodoCliente* nodoEliminar);
    void deleteAll();

    NodoCliente* getLastPos();
    NodoCliente* findData(Cliente& clnt);
    Cliente& retrieve(NodoCliente* nodo);

    std::string toString();

    ListaClientes& operator = (ListaClientes& list);

};
#endif //ENTREGABLE1_LISTACLIENTES_H
