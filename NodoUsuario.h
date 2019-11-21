
#ifndef ENTREGABLE1_NODOUSUARIO_H
#define ENTREGABLE1_NODOUSUARIO_H

#include "Usuario.h"

class NodoUsuario
{
private:

    Usuario* dataPtr;
    NodoUsuario* next;
    NodoUsuario* prev;

public:

    NodoUsuario();
    NodoUsuario(Usuario& v);
    ~NodoUsuario();

    void setDataPtr(Usuario* ptr);
    void setData(Usuario& data);
    void setNext(NodoUsuario* n);
    void setPrev(NodoUsuario* p);

    Usuario* getDataPtr();
    Usuario& getData();
    NodoUsuario* getNext();
    NodoUsuario* getPrev();

};

#endif //ENTREGABLE1_NODOUSUARIO_H
