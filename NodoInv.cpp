// Created by Hugo.

#include "NodoInv.h"

using  namespace std;

NodoInv::NodoInv() : llavePtr(nullptr), primario(nullptr), secundario(nullptr)
{

}

NodoInv::NodoInv(std::string &llave) : primario(nullptr), secundario(nullptr)
{
llavePtr = new string(llave);
}

NodoInv::~NodoInv() {
delete llavePtr;
}

void NodoInv::setLlavePtr(std::string *llave) {
llavePtr = llave;
}

void NodoInv::setLlave(std::string &llave) {

    if (llavePtr == nullptr)
    {
        llavePtr = new string(llave);
    }
    else
    {
        *llavePtr = llave;
    }
}

void NodoInv::setPrimario(NodoInv *nodo) {
primario = nodo;
}

void NodoInv::setSecundario(NodoInv *nodo) {
secundario = nodo;
}

std::string &NodoInv::getLLave() {
    return *llavePtr;
}

std::string *NodoInv::getLlavePtr() {
    return llavePtr;
}

NodoInv *NodoInv::getPrimario() {
    return primario;
}

NodoInv *NodoInv::getSecundario() {
    return secundario;
}
