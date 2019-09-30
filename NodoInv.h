// Created by Hugo.

#ifndef ENTREGABLE1_NODOINV_H
#define ENTREGABLE1_NODOINV_H

#include "Cliente.h"

class NodoInv {
private:
    std::string* llavePtr;
    NodoInv* primario;
    NodoInv* secundario;

public:

    NodoInv();
    NodoInv(std::string& llave);
    ~NodoInv();

    void setLlavePtr(std::string* llave);
    void setLlave(std::string& llave);
    void setPrimario(NodoInv* nodo);
    void setSecundario(NodoInv* nodo);

    std::string& getLLave();
    std::string * getLlavePtr();
    NodoInv* getPriMario();
    NodoInv* getSecundario();

};
#endif //ENTREGABLE1_NODOINV_H
