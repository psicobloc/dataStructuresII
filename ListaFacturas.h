// Created by Hugo.

#ifndef ENTREGABLE1_LISTAFACTURAS_H
#define ENTREGABLE1_LISTAFACTURAS_H

#include "NodoFactura.h"

class ListaFacturas
{
private:
    NodoFactura* header;

public:

    ListaFacturas();
    ListaFacturas(ListaFacturas& lista);
    ~ListaFacturas();

    bool isEmpty();
    void insertData(NodoFactura* prevNode, Factura& pedido);
    void deleteData(NodoFactura* node);
    void deleteAll();
    bool isValidPos(NodoFactura* node);
    void copyAll(ListaFacturas& lista);

    NodoFactura* getFirstPos();
    NodoFactura* getLastPos();
    NodoFactura* getPrevPos(NodoFactura* node);
    NodoFactura* getNextPos(NodoFactura* node);
    NodoFactura* findData(Factura& pedido);

    Factura& retrieve(NodoFactura* node);
    std::string toString();

    ListaFacturas& operator = (ListaFacturas&);

    void write(const std::string& filename); // se guarda en listaPedidos.txt y cada orden guarda su lista
    void read(const std::string& filename);
};

#endif //ENTREGABLE1_LISTAFACTURAS_H
