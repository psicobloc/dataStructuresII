// Created by Hugo.

#include "ListaOrdenCompra.h"
using namespace std;

ListaOrdenCompra::ListaOrdenCompra() {
    if((header = new NodoOrdenCompra) == nullptr) //creando header
    {
        cout << "exception, constructor ListaOrdenCompra" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListaOrdenCompra::ListaOrdenCompra(ListaOrdenCompra &lista) {
copyAll(lista);
}

ListaOrdenCompra::~ListaOrdenCompra() {
deleteAll();
delete(header);
}

bool ListaOrdenCompra::isEmpty() {
    return header->getNext() == header;
}

void ListaOrdenCompra::insertData(NodoOrdenCompra *prevNode, OrdenCompra &pedido) {

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar lista OrdenCompra" << endl;
    }

    NodoOrdenCompra* aux(nullptr);

    aux = new NodoOrdenCompra(pedido);

    if(aux == nullptr) ///al parecer es unreachable code
    {
        cout << "Excepcion creando nodo, insert en lista Productoes" << endl;
    }

    if(prevNode == nullptr)
    {
        prevNode = header;
    }

    cout << "insert data .. " << aux->getData().toString() << endl;

    aux->setPrev(prevNode);
    aux->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(aux);
    prevNode->setNext(aux);
}

void ListaOrdenCompra::deleteData(NodoOrdenCompra *node) {

    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista Orden Compra" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    //eliminar la lista anidada
    node->getData().getListaProdOrdenCompra().deleteAll();

    delete node;
}

void ListaOrdenCompra::deleteAll() {
    NodoOrdenCompra* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);

}

bool ListaOrdenCompra::isValidPos(NodoOrdenCompra *node) {
    NodoOrdenCompra* aux(header->getNext());

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

void ListaOrdenCompra::copyAll(ListaOrdenCompra &lista) {

    NodoOrdenCompra* aux(lista.header->getNext());
    NodoOrdenCompra* newNode;

    while (aux != lista.header) //**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
    {
        if ((newNode = new NodoOrdenCompra(aux->getData())) == nullptr) {
            cout << "excepcion, ListaOrdenCompra copyAll" << endl;
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }

}

NodoOrdenCompra *ListaOrdenCompra::getFirstPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();

}

NodoOrdenCompra *ListaOrdenCompra::getLastPos() {
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoOrdenCompra *ListaOrdenCompra::getPrevPos(NodoOrdenCompra *node) {
    if(node == header->getNext() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getPrev();
}

NodoOrdenCompra *ListaOrdenCompra::getNextPos(NodoOrdenCompra *node) {
    if(node == header->getPrev() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getNext();
}

NodoOrdenCompra *ListaOrdenCompra::findData(OrdenCompra &pedido) {
    NodoOrdenCompra* aux(header->getNext());

    while( aux != header)
    {
        if(aux->getData() == pedido)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

OrdenCompra &ListaOrdenCompra::retrieve(NodoOrdenCompra *node) {
    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de Productos" << endl;
    }
    return node->getData();
}

std::string ListaOrdenCompra::toString() {

    NodoOrdenCompra* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaOrdenCompra &ListaOrdenCompra::operator=(ListaOrdenCompra& Lst) {
    deleteAll();
    copyAll(Lst);
    return *this;
}

void ListaOrdenCompra::write(const std::string &filename = "listaPedidos.txt") {





}

void ListaOrdenCompra::read(const std::string &filename = "listaPedidos.txt") {





}
