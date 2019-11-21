#ifndef ENTREGABLE1_NODOVENTA_H
#define ENTREGABLE1_NODOVENTA_H

#include "Venta.h"

class NodoVenta
{
private:
    Venta*  dataPtr;
    NodoVenta* next;
    NodoVenta* prev;

public:

    NodoVenta();
    NodoVenta(Venta& v);
    ~NodoVenta();

    void setDataPtr(Venta* ptr);
    void setData(Venta& data);
    void setNext(NodoVenta* n);
    void setPrev(NodoVenta* p);

    Venta* getDataPtr();
    Venta& getData();
    NodoVenta* getNext();
    NodoVenta* getPrev();

};
#endif //ENTREGABLE1_NODOVENTA_H