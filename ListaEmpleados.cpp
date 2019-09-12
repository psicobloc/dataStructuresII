// Created by Hugo.

#include "ListaEmpleados.h"
using namespace std;

ListaEmpleados::ListaEmpleados() {

    if((header = new NodoEmpleados) == nullptr) //creando header
    {
        cout << "exception, constructor ListaEmpleados" << endl;
    }
    header->setPrev(header);
    header->setNext(header);

}

ListaEmpleados::ListaEmpleados(ListaEmpleados &lista) {
copyAll(lista);
}

ListaEmpleados::~ListaEmpleados() {
deleteAll();
delete(header);
}

bool ListaEmpleados::isEmpty() {
    return header->getNext() == header;
}

void ListaEmpleados::insertData(NodoEmpleados *prevNode, Empleado &emp) {

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "posicion invalida, intentando insertar lista Empleados" << endl;
    }

    NodoEmpleados* aux(nullptr);

    aux = new NodoEmpleados(emp);

    if(aux == nullptr) ///al parecer es unreachable code
    {
        cout << "Excepcion creando nodo, insert en lista Productoes" << endl;
    }

    if(prevNode == nullptr)
    {
        prevNode = header;
    }

    cout << "insert data Empleados.. " << aux->getData().toString() << endl;

    aux->setPrev(prevNode);
    aux->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(aux);
    prevNode->setNext(aux);
}

void ListaEmpleados::deleteData(NodoEmpleados *node) {

    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista Empleados" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());

    delete node;
}

void ListaEmpleados::deleteAll() {

    NodoEmpleados* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);
}

bool ListaEmpleados::isValidPos(NodoEmpleados *node) {

    NodoEmpleados* aux(header->getNext());

    while(aux != header)
    {
        if(aux == node)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void ListaEmpleados::copyAll(ListaEmpleados &lista) {

    NodoEmpleados* aux(lista.header->getNext());
    NodoEmpleados* newNode;

    while (aux != lista.header)
    {
        if ((newNode = new NodoEmpleados(aux->getData())) == nullptr) {
            cout << "excepcion, ListaEmpleados copyAll" << endl;
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }

}

NodoEmpleados *ListaEmpleados::getFirstPos() {
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();
}

NodoEmpleados *ListaEmpleados::getLastPos() {
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoEmpleados *ListaEmpleados::getPrevPos(NodoEmpleados *node) {
    if(node == header->getNext() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getPrev();
}

NodoEmpleados *ListaEmpleados::getNextPos(NodoEmpleados *node) {
    if(node == header->getPrev() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getNext();
}

NodoEmpleados *ListaEmpleados::findData(Empleado &emp) {
    NodoEmpleados* aux(header->getNext());

    while( aux != header)
    {
        if(aux->getData() == emp)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

Empleado &ListaEmpleados::retrieve(NodoEmpleados *node) {
    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de Productos" << endl;
    }
    return node->getData();
}

std::string ListaEmpleados::toString() {
    NodoEmpleados* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaEmpleados &ListaEmpleados::operator=(ListaEmpleados &list) {
    deleteAll();
    copyAll(list);
    return *this;
}

void ListaEmpleados::write(const std::string &filename) {

}

void ListaEmpleados::read(const std::string &filename) {

}
