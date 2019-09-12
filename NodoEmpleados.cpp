// Created by Hugo.

#include "NodoEmpleados.h"

using namespace std;

NodoEmpleados::NodoEmpleados() : next(nullptr), prev(nullptr)
{

}

NodoEmpleados::NodoEmpleados(Empleado &emp)  : next(nullptr), prev(nullptr)
{
    if((dataPtr = new Empleado(emp)) == nullptr)
    {
        cout << "Excepcion, memoria insuficiente, NodoEmpleados constructor" <<endl;
    }
}

NodoEmpleados::~NodoEmpleados() {

    delete dataPtr;

}

void NodoEmpleados::setDataPtr(Empleado *ptr) {
dataPtr = ptr;
}

void NodoEmpleados::setData(Empleado &data) {

    if(dataPtr == nullptr)
    {
        if((dataPtr = new Empleado(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodoEmpleados set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }

}

void NodoEmpleados::setNext(NodoEmpleados *n) {
    next = n;
}

void NodoEmpleados::setPrev(NodoEmpleados *p) {
prev = p;
}

Empleado *NodoEmpleados::getDataPtr() {
    return dataPtr;
}

Empleado &NodoEmpleados::getData() {
    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Orden Compra, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodoEmpleados *NodoEmpleados::getNext() {
    return next;
}

NodoEmpleados *NodoEmpleados::getPrev() {
    return prev;
}
