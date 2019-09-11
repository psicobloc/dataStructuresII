// Created by hugo on 28/08/19.
#ifndef ENTREGABLE1_LISTPROD_H
#define ENTREGABLE1_LISTPROD_H

#include <fstream>
#include <stdio.h>
#include <iostream>
#include "producto.h"
#include "nodeProd.h"
#include "cstring"

class ListProd {
private:
    NodeProd* header;

    void swapPtr(NodeProd* node1, NodeProd* node2);

public:

    ListProd();
    ListProd(ListProd& original);
    ~ListProd();

    bool isEmpty();
    void insertData(NodeProd* prevNode, Producto& prov);
    void deleteData(NodeProd* node);
    void deleteAll();
    bool isValidPos(NodeProd* node);
    void copyAll(ListProd& lista);

    NodeProd* getFirstPos();
    NodeProd* getLastPos();
    NodeProd* getPrevPos(NodeProd* node);
    NodeProd* getNextPos(NodeProd* node);
    NodeProd* findData(Producto& prov);

    Producto& retrieve(NodeProd* node);
    std::string toString();

    ListProd& operator = (ListProd&);

    void write(const std::string& filename);
    void read(const std::string& filename);

};
#endif //ENTREGABLE1_LISTPROD_H
