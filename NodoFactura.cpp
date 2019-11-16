// Created by Hugo.

#include "NodoFactura.h"

using namespace std;

NodoFactura::NodoFactura() : next(nullptr), prev(nullptr)
{

}

NodoFactura::NodoFactura(Factura &fac) : next(nullptr), prev(nullptr)
{
    if((dataPtr = new Factura(fac)) == nullptr)
    {
        cout << "Excepcion, memoria insuficiente, NodoFactura constructor" <<endl;
    }
}

NodoFactura::~NodoFactura() {
    delete dataPtr;
}

void NodoFactura::setDataPtr(Factura *ptr) {
    dataPtr = ptr;
}

void NodoFactura::setData(Factura &data) {

    if(dataPtr == nullptr)
    {
        if((dataPtr = new Factura(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodoFactura set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }
}

void NodoFactura::setNext(NodoFactura *n) {
    next = n;

}

void NodoFactura::setPrev(NodoFactura *p) {
    prev = p;
}

Factura *NodoFactura::getDataPtr() {
    return dataPtr;
}

Factura &NodoFactura::getData() {

    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Factura, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodoFactura *NodoFactura::getNext() {
    return next;
}

NodoFactura *NodoFactura::getPrev() {
    return prev;
}
