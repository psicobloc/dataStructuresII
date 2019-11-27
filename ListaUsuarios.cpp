
#include "ListaUsuarios.h"

using namespace std;

ListaUsuarios::ListaUsuarios()
{
    if ((header = new NodoUsuario) == nullptr)
    {
        //throw exeption
    }

    header->setNext(header);
    header->setPrev(header);
}

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
    NodoUsuario* aux(header->getNext());

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
        if (auxNode->getData().getName() == u.getName())
        {
            return auxNode;
        }

        auxNode = auxNode->getNext();
    }

    return nullptr;
}

Usuario &ListaUsuarios::retrieve(NodoUsuario *node)
{

    if (!isValidPos(node))
    {
        cout << "posicion invalida, retrieve, nodo usuario" << endl;

        Usuario user;
        user.setNombre("usuario invalido");
        user.setTipoUsuario("invalido");
        return user; ///chance no funciona porque retornamos una variable que solo existe dentro del scope de esta funcion.

    }
    return node->getData();
}

std::string ListaUsuarios::toString()
{

    NodoUsuario* aux(header->getNext());
    string result;

    while (aux != header)
    {
        result += aux->getData().toString() + "\n\n";
        aux = aux->getNext();
    }

    return result;
}

ListaUsuarios &ListaUsuarios::operator=(ListaUsuarios &lst)
{
    deleteAll();
    copyAll(lst);

    return *this;
}

void ListaUsuarios::read()
{
    deleteAll();

    ifstream leer("listaUsuarios.txt", ios::in);
    string ultimoName;

    char name[50];
    char type[20];
    char password[30];
    int l1,l2,l3;

    Usuario auxUser;

    while (!leer.eof())
    {
        leer.read((char*)& l1, sizeof(int));
        leer.read((char*)& name, l1);
        name[l1] = '\0';
        leer.read((char*)& l2, sizeof(int));
        leer.read((char*)& type, l2);
        type[l2] = '\0';

        string nuevoName(name);

        if (ultimoName == nuevoName)
        {
            break;
        }

        leer.read((char*)& l3, sizeof(int));
        leer.read((char*)& password, l3);
        password[l3] = '\0';

        string passNew(password);
        string typeNew(type);

        auxUser.setNombre(nuevoName);
        auxUser.setTipoUsuario(typeNew);
        auxUser.setPassword(passNew); //todo hacer un set pass sin hashear para asignar el hash leido desde el disco

        insertData(getLastPos(), auxUser);

        ultimoName = nuevoName;
    }

leer.close();
}

void ListaUsuarios::write()
{
    ofstream escribir("listaUsuarios.txt", ios::trunc);
    NodoUsuario* aux(header->getNext());

    char name[50];
    char type[20];
    char password[30];

    while (aux != header)
    {
        int l1 = size(aux->getData().getName());
        int l2 = size(aux->getData().getTipoUsuario());
        int l3 = size(aux->getData().getPassword());

        //convertir a chars
        strncpy(name, aux->getData().getName().c_str(), l1);
        strncpy(type, aux->getData().getTipoUsuario().c_str(), l2);
        strncpy(password, aux->getData().getPassword().c_str(), l3);

        //escribir al disco
        escribir.write((char*)& l1, sizeof(int));
        escribir.write((char*)& name, l1);
        escribir.write((char*)& l2, sizeof(int));
        escribir.write((char*)& type, l2);
        escribir.write((char*)& l3, sizeof(int));
        escribir.write((char*)& password, l3);

        aux = aux->getNext();
    }

escribir.close();
}
