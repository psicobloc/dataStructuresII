// Created by hugo on 28/08/19.
#ifndef ENTREGABLE1_NODEPROD_H
#define ENTREGABLE1_NODEPROD_H

#include "producto.h"

class NodeProd {
private:
    Producto* dataPtr;
    NodeProd* next;
    NodeProd* prev;

public:
    NodeProd();
    NodeProd(Producto&);
    ~NodeProd();

    void setDataPtr(Producto* ptr);
    void setData(Producto& data);
    void setNext(NodeProd* n);
    void setPrev(NodeProd* p);

    Producto* getDataPtr();
    Producto& getData();
    NodeProd* getNext();
    NodeProd* getPrev();
};


#endif //ENTREGABLE1_NODEPROD_H
