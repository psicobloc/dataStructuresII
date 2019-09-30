// Created by Hugo.

#include "ListaClientes.h"

using namespace std;

ListaClientes::ListaClientes()
{
    if ((header = new NodoCliente) == nullptr) //creando header
    {
        cout << "exception, constructor ListaClientes" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListaClientes::ListaClientes(ListaClientes &lista)
{
    copyAll(lista);
}

ListaClientes::~ListaClientes()
{
    deleteAll();
    delete header;
}

bool ListaClientes::isEmpty()
{
    return header->getNext() == header;
}

bool ListaClientes::isValidPos(NodoCliente *nodo)
{
    NodoCliente *aux(header->getNext());

    while (aux != header)
    {
        if (aux == nodo)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void ListaClientes::insertData(NodoCliente *prevNode, Cliente &clnt)
{
    NodoCliente *aux(nullptr);
    aux = new NodoCliente(clnt);

    if (prevNode == nullptr)
    {
        prevNode = header;
    }

    cout << "insert data .. " << aux->getData().toString() << endl;

    aux->setPrev(prevNode);
    aux->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(aux);
    prevNode->setNext(aux);
}

void ListaClientes::copyAll(ListaClientes &lst)
{
    NodoCliente *aux(lst.header->getNext());
    NodoCliente *newNode;

    while (aux != lst.header)
    {
        if ((newNode = new NodoCliente(aux->getData())) == nullptr)
        {
            cout << "excepcion, ListaClientes copyAll" << endl;
        }

        newNode->setPrev(header->getPrev()); //** neWnode->setprev()
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

void ListaClientes::deleteData(NodoCliente *nodoEliminar)
{
    nodoEliminar->getPrev()->setNext(nodoEliminar->getNext());
    nodoEliminar->getNext()->setPrev(nodoEliminar->getPrev());
    delete nodoEliminar;
}

void ListaClientes::deleteAll()
{
    NodoCliente *aux(nullptr);

    while (header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);
}

NodoCliente *ListaClientes::getLastPos()
{
    if (isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoCliente *ListaClientes::findData(Cliente &clnt)
{
    NodoCliente *aux(header->getNext());

    while (aux != header)
    {
        if (aux->getData() == clnt)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

Cliente &ListaClientes::retrieve(NodoCliente *nodo)
{
    if (!isValidPos(nodo))
    {
        cout << "Posicion invalida, intentando recuperar de lista de Productos" << endl;
    }
    return nodo->getData();
}

std::string ListaClientes::toString()
{
    NodoCliente* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaClientes &ListaClientes::operator=(ListaClientes &list)
{
    deleteAll();
    copyAll(list);
    return *this;
}
