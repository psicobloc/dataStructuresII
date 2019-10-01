// Created by hugo on 28/08/19.

#include "listProd.h"
#include <string.h>

using namespace std;

void ListProd::copyAll(ListProd &lista) {

    NodeProd* aux(lista.header->getNext()); //** cambiar por header ** comment viejo, probar **
    NodeProd* newNode;

    while (aux != lista.header) //**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
    {
        if ((newNode = new NodeProd(aux->getData())) == nullptr) {
            cout << "excepcion, ListProd copyAll" << endl;
        }

        newNode->setPrev(header->getPrev()); //** neWnode->setprev()
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

bool ListProd::isValidPos(NodeProd *node) {
    NodeProd* aux(header->getNext());

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

void ListProd::swapPtr(NodeProd *node1, NodeProd *node2) {

    Producto* aux(node1->getDataPtr());
    node1->setDataPtr(node2->getDataPtr());
    node2->setDataPtr(aux);
}

ListProd::ListProd() {
    if((header = new NodeProd) == nullptr) //creando header
    {
        cout << "exception, constructor ListProd" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListProd::ListProd(ListProd &original) : ListProd() {
    copyAll(original);
}

ListProd::~ListProd() {

    deleteAll();
    delete(header);

}

bool ListProd::isEmpty() {

    return header->getNext() == header;

}

void ListProd::insertData(NodeProd *prevNode, Producto &prod) {

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar" << endl;
    }

    NodeProd* aux(nullptr);

    aux = new NodeProd(prod);

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

void ListProd::deleteData(NodeProd *node) {

    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista Productos" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    ///eliminar la lista anidada, si existe en Productos (?)
    //node->getData().getCLientList().deleteAll();
    delete node;

}

void ListProd::deleteAll() {

    NodeProd* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);

}

NodeProd *ListProd::getFirstPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();
}

NodeProd *ListProd::getLastPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodeProd *ListProd::getPrevPos(NodeProd *node) {

    if(node == header->getNext() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getPrev();

}

NodeProd *ListProd::getNextPos(NodeProd *node) {

    if(node == header->getPrev() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getNext();

}

NodeProd* ListProd::findData(Producto &prov) {

    NodeProd* aux(header->getNext());

    while( aux != header)
    {
        if(aux->getData() == prov)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;

}

Producto &ListProd::retrieve(NodeProd *node) {

    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de Productos" << endl;
    }
    return node->getData();
}

std::string ListProd::toString() {

    NodeProd* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListProd &ListProd::operator=(ListProd & Lst) {
    deleteAll();
    copyAll(Lst);
    return *this;
}

void ListProd::write(const std::string &filename) { /// name, code, amount, price

    ofstream escribir(filename, ios::trunc);
    NodeProd *aux(header->getNext());

    char name[50];
    char code[15];
    char price[15];
    char amo[15];

    while (aux != header)
    {
        //dimensiones
        int l1 = size(aux->getData().getName());
        int l2 = size(aux->getData().getCode());
        int l3 = size(aux->getData().getAmount());
        int l4 = aux->getData().getPrice().length(); ///para ver si funciona igual que size
        // convertir a chars
        strncpy(name, aux->getData().getName().c_str(), l1);
        strncpy(code, aux->getData().getCode().c_str(), l2);
        strncpy(amo, aux->getData().getAmount().c_str(), l3);
        strncpy(price,aux->getData().getPrice().c_str(), l4);
        // escribir en el disco
        escribir.write((char*)& l1, sizeof(int));
        escribir.write((char*)& name, l1);///asi? o con sizeof(name) ???
        escribir.write((char*)& l2, sizeof(int));
        escribir.write((char*)& code, l2);
        escribir.write((char*)& l3, sizeof(int));
        escribir.write((char*)& amo, l3);
        escribir.write((char*)& l4, sizeof(int));
        escribir.write((char*)& price, l4);

        //escribir.write((char*)& aux->getData().getName().c_str(), l1); *** funcionaria?
        aux = aux->getNext();
    }

    escribir.close();
}

void ListProd::read(const std::string &filename) { // todo /// al leer se lee doble


    deleteAll(); // inicializamos de nuevo la lista

    char name[50];
    char code[15];
    char price[15];
    char amo[15];

    int l1,l2,l3,l4;

    Producto aux;

    ifstream read(filename, ios::in);

    string lastCode("");

    while (!read.eof())
    {
        read.read((char*)& l1, sizeof(int));
        read.read((char*)& name, l1);
        name[l1] ='\0';
        read.read((char*)& l2, sizeof(int));
        read.read((char*)& code, l2);
        code[l2] ='\0';
        string cod(code);

        if (lastCode == cod)
        {
            break;
        }

        read.read((char*)& l3, sizeof(int));
        read.read((char*)& amo, l3);
        amo[l3] ='\0';
        read.read((char*)& l4, sizeof(int));
        read.read((char*)& price, l4);
        price[l4] ='\0';

        string nom(name);

        string amount(amo);
        string prec(price);

        aux.setName(nom);
        aux.setCode(cod);
        aux.setAmount(amount);
        aux.setPrice(prec);

        insertData(getLastPos(),aux);

        lastCode = cod;
    }

    read.close();

}

