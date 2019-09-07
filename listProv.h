// Created by hugo on 23/08/19.

#ifndef ENTREGABLE1_LISTPROV_H
#define ENTREGABLE1_LISTPROV_H

#include <fstream>
#include <stdio.h>
#include "nodoProv.h"
#include "proveedores.h"

class ListaProv{
private:
    NodoProv* header;
    
    void copyAll(ListaProv& lista);

    void swapPtr(NodoProv* node1, NodoProv* node2);

public:
    
    ListaProv();
    ListaProv(ListaProv& original);
    ~ListaProv();
    
    bool isEmpty();
    void insertData(NodoProv* prevNode, Proveedor& prov);
    void deleteData(NodoProv* node);
    void deleteAll();
    bool isValidPos(NodoProv* node);

    NodoProv* getFirstPos();
    NodoProv* getLastPos();
    NodoProv* getPrevPos(NodoProv* node);
    NodoProv* getNextPos(NodoProv* node);
    NodoProv* findData(Proveedor& prov);

    Proveedor& retrieve(NodoProv* node);
    std::string toString();

    ListaProv& operator = (ListaProv&);

    void write(const std::string& filename);
    void read(const std::string& filename);

};

#endif //ENTREGABLE1_LISTPROV_H
