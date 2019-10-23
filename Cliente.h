// Created by Hugo.

#ifndef ENTREGABLE1_CLIENTE_H
#define ENTREGABLE1_CLIENTE_H

#include "MenuOrdenCompra.h"
#include <fstream>

class Cliente {
private:
    std::string name;
    std::string direccion; // para listas invertidas
    std::string estado;
    std::string codigoCliente;
    std::string RFC;
    std::string tipoCliente; // para listas invertidas

public:

    Cliente();
    Cliente(Cliente& clnt);
    Cliente(std::string codCliente, std::string rfcCliente);

     std::string &getName() ;
    void setName( std::string &name);
     std::string &getDireccion() ;
    void setDireccion( std::string &direccion);
     std::string &getEstado() ;
    void setEstado( std::string &estado);
     std::string &getCodigoCliente() ;
    void setCodigoCliente( std::string &codigoCliente);
     std::string &getRfc() ;
    void setRfc( std::string &rfc);
     std::string &getTipoCliente() ;
    void setTipoCliente( std::string &tipoCliente);

    std::string toString();

    bool operator==( Cliente &rhs) ;
    bool operator!=( Cliente &rhs) ;


};


#endif //ENTREGABLE1_CLIENTE_H
