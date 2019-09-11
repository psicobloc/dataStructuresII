
#include "NodoOrdenCompra.h"
using namespace std;

NodoOrdenCompra::NodoOrdenCompra() : next(nullptr), prev(nullptr)
{

}

NodoOrdenCompra::NodoOrdenCompra(OrdenCompra &orden) : next(nullptr), prev(nullptr)
{
    if((dataPtr = new OrdenCompra(orden)) == nullptr)
    {
        cout << "Excepcion, memoria insuficiente, NodoOrdenCompra constructor" <<endl;
    }
}

NodoOrdenCompra::~NodoOrdenCompra() {
delete dataPtr;
}

void NodoOrdenCompra::setDataPtr(OrdenCompra *ptr) {
dataPtr = ptr;
}

void NodoOrdenCompra::setData(OrdenCompra &data) {

    if(dataPtr == nullptr)
    {
        if((dataPtr = new OrdenCompra(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodoOrdenCompra set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }
}

void NodoOrdenCompra::setNext(NodoOrdenCompra *n) {
next = n;

}

void NodoOrdenCompra::setPrev(NodoOrdenCompra *p) {
prev = p;
}

OrdenCompra *NodoOrdenCompra::getDataPtr() {
    return dataPtr;
}

OrdenCompra &NodoOrdenCompra::getData() {

    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Orden Compra, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodoOrdenCompra *NodoOrdenCompra::getNext() {
    return next;
}

NodoOrdenCompra *NodoOrdenCompra::getPrev() {
    return prev;
}
