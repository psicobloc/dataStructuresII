
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
        return;
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

void ListaVentas::read() //listaVentas.txt
{
    /*
     * std::string codigoVenta;
     * std::string codigoCliente;
     * std::string codigoEmpleado;
     * ListProd listaProdVenta;
     * float  total;
    */

    char codigoVenta[15];
    char codigoCliente[15];
    char codigoEmpleado[15];
    float tots;
    int tamno(15);
    Venta auxVenta;
    ListProd prodListAux;
    string lastCode("X");
    string filename("listaVentas.txt");

    deleteAll();

    ifstream leer(filename, ios::in);

    while (!leer.eof())
    {
        //leer codigo de venta
        leer.read((char*)& codigoVenta, tamno);

        string cod(codigoVenta);

        if (lastCode == cod)
        {
            break;
        }

        //leer el resto de las variables

        leer.read((char*)& codigoCliente, tamno);
        leer.read((char*)& codigoEmpleado, tamno);
        leer.read((char*)& tots, sizeof(float));

        string filenm("venta");
        filenm += cod;
        filenm += ".txt";

        prodListAux.read(filenm);

        //convertir a string.

        string codeSale(codigoVenta);
        string codeClnt(codigoCliente);
        string codeEmply(codigoEmpleado);

        // asignar valores
        auxVenta.setCodigoVenta(codeSale);
        auxVenta.setCodigoCliente(codeClnt);
        auxVenta.setCodigoEmpleado(codeEmply);
        auxVenta.setTotal(tots);
        auxVenta.setListaProductosVenta(prodListAux);

        //agregar a la lista

        insertData(getLastPos(), auxVenta);

        lastCode = cod;
    }
    leer.close();
}

void ListaVentas::write()
{
    char codigoVenta[15];
    char codigoCliente[15];
    char codigoEmpleado[15];
    float tots;
    int tamno(15);
    string filename("listaVentas.txt");

    ofstream escribir(filename, ios::trunc);
    NodoVenta* aux(header->getNext());

    while (aux != header)
    {
        //dimensiones
        int l1 = size(aux->getData().getCodigoVenta());
        int l2 = size(aux->getData().getCodigoCliente());
        int l3 = size(aux->getData().getCodigoEmpleado());

        //convertir a chars
        strncpy(codigoVenta, aux->getData().getCodigoVenta().c_str(), l1);
        strncpy(codigoCliente, aux->getData().getCodigoCliente().c_str(), l2);
        strncpy(codigoEmpleado, aux->getData().getCodigoEmpleado().c_str(), l3);

        tots = aux->getData().getTotal();

        // agregar '\0' al final
        codigoVenta[l1] = '\0';
        codigoCliente[l2] = '\0';
        codigoEmpleado[l3] = '\0';

        //escribir en el disco
        escribir.write((char*)& codigoVenta, tamno);
        escribir.write((char*)& codigoCliente, tamno);
        escribir.write((char*)& codigoEmpleado, tamno);
        escribir.write((char*)& tots, sizeof(float));

        //escribir su lista de productos
        string filenm("venta");
        filenm += aux->getData().getCodigoVenta();
        filenm += ".txt";
        aux->getData().writeListaProductos(filenm);

        aux = aux->getNext();
    }
    escribir.close();
}
