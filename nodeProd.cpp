//
// Created by hugo on 28/08/19.
//

#include "nodeProd.h"

using namespace std;

NodeProd::NodeProd() : next(nullptr), prev(nullptr), dataPtr(nullptr)
{

}

NodeProd::NodeProd(Producto & P) : next(nullptr), prev(nullptr)
{
    if((dataPtr = new Producto(P)) == nullptr)
    {
        cout << "Excepcion, memoria insuficiente, NodeProd constructor" <<endl;
    }

}

NodeProd::~NodeProd() {
delete dataPtr;
}

void NodeProd::setDataPtr(Producto* ptr) {
dataPtr = ptr;
}

void NodeProd::setData(Producto &data) {
    if(dataPtr == nullptr)
    {
        if((dataPtr = new Producto(data)) == nullptr)
        {
            cout << "excepcion, memoria insuficiente, setData NodeProd set data" << endl;
        }
    }
    else
    {
        *dataPtr = data;
    }
}

void NodeProd::setNext(NodeProd *n) {
next = n;
}

void NodeProd::setPrev(NodeProd *p) {
prev = p;
}

Producto *NodeProd::getDataPtr() {
    return dataPtr;
}

Producto &NodeProd::getData() {
    if(dataPtr == nullptr)
    {
        cout << "excepcion, get data, nodo Producto, memoria insuficiente" << endl;
    }
    return *dataPtr;
}

NodeProd* NodeProd::getNext() {
    return next;
}

NodeProd* NodeProd::getPrev() {
    return prev;
}
