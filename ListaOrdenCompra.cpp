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

//guardar cada variable de la orden de compra con \0

char codigo[15];
char codigoUsuario[15];
char codigoProv[15];
float total;

int tamno(15);

ofstream escribir(filename, ios::trunc);
NodoOrdenCompra* aux(header->getNext());

while (aux != header)
{
    //dimensiones
    int l1 = size(aux->getData().getCode());
    int l2 = size(aux->getData().getUserCode());
    int l3 = size(aux->getData().getProvCode());

    //convertir a chars
    strncpy(codigo, aux->getData().getCode().c_str(), l1);
    strncpy(codigoUsuario, aux->getData().getUserCode().c_str(), l2);
    strncpy(codigoProv, aux->getData().getProvCode().c_str(), l3);

    // agregar '\0' al final todo checar si es en l1 o l1+1
    codigo[l1] = '\0';
    codigoUsuario[l2] = '\0';
    codigoProv[l3] = '\0';

    // escribir en el disco
    escribir.write((char*)& codigo, tamno);
    escribir.write((char*)& codigoUsuario, tamno);
    escribir.write((char*)& codigoProv, tamno);
    total = aux->getData().getTotalPedido();
    escribir.write((char*)& total, sizeof(float));

    // escribir lista de productos en el disco (otro archivo)
    aux->getData().write(aux->getData().getCode());

    aux = aux->getNext();
}

escribir.close();

}

void ListaOrdenCompra::read(const std::string &filename = "listaPedidos.txt") {

    deleteAll();

    char codigo[15];
    char codigoUsuario[15];
    char codigoProv[15];
    float total;
    string lastCode("X");

    int tamno(15);

    OrdenCompra auxOrden;
    ListProd listaProductosAux;

    ifstream read(filename, ios::in);

    while(!read.eof())
    {
        //leer codigo
        read.read((char*)& codigo, tamno);

        string cod(codigo);

        // validar leectura de nuevo registro
        if (lastCode == cod)
        {
            break;
        }

        //leer resto de variables
        read.read((char*)& codigoUsuario, tamno);
        read.read((char*)& codigoProv, tamno);
        read.read((char*)& total, sizeof(float));
        listaProductosAux.read(cod);

        //convertir a string
        string codeUsuarioAux(codigoUsuario);
        string codeProveedorAux(codigoProv);

        // asignar valores
        auxOrden.setCode(cod);
        auxOrden.setUserCode(codigoUsuario);
        auxOrden.setCodigoProveedor(codigoProv);
        auxOrden.setTotalPedido(total);
        auxOrden.setListaProdOrdenCompra(listaProductosAux);

        //agregar a la lista
        insertData(getLastPos(), auxOrden);

        lastCode = cod;
    }

    read.close();
}
