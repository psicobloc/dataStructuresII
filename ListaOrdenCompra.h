// Created by Hugo.


#ifndef ENTREGABLE1_LISTAORDENCOMPRA_H
#define ENTREGABLE1_LISTAORDENCOMPRA_H


#include "NodoOrdenCompra.h"

class ListaOrdenCompra {
private:
    NodoOrdenCompra* header;

public:

    ListaOrdenCompra();
    ListaOrdenCompra(ListaOrdenCompra& lista);
    ~ListaOrdenCompra();

    bool isEmpty();
    void insertData(NodoOrdenCompra* prevNode, OrdenCompra& pedido);
    void deleteData(NodoOrdenCompra* node);
    void deleteAll();
    bool isValidPos(NodoOrdenCompra* node);
    void copyAll(ListaOrdenCompra& lista);

    NodoOrdenCompra* getFirstPos();
    NodoOrdenCompra* getLastPos();
    NodoOrdenCompra* getPrevPos(NodoOrdenCompra* node);
    NodoOrdenCompra* getNextPos(NodoOrdenCompra* node);
    NodoOrdenCompra* findData(OrdenCompra& pedido);

    OrdenCompra& retrieve(NodoOrdenCompra* node);
    std::string toString();

    ListaOrdenCompra& operator = (ListaOrdenCompra&);

    void write(const std::string& filename); // se guarda en listaPedidos.txt y cada orden guarda su lista
    void read(const std::string& filename);

};

#endif //ENTREGABLE1_LISTAORDENCOMPRA_H