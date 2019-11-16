// Created by Hugo.

#ifndef ENTREGABLE1_LISTAINVERTIDA_H
#define ENTREGABLE1_LISTAINVERTIDA_H

#include "NodoInv.h"

class ListaInvertida {
private:
    NodoInv* anclaCodigo; //secundaria
    NodoInv* anclaEstado; //primaria

public:
    ListaInvertida();
    ~ListaInvertida();

    bool estadoExist(std::string edo);
    void crearEstado(std::string edo, std::string codigo);
    void crearCliente(std::string edo, std::string codigo); // solo se va aguardar su codigo
    bool isListaEdosEmpty();
    bool isListaClientesEmpty();
    bool isListaClnt_EdoEmpty(std::string edo);

    NodoInv* findEdo(std::string edo);

    void deleteAll();
    NodoInv* getAnclaEstados();
    NodoInv* getAnclaClientes();
    std::string estadosToString();
    std::string clientesToString(std::string edo); //imprimir los municipios por estado

};
#endif //ENTREGABLE1_LISTAINVERTIDA_H
