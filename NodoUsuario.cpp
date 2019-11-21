
#include "NodoUsuario.h"

using namespace std;

NodoUsuario::NodoUsuario() : next(nullptr), prev(nullptr)
{}

NodoUsuario::NodoUsuario(Usuario &u) : next(nullptr), prev(nullptr)
{
    if ((dataPtr = new Usuario(u)) == nullptr)
    {
        cout << "error falta de memoria, nodo usuario" << endl;
    }
}

NodoUsuario::~NodoUsuario()
{
delete dataPtr;
}

void NodoUsuario::setDataPtr(Usuario *ptr)
{
dataPtr = ptr;
}

void NodoUsuario::setData(Usuario &data)
{
    if(dataPtr == nullptr)
    {
        if((dataPtr = new Usuario(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodoUsuario set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }
}

void NodoUsuario::setNext(NodoUsuario *n)
{
next = n;
}

void NodoUsuario::setPrev(NodoUsuario *p)
{
prev = p;
}

Usuario *NodoUsuario::getDataPtr()
{
    return dataPtr;
}

Usuario &NodoUsuario::getData()
{
    return *dataPtr;
}

NodoUsuario *NodoUsuario::getNext()
{
    return next;
}

NodoUsuario *NodoUsuario::getPrev()
{
    return prev;
}