
#include "NodoVenta.h"

using namespace std;

NodoVenta::NodoVenta() : next(nullptr), prev(nullptr)
{}

NodoVenta::NodoVenta(Venta &v) : next(nullptr), prev(nullptr)
{
    if((dataPtr = new Venta(v)) == nullptr)
    {
        cout << "Excepcion, memoria insuficiente, NodoVenta constructor" <<endl;
    }
}

NodoVenta::~NodoVenta() {
    delete dataPtr;
}

void NodoVenta::setDataPtr(Venta *ptr) {
    dataPtr = ptr;
}

void NodoVenta::setData(Venta &data) {

    if(dataPtr == nullptr)
    {
        if((dataPtr = new Venta(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodoVenta set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }
}

void NodoVenta::setNext(NodoVenta *n) {
    next = n;

}

void NodoVenta::setPrev(NodoVenta *p) {
    prev = p;
}

Venta *NodoVenta::getDataPtr() {
    return dataPtr;
}

Venta &NodoVenta::getData() {

    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Venta, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodoVenta *NodoVenta::getNext() {
    return next;
}

NodoVenta *NodoVenta::getPrev() {
    return prev;
}
