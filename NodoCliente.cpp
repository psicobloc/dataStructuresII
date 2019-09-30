// Created by Hugo.

#include "NodoCliente.h"

using namespace std;

NodoCliente::NodoCliente() : next(nullptr), prev(nullptr), dataPtr(nullptr)
{}

NodoCliente::NodoCliente(Cliente &clnt) : next(nullptr), prev(nullptr)
{
    if ((dataPtr = new Cliente(clnt)) == nullptr)
    {
        cout << "Exepcion, memoria insuficiente, nodoCliente"
             << endl; // si hay exepcion en realidad no se ejecuta este codigo, no?
    }
}

NodoCliente::~NodoCliente()
{
    delete dataPtr;
}

void NodoCliente::setDataPtr(Cliente *dataPtr)
{
    dataPtr = dataPtr;
}

void NodoCliente::setNext(NodoCliente *next)
{
    next = next;
}

void NodoCliente::setPrev(NodoCliente *prev)
{
    prev = prev;
}


void NodoCliente::setData(Cliente &clnt)
{
    if (dataPtr == nullptr)
    {
        if ((dataPtr = new Cliente(clnt)) == nullptr)
        {
            cout << "Exepcion, memoria insuficiente, nodoCliente"
                 << endl;
        }
    }
}

Cliente &NodoCliente::getData()
{
    if (dataPtr == nullptr)
    {
        cout << "Exepcion, memoria insuficiente, nodoCliente"
             << endl;
    }
    return *dataPtr;
}

Cliente *NodoCliente::getDataPtr()
{
    return dataPtr;
}

NodoCliente *NodoCliente::getNext()
{
    return next;
}

NodoCliente *NodoCliente::getPrev()
{
    return prev;
}
