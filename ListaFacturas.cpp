// Created by Hugo.

#include "ListaFacturas.h"

using namespace std;


ListaFacturas::ListaFacturas() {
    if((header = new NodoFactura) == nullptr) //creando header
    {
        cout << "exception, constructor ListaFacturas" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListaFacturas::ListaFacturas(ListaFacturas &lista) {
    copyAll(lista);
}

ListaFacturas::~ListaFacturas() {
    deleteAll();
    delete(header);
}

bool ListaFacturas::isEmpty() {
    return header->getNext() == header;
}

void ListaFacturas::insertData(NodoFactura *prevNode, Factura &data) {

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar lista Factura" << endl;
    }

    NodoFactura* aux(nullptr);

    aux = new NodoFactura(data);

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

void ListaFacturas::deleteData(NodoFactura *node) {

    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista Facturas" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    //eliminar la lista anidada
    node->getData().getListaProdFactura().deleteAll();

    delete node;
}

void ListaFacturas::deleteAll() {
    NodoFactura* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);

}

bool ListaFacturas::isValidPos(NodoFactura *node) {
    NodoFactura* aux(header->getNext());

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

void ListaFacturas::copyAll(ListaFacturas &lista) {

    NodoFactura* aux(lista.header->getNext());
    NodoFactura* newNode;

    while (aux != lista.header) //**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
    {
        if ((newNode = new NodoFactura(aux->getData())) == nullptr) {
            cout << "excepcion, ListaFacturas copyAll" << endl;
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }

}

NodoFactura *ListaFacturas::getFirstPos() {

    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();

}

NodoFactura *ListaFacturas::getLastPos() {
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoFactura *ListaFacturas::getPrevPos(NodoFactura *node) {
    if(node == header->getNext() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getPrev();
}

NodoFactura *ListaFacturas::getNextPos(NodoFactura *node) {
    if(node == header->getPrev() or !isValidPos(node))
    {
        return nullptr;
    }
    return node->getNext();
}

NodoFactura *ListaFacturas::findData(Factura &data) {
    NodoFactura* aux(header->getNext());

    while( aux != header)
    {
        if(aux->getData() == data)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

Factura &ListaFacturas::retrieve(NodoFactura *node) {
    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de Facturas" << endl;
    }
    return node->getData();
}

std::string ListaFacturas::toString() {

    NodoFactura* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaFacturas &ListaFacturas::operator=(ListaFacturas& Lst) {
    deleteAll();
    copyAll(Lst);
    return *this;
}

void ListaFacturas::write(const std::string &filename = "listaFacturas.bin") {

    char codigoFactura[15];
    char codigoCliente[15];
    char codigoVenta[15];
    char RFC[15];
    float total;
    float IVA;

    int tamno(15);

    ofstream escribir(filename, ios::trunc | ios::binary);
    NodoFactura* aux(header->getNext());

    while (aux != header)
    {
        //dimensiones
        int l1 = size(aux->getData().getCodigoFactura());
        int l2 = size(aux->getData().getCodCliente());
        int l3 = size(aux->getData().getCodVenta());
        int l4 = size(aux->getData().getRFC());

        //convertir a chars
        strncpy(codigoFactura, aux->getData().getCodigoFactura().c_str(), l1);
        strncpy(codigoCliente, aux->getData().getCodCliente().c_str(), l2);
        strncpy(codigoVenta, aux->getData().getCodVenta().c_str(), l3);
        strncpy(RFC, aux->getData().getRFC().c_str(), l4);

        // agregar '\0' al final
        codigoFactura[l1] = '\0';
        codigoCliente[l2] = '\0';
        codigoVenta[l3] = '\0';
        RFC[l4] = '\0';

        // escribir en el disco
        escribir.write((char*)& codigoFactura, tamno);
        escribir.write((char*)& codigoCliente, tamno);
        escribir.write((char*)& codigoVenta, tamno);
        escribir.write((char*)& RFC, tamno);

        total = aux->getData().getTotal();
        IVA = aux->getData().getIVA();

        escribir.write((char*)& total, sizeof(float));
        escribir.write((char*)& IVA, sizeof(float));

        // escribir lista de productos en el disco (otro archivo)
        string filenm("factura");
        filenm += aux->getData().getCodigoFactura();
        filenm += ".txt";
        aux->getData().write(filenm);

        aux = aux->getNext();
    }

    escribir.close();
}

void ListaFacturas::read(const std::string &filename = "listaFacturas.bin") {

    /*
     * factura
     * cliente
     * venta
     * rfc
     * total
     * iva*/

    deleteAll();

    char codigoFactura[15];
    char codigoCliente[15];
    char codigoVenta[15];
    char RFC[15];
    float total;
    float IVA;

    string lastCode("X");

    int tamno(15);

    Factura auxFactura;
    ListProd listaProductosAux;

    ifstream read(filename, ios::in | ios::binary);

    while(!read.eof())
    {
        //leer codigo
        read.read((char*)& codigoFactura, tamno);

        string cod(codigoFactura);

        // validar leectura de nuevo registro
        if (lastCode == cod)
        {
            break;
        }

        //leer resto de variables

        read.read((char*)& codigoCliente, tamno);
        read.read((char*)& codigoVenta, tamno);
        read.read((char*)& RFC, tamno);
        read.read((char*)& total, sizeof(float));
        read.read((char*)& IVA, sizeof(float));

        string filenm("factura");
        filenm += cod;
        filenm += ".txt";

        listaProductosAux.read(filenm);

        //convertir a string
        string codeClienteAux(codigoCliente);
        string codeVentasAux(codigoVenta);
        string RFCAux(RFC);

        // asignar valores

        auxFactura.setCodigoFactura(cod);
        auxFactura.setCodigoCliente(codeClienteAux);
        auxFactura.setCodigoVenta(codeVentasAux);
        auxFactura.setRFC(RFCAux); //no es necesario
        auxFactura.setTotal(total);
        //auxFactura.setIva(); //no es necesario
        auxFactura.setListaProdFactura(listaProductosAux);

        //agregar a la lista
        insertData(getLastPos(), auxFactura);

        lastCode = cod;
    }

    read.close();
}
