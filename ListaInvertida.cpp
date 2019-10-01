// Created by Hugo.

#include "ListaInvertida.h"

using namespace std;

ListaInvertida::ListaInvertida() : anclaEstado(nullptr), anclaCodigo(nullptr)
{}

ListaInvertida::~ListaInvertida() {
deleteAll();
delete anclaCodigo;
delete anclaEstado;
}

bool ListaInvertida::estadoExist(std::string edo)
{
    NodoInv* aux(anclaEstado);

    while(aux!= nullptr)
    {
        if(aux->getLLave() == edo)
        {
            return true;
        }
        aux = aux->getPrimario();
    }
    return false;
}

void ListaInvertida::crearEstado(std::string edo, std::string codigo)
{
    //system("cls");

    string nomEdo("");
    NodoInv* auxEdo(anclaEstado);
    NodoInv* nuevoNodo(nullptr);

    if(!estadoExist(edo))
    {
        nuevoNodo = new NodoInv(edo);

        if(anclaEstado == nullptr)
        {
            anclaEstado = nuevoNodo;
            return;
        }
        else
        {
            while(auxEdo->getPrimario() != nullptr)
            {
                auxEdo = auxEdo->getPrimario();
            }
            auxEdo->setPrimario(nuevoNodo);
        }
    }
    crearCliente(edo,codigo);
}

void ListaInvertida::crearCliente(std::string edo, std::string codigo)
{
    NodoInv* auxEdo(anclaEstado);
    NodoInv* auxCod(anclaCodigo);
    NodoInv* nuevoCliente(nullptr);

    while(auxEdo->getLLave() != edo)
    {
        auxEdo = auxEdo->getPrimario();
    }

    nuevoCliente = new NodoInv(codigo);

    if(anclaCodigo == nullptr)
    {
        anclaCodigo = nuevoCliente;
    }
    else
    {
        while(auxCod->getPrimario() != nullptr)
        {
            auxCod = auxCod->getPrimario();
        }
        auxCod->setPrimario(nuevoCliente);
    }

    if(auxEdo->getSecundario() == nullptr)
    {
        NodoInv* P(nuevoCliente);
        auxEdo->setSecundario(P);
    }
    else
    {
        NodoInv* recClientes(auxEdo->getSecundario());

        while(recClientes->getSecundario() != nullptr)
        {
            recClientes = recClientes->getSecundario();
        }

        recClientes->setSecundario(nuevoCliente);
    }
}

bool ListaInvertida::isListaEdosEmpty()
{
    return anclaEstado == nullptr;
}

bool ListaInvertida::isListaClientesEmpty()
{
    return anclaCodigo == nullptr;
}

bool ListaInvertida::isListaClnt_EdoEmpty(std::string edo)
{
    NodoInv* auxC(anclaEstado);

    while(auxC != nullptr)
    {
        if(auxC->getLLave() == edo)
        {
            if(auxC->getSecundario() != nullptr)
            {
                return false;
            }
        }
        auxC = auxC->getPrimario();
    }
    return true;
}

NodoInv *ListaInvertida::findEdo(std::string edo)
{
    NodoInv* auxC(anclaEstado);

    while(auxC != nullptr)
    {
        if(auxC->getLLave() == edo)
        {
            return auxC;
        }
        auxC = auxC->getPrimario();
    }
    return nullptr;
}

void ListaInvertida::deleteAll()
{
    NodoInv* auxEdo(anclaEstado);
    NodoInv* auxCod(anclaCodigo);

    while(!isListaClientesEmpty())
    {
        auxCod = anclaCodigo;
        anclaCodigo = anclaCodigo->getPrimario();
        delete auxCod;
    }

    while(!isListaEdosEmpty())
    {
        auxEdo = anclaEstado;
        anclaEstado = anclaEstado->getPrimario();
        delete auxEdo;
    }
}

NodoInv *ListaInvertida::getAnclaEstados()
{
    return anclaEstado;
}

NodoInv *ListaInvertida::getAnclaClientes()
{
    return anclaCodigo;
}

std::string ListaInvertida::estadosToString()
{
    NodoInv* auxC(anclaEstado);
    string myStr("Lista de Estados:\n");

    while(auxC != nullptr)
    {
        myStr += auxC->getLLave();
        myStr += "\t";
        auxC = auxC->getPrimario();
    }
    return myStr;
}

std::string ListaInvertida::clientesToString(std::string edo) // va aimprimir los codigos
{
    NodoInv* auxEdo(findEdo(edo));
    NodoInv* auxNom(auxEdo->getSecundario());
    string myStr(edo);

    myStr += "\n";

    while(auxNom != nullptr)
    {
        myStr += auxNom->getLLave();
        myStr += "\n";
        auxNom = auxNom->getSecundario();
    }
    return myStr;
}
