//
// Created by hugo on 23/08/19.
//
#include "nodoProv.h"
using namespace std;

NodoProv::NodoProv() : dataPtr(nullptr), prev(nullptr), next(nullptr)
{

}

NodoProv::NodoProv(Proveedor &P) : next(nullptr), prev(nullptr)
{
    if((dataPtr = new Proveedor(P)) == nullptr)
    {
     cout << "Excepcion, memoria insuficiente, nodeProv" <<endl;
    }
}

NodoProv::~NodoProv() {
delete dataPtr;
}

void NodoProv::setDataPtr(Proveedor* ptr) {
dataPtr = ptr;
}

void NodoProv::setData(Proveedor& data) {

    if(dataPtr == nullptr)
    {
        if((dataPtr = new Proveedor(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData nodeProv" << endl;
        }
    }
    else
        {
        *dataPtr = data;
    }
}

void NodoProv::setNext(NodoProv *n) {
next = n;
}

void NodoProv::setPrev(NodoProv *p) {
prev = p;
}

Proveedor* NodoProv::getDataPtr() {
    return dataPtr;
}

Proveedor& NodoProv::getData() {
    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Prov, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodoProv* NodoProv::getNext() {
    return next;
}

NodoProv* NodoProv::getPrev() {
    return prev;
}
