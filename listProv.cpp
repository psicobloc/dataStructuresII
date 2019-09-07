// Created by hugo on 24/08/19.
#include "listProv.h"

using namespace std;

void ListaProv::copyAll(ListaProv &lista) {

    NodoProv* aux(lista.header->getNext()); //** cambiar por header ** comment viejo, probar **
    NodoProv* newNode;

    while (aux != lista.header) //**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
    {
        if ((newNode = new NodoProv(aux->getData())) == nullptr) {
            cout << "excepcion, listaProv copyAll" << endl;
        }

        newNode->setPrev(header->getPrev()); //** neWnode->setprev()
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

bool ListaProv::isValidPos(NodoProv *node) {
    NodoProv* aux(header->getNext());

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

void ListaProv::swapPtr(NodoProv *node1, NodoProv *node2) {

    Proveedor* aux(node1->getDataPtr());
    node1->setDataPtr(node2->getDataPtr());
    node2->setDataPtr(aux);
}

ListaProv::ListaProv() {
    if((header = new NodoProv) == nullptr) //creando header
    {
        cout << "exception, constructor ListProv" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListaProv::ListaProv(ListaProv &original) : ListaProv() {
copyAll(original);
}

ListaProv::~ListaProv() {

deleteAll();
delete(header);

}

bool ListaProv::isEmpty() {

    return header->getNext() == header;

}

void ListaProv::insertData(NodoProv *prevNode, Proveedor &prov) {

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar" << endl;
    }

    NodoProv* aux(nullptr);

    aux = new NodoProv(prov);

    if(aux == nullptr) ///al parecer es unreachable code
    {
        cout << "Excepcion creando nodo, insert en lista proveedores" << endl;
    }

    if(prevNode == nullptr)
    {
        prevNode = header;
    }

    //cout << "insert data .. " << aux->getData().toString() << endl;
    aux->setPrev(prevNode);
    aux->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(aux);
    prevNode->setNext(aux);

}

void ListaProv::deleteData(NodoProv *node) {

    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista proveedores" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    ///eliminar la lista anidada, si existe en proveedores (?)
    //node->getData().getCLientList().deleteAll();
    delete node;

}

void ListaProv::deleteAll() {

    NodoProv* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);

}

NodoProv *ListaProv::getFirstPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();
}

NodoProv *ListaProv::getLastPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoProv *ListaProv::getPrevPos(NodoProv *node) {

    if(node == header->getNext() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getPrev();

}

NodoProv *ListaProv::getNextPos(NodoProv *node) {

    if(node == header->getPrev() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getNext();

}

NodoProv* ListaProv::findData(Proveedor &prov) {

    NodoProv* aux(header->getNext());

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

Proveedor &ListaProv::retrieve(NodoProv *node) {

    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de proveedores" << endl;
    }
    return node->getData();
}

std::string ListaProv::toString() {

    NodoProv* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaProv &ListaProv::operator=(ListaProv & Lst) {
    deleteAll();
    copyAll(Lst);
    return *this;
}

void ListaProv::write(const std::string &filename) {

    NodoProv* aux(header->getNext());
    string myStr("");
    ofstream write(filename, ios::trunc); //sobreescribimos la lista.

    while (aux != header)
    {
        myStr += aux->getData().getName();
        myStr += ',';
        myStr += aux->getData().getPhone();
        myStr += ',';
        myStr += aux->getData().getCode();
        myStr += ',';
        myStr += aux->getData().getAddress();
        myStr += ',';
        aux = aux->getNext();
    }

    cout << "se escribira en el disco: " << myStr << endl;
    write << myStr;
    write.close();
}

void ListaProv::read(const std::string &filename) { // todo /// al leer se lee doble

    ifstream read(filename, ios::in);
    Proveedor newProv;
    //deleteAll();

    string name, code,  addrs, phone;

    while (!read.eof())
    {
        getline(read,name,',');
        getline(read,phone,',');
        getline(read,code,',');
        getline(read,addrs,',');

        newProv.setName(name);
        newProv.setPhone(phone);
        newProv.setCode(code);
        newProv.setAddrs(addrs);

        if (read.eof())
        {
            break;
        }

        if (getLastPos()->getData().getCode() == code)
        {
            break;
        }

        insertData(getLastPos(),newProv);
    }

cout << "se leyo del disco la lista: " << endl << toString() << endl;

}

