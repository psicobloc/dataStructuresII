// Created by Hugo.

#ifndef ENTREGABLE1_LISTAINVERTIDA_H
#define ENTREGABLE1_LISTAINVERTIDA_H

#include "NodoInv.h"

class ListaInvertida {
private:
    NodoInv* anclaNombre; //secundaria
    NodoInv* anclaEstado; //primaria

public:
    ListaInvertida();
    ~ListaInvertida();

    bool estadoExist(std::string edo);
    void crearEstado(std::string edo);


};


#endif //ENTREGABLE1_LISTAINVERTIDA_H
