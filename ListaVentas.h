#ifndef ENTREGABLE1_LISTAVENTAS_H
#define ENTREGABLE1_LISTAVENTAS_H

#include "NodoVenta.h"

class ListaVentas
{
private:
NodoVenta* header;

public:

    ListaVentas();
    ListaVentas(ListaVentas& lst);
    ~ListaVentas();

    bool isEmpty();
    void insertData(NodoVenta* prevNode, Venta& v);
    void deleteData(NodoVenta* node);
    void deleteAll();
    bool isValidPos(NodoVenta* node);
    void copyAll(ListaVentas& lista);

    NodoVenta* getLastPos();
    NodoVenta* findData(Venta& v);

    Venta& retrieve(NodoVenta* node);
    std::string toString();

    ListaVentas& operator = (ListaVentas& lst);

    ///la listaProductosVenta se guarda desde cada Venta

    //read & write, tal vez en el menuVenta mejor? por la dispersión.
};

#endif //ENTREGABLE1_LISTAVENTAS_H
