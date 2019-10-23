// Created by Hugo.

#ifndef ENTREGABLE1_NODOCLIENTE_H
#define ENTREGABLE1_NODOCLIENTE_H

#include "Cliente.h"

class NodoCliente {
private:
    Cliente* dataPtr;
    NodoCliente* next;
    NodoCliente* prev;

public:
    NodoCliente();
    NodoCliente(Cliente& clnt);
    ~NodoCliente();

    void setDataPtr(Cliente* data);
    void setData(Cliente& clnt);
    void setNext(NodoCliente* nextNode);
    void setPrev(NodoCliente* prevNode);

    Cliente* getDataPtr();
    Cliente& getData();
    NodoCliente* getNext();
    NodoCliente* getPrev();
};


#endif //ENTREGABLE1_NODOCLIENTE_H
