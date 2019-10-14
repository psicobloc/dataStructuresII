// Created by Hugo.

#ifndef ENTREGABLE1_NODOFACTURA_H
#define ENTREGABLE1_NODOFACTURA_H

#include "Factura.h"

class NodoFactura
{
private:
    Factura* dataPtr;
    NodoFactura* next;
    NodoFactura* prev;

public:
    NodoFactura();
    NodoFactura(Factura& orden);
    ~NodoFactura();

    void setDataPtr(Factura* ptr);
    void setData(Factura& data);
    void setNext(NodoFactura* n);
    void setPrev(NodoFactura* p);

    Factura* getDataPtr();
    Factura& getData();
    NodoFactura* getNext();
    NodoFactura* getPrev();
};


#endif //ENTREGABLE1_NODOFACTURA_H
