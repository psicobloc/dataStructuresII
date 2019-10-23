// Created by Hugo.

#include "Cliente.h"

using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(Cliente &clnt)
{
codigoCliente = clnt.codigoCliente;
name = clnt.name;
direccion = clnt.direccion;
estado = clnt.estado;
RFC = clnt.RFC;
tipoCliente = clnt.tipoCliente;
}

Cliente::Cliente(string codCliente, string rfcCliente) : codigoCliente(codCliente), RFC(rfcCliente)
{

}

string &Cliente::getName()  {
    return name;
}

void Cliente::setName( string &nameClt) {
    name = nameClt;
}

 string &Cliente::getDireccion()  {
    return direccion;
}

void Cliente::setDireccion( string &direccionClt) {
    direccion = direccionClt;
}

 string &Cliente::getEstado()  {
    return estado;
}

void Cliente::setEstado( string &estadoClt) {
    estado = estadoClt;
}

 string &Cliente::getCodigoCliente()  {
    return codigoCliente;
}

void Cliente::setCodigoCliente( string &codigoClienteClt) {
   codigoCliente = codigoClienteClt;
}

 string &Cliente::getRfc()  {
    return RFC;
}

void Cliente::setRfc( string &rfc) {
    RFC = rfc;
}

 string &Cliente::getTipoCliente()  {
    return tipoCliente;
}

void Cliente::setTipoCliente( string &tipoClienteClt) {
    tipoCliente = tipoClienteClt;
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


bool Cliente::operator==( Cliente &rhs)  {
    return codigoCliente == rhs.codigoCliente;
}

bool Cliente::operator!=( Cliente &rhs)  {
    return codigoCliente != rhs.codigoCliente;
}
