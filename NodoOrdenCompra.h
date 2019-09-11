#ifndef ENTREGABLE1_NODOORDENCOMPRA_H
#define ENTREGABLE1_NODOORDENCOMPRA_H

#include "OrdenCompra.h"

class NodoOrdenCompra {
private:
    OrdenCompra* dataPtr;
    NodoOrdenCompra* next;
    NodoOrdenCompra* prev;

public:
    NodoOrdenCompra();
    NodoOrdenCompra(OrdenCompra& orden);
    ~NodoOrdenCompra();

    void setDataPtr(OrdenCompra* ptr);
    void setData(OrdenCompra& data);
    void setNext(NodoOrdenCompra* n);
    void setPrev(NodoOrdenCompra* p);

    OrdenCompra* getDataPtr();
    OrdenCompra& getData();
    NodoOrdenCompra* getNext();
    NodoOrdenCompra* getPrev();

};
#endif //ENTREGABLE1_NODOORDENCOMPRA_H