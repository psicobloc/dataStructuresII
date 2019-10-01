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

    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getDireccion() const;
    void setDireccion(const std::string &direccion);
    const std::string &getEstado() const;
    void setEstado(const std::string &estado);
    const std::string &getCodigoCliente() const;
    void setCodigoCliente(const std::string &codigoCliente);
    const std::string &getRfc() const;
    void setRfc(const std::string &rfc);
    const std::string &getTipoCliente() const;
    void setTipoCliente(const std::string &tipoCliente);

    std::string toString();

    bool operator==(const Cliente &rhs) const;
    bool operator!=(const Cliente &rhs) const;


};


#endif //ENTREGABLE1_CLIENTE_H
