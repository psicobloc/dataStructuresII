// Created by Hugo.

#include "NodoCliente.h"

using namespace std;

NodoCliente::NodoCliente() : next(nullptr), prev(nullptr), dataPtr(nullptr)
{}

NodoCliente::NodoCliente(Cliente &clnt) : next(nullptr), prev(nullptr)
{
    if ((dataPtr = new Cliente(clnt)) == nullptr)
    {
        cout << "Exepcion, memoria insuficiente, nodoCliente" << endl; // si hay exepcion en realidad no se ejecuta este codigo, no?
    }
}

NodoCliente::~NodoCliente()
{
    delete dataPtr;
}

void NodoCliente::setDataPtr(Cliente* data)
{
    dataPtr = data;
}

void NodoCliente::setNext(NodoCliente* nextNode)
{
    next = nextNode;
}

void NodoCliente::setPrev(NodoCliente* prevNode)
{
    prev = prevNode;
}

void NodoCliente::setData(Cliente &clnt)
{
    if (dataPtr == nullptr)
    {
        if ((dataPtr = new Cliente(clnt)) == nullptr)
        {
            cout << "Exepcion, memoria insuficiente, nodoCliente" << endl;
        }
    }
    else
    {
        *dataPtr = clnt;
    }
}

Cliente& NodoCliente::getData()
{
    if (dataPtr == nullptr)
    {
        cout << "Exepcion, memoria insuficiente, nodoCliente" << endl;
    }
    return *dataPtr;
}

Cliente* NodoCliente::getDataPtr()
{
    return dataPtr;
}

NodoCliente* NodoCliente::getNext()
{
    return next;
}

NodoCliente* NodoCliente::getPrev()
{
    return prev;
}
