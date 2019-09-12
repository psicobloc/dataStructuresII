// Created by Hugo.

#ifndef ENTREGABLE1_LISTAEMPLEADOS_H
#define ENTREGABLE1_LISTAEMPLEADOS_H

#include "NodoEmpleados.h"

class ListaEmpleados {
private:
NodoEmpleados* header;

public:
    ListaEmpleados();
    ListaEmpleados(ListaEmpleados& lista);
    ~ListaEmpleados();

    bool isEmpty();
    void insertData(NodoEmpleados* prevNode, Empleado& emp);
    void deleteData(NodoEmpleados* node);
    void deleteAll();
    bool isValidPos(NodoEmpleados* node);
    void copyAll(ListaEmpleados& lista);

    NodoEmpleados* getFirstPos();
    NodoEmpleados* getLastPos();
    NodoEmpleados* getPrevPos(NodoEmpleados* node);
    NodoEmpleados* getNextPos(NodoEmpleados* node);
    NodoEmpleados* findData(Empleado& emp);

    Empleado& retrieve(NodoEmpleados* node);
    std::string toString();

    ListaEmpleados& operator = (ListaEmpleados&);

    void write(const std::string& filename); // se guarda en listaPedidos.txt y cada orden guarda su lista
    void read(const std::string& filename);
};

#endif //ENTREGABLE1_LISTAEMPLEADOS_H