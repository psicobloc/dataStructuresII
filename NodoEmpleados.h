// Created by Hugo.

#ifndef ENTREGABLE1_NODOEMPLEADOS_H
#define ENTREGABLE1_NODOEMPLEADOS_H

#include "Empleado.h"

class NodoEmpleados {
private:
    Empleado* dataPtr;
    NodoEmpleados* next;
    NodoEmpleados* prev;

public:
    NodoEmpleados();
    NodoEmpleados(Empleado& emp);
    ~NodoEmpleados();

    void setDataPtr(Empleado* ptr);
    void setData(Empleado& data);
    void setNext(NodoEmpleados* n);
    void setPrev(NodoEmpleados* p);

    Empleado* getDataPtr();
    Empleado& getData();
    NodoEmpleados* getNext();
    NodoEmpleados* getPrev();
};

#endif //ENTREGABLE1_NODOEMPLEADOS_H