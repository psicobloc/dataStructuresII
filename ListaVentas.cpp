
#include "ListaVentas.h"

using namespace std;

ListaVentas::ListaVentas()
{
    if((header = new NodoVenta) == nullptr) //creando header
    {
        cout << "exception, constructor ListaFacturas" << endl;
    }
    header->setPrev(header);
    header->setNext(header);
}

ListaVentas::ListaVentas(ListaVentas &lst)
{
copyAll(lst);
}

ListaVentas::~ListaVentas()
{
deleteAll();
delete header;
}

bool ListaVentas::isEmpty()
{
    return header->getNext() == header;
}

void ListaVentas::insertData(NodoVenta *prevNode, Venta &v)
{
    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar lista Venta" << endl;
    }

    NodoVenta* aux(nullptr);

    aux = new NodoVenta(v);

    if(prevNode == nullptr)
    {
        prevNode = header;
    }

    cout << "insert data Venta .. " << aux->getData().toString() << endl;

    aux->setPrev(prevNode);
    aux->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(aux);
    prevNode->setNext(aux);
}

void ListaVentas::deleteData(NodoVenta *node)
{
    if(!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar , lista Venta" << endl;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    //eliminar la lista anidada
    node->getData().getListaProductosVenta().deleteAll();

    delete node;
}

void ListaVentas::deleteAll()
{
    NodoVenta* aux(nullptr);

    while(header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);
}

bool ListaVentas::isValidPos(NodoVenta *node)
{
    NodoVenta* aux(header->getNext());

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

void ListaVentas::copyAll(ListaVentas &lista)
{
    NodoVenta* aux(lista.header->getNext());
    NodoVenta* newNode;

    while (aux != lista.header) //**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
    {
        if ((newNode = new NodoVenta(aux->getData())) == nullptr) {
            cout << "excepcion, ListaVentas copyAll" << endl;
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

NodoVenta *ListaVentas::getLastPos()
{
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

NodoVenta *ListaVentas::findData(Venta &v)
{
    NodoVenta* aux(header->getNext());

    while( aux != header)
    {
        if(aux->getData() == v)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

Venta &ListaVentas::retrieve(NodoVenta *node)
{
    if(!isValidPos(node))
    {
        cout << "excepcion, posicion invalida, intentando recuperar de lista de Ventas" << endl;
    }
    return node->getData();
}

std::string ListaVentas::toString()
{
    NodoVenta* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }
    return result;
}

ListaVentas &ListaVentas::operator=(ListaVentas &lst)
{
    deleteAll();
    copyAll(lst);
    return *this;
}
