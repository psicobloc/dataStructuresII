
#include "ListaUsuarios.h"

using namespace std;

ListaUsuarios::ListaUsuarios() : header(nullptr)
{}

ListaUsuarios::~ListaUsuarios()
{
    deleteAll();
delete header;
}

bool ListaUsuarios::isEmpty()
{
    return header->getNext() == header;
}

void ListaUsuarios::insertData(NodoUsuario *prevNode, Usuario &u)
{

    if(prevNode != nullptr and !isValidPos(prevNode))
    {
        cout<< "pocision invalida, intentando insertar lista Usuarios" << endl;
    }

NodoUsuario* newNode;
newNode = new NodoUsuario(u);

    if (prevNode == nullptr)
    {
        prevNode = header;
    }

    cout << "Insertando usuario: " << newNode->getData().getName() << endl;

    newNode->setPrev(prevNode);
    newNode->setNext(prevNode->getNext());
    prevNode->getNext()->setPrev(newNode);
    prevNode->setNext(newNode);
}

void ListaUsuarios::deleteData(NodoUsuario *node)
{

    if (!isValidPos(node))
    {
        cout << "posicion invalida, intentando eliminar nodo de cliente" << endl;
        return;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());

    delete node;
}

void ListaUsuarios::deleteAll()
{
NodoUsuario* aux(nullptr);

    while (header->getNext() != header)
    {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }

    header->setPrev(header);
    //no eliminamos header, deleteAll != destructor
}

bool ListaUsuarios::isValidPos(NodoUsuario *node)
{
    NodoUsuario* aux(nullptr);

    while (aux != header)
    {
        if (aux == node)
        {
            return true;
        }
        aux = aux->getNext();
    }

    return false;
}

void ListaUsuarios::copyAll(ListaUsuarios &lista)
{

    NodoUsuario* aux(lista.header->getNext());
    NodoUsuario* newNode;

    while (aux != lista.header)
    {
        if ((newNode = new NodoUsuario(aux->getData())) == nullptr) {
            cout << "excepcion, ListaUsuarios copyAll" << endl;
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }

}

NodoUsuario *ListaUsuarios::getLastPos()
{
    if (isEmpty())
    {
        return nullptr;
    }

    return header->getPrev();
}

NodoUsuario *ListaUsuarios::findData(Usuario &u)
{
    NodoUsuario* auxNode(header->getNext());

    while (auxNode != header)
    {
        if (auxNode->getData().getName() == u.getName() and auxNode->getData().getTipoUsuario() == u.getTipoUsuario())
        {
            return auxNode;
        }

        auxNode = auxNode->getNext();
    }

    return nullptr;//**cuando llegue al final, cuando regrese a header, podriamos hacerlo con do_while
}

Usuario &ListaUsuarios::retrieve(NodoUsuario *node)
{

    if (!isValidPos(node))
    {
        cout << "posicion invalida, retrieve, nodo usuario" << endl;

        Usuario user;
        user.setNombre("usuario invalido");
        user.setTipoUsuario("invalido");
        return user;

    }
    return node->getData();
}

std::string ListaUsuarios::toString()
{
    return std::__cxx11::string();
}

ListaUsuarios &ListaUsuarios::operator=(ListaUsuarios &lst)
{
    return <#initializer#>;
}

void ListaUsuarios::read()
{

}

void ListaUsuarios::write()
{

}
