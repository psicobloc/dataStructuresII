// Created by Hugo.

#include "Cliente.h"

using namespace std;

Cliente::Cliente() {}


const string &Cliente::getName() const {
    return name;
}

void Cliente::setName(const string &name) {
    Cliente::name = name;
}

const string &Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const string &direccion) {
    Cliente::direccion = direccion;
}

const string &Cliente::getEstado() const {
    return estado;
}

void Cliente::setEstado(const string &estado) {
    Cliente::estado = estado;
}

const string &Cliente::getCodigoCliente() const {
    return codigoCliente;
}

void Cliente::setCodigoCliente(const string &codigoCliente) {
    Cliente::codigoCliente = codigoCliente;
}

const string &Cliente::getRfc() const {
    return RFC;
}

void Cliente::setRfc(const string &rfc) {
    RFC = rfc;
}

const string &Cliente::getTipoCliente() const {
    return tipoCliente;
}

void Cliente::setTipoCliente(const string &tipoCliente) {
    Cliente::tipoCliente = tipoCliente;
}


std::string Cliente::toString()
{
    string cliente;

    cliente += "Nombre:\t";
    cliente += name;
    cliente += "  Direccion:\t";
    cliente += direccion;
    cliente += "  Estado:\t";
    cliente += estado;
    cliente += "  Codigo de cliente:\t";
    cliente += codigoCliente;
    cliente += "  RFC:\t";
    cliente += RFC;
    cliente += "  Tipo de cliente\t";
    cliente += tipoCliente;

    return cliente;
}


bool Cliente::operator==(const Cliente &rhs) const {
    return codigoCliente == rhs.codigoCliente;
}

bool Cliente::operator!=(const Cliente &rhs) const {
    return !(rhs == *this);
}
