// Created by hugo on 23/08/19.
#ifndef ENTREGABLE1_NODOPROV_H
#define ENTREGABLE1_NODOPROV_H

#include "proveedores.h"

class NodoProv{
private:
    Proveedor* dataPtr;
    NodoProv* next;
    NodoProv* prev;

public:
    NodoProv();
    NodoProv(Proveedor&);
    ~NodoProv();

    void setDataPtr(Proveedor* ptr);
    void setData(Proveedor& data);
    void setNext(NodoProv* n);
    void setPrev(NodoProv* p);

    Proveedor* getDataPtr();
    Proveedor& getData();
    NodoProv* getNext();
    NodoProv* getPrev();

//    Proveedor* getDataPtr();
};
#endif //ENTREGABLE1_NODOPROV_H
