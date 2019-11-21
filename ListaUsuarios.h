
#ifndef ENTREGABLE1_LISTAUSUARIOS_H
#define ENTREGABLE1_LISTAUSUARIOS_H

#include "NodoUsuario.h"


class ListaUsuarios
{
private:

    NodoUsuario* header;

public:

    ListaUsuarios();
    ~ListaUsuarios();

    bool isEmpty();
    void insertData(NodoUsuario* prevNode, Usuario& u);
    void deleteData(NodoUsuario* node);
    void deleteAll();
    bool isValidPos(NodoUsuario* node);
    void copyAll(ListaUsuarios& lista);

    NodoUsuario* getLastPos();
    NodoUsuario* findData(Usuario& u);

    Usuario& retrieve(NodoUsuario* node);
    std::string toString();

    ListaUsuarios& operator = (ListaUsuarios& lst);

    void read();
    void write();

};
#endif //ENTREGABLE1_LISTAUSUARIOS_H