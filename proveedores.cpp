// Created by hugo on 23/08/19.

#include "proveedores.h"

Proveedor::Proveedor() {}

Proveedor::Proveedor(Proveedor& P) : name(P.name), phone(P.phone), address(P.address), code(P.code)
{

}

void Proveedor::setName(std::string &nombre) {
name = nombre;
}

void Proveedor::setPhone(std::string &tel) {
phone = tel;
}

void Proveedor::setCode(std::string &codigo) {
code = codigo;
}

void Proveedor::setAddrs(std::string &dir) {
address = dir;
}

std::string Proveedor::getName() {
    return name;
}

std::string Proveedor::getPhone() {
    return phone;
}

std::string Proveedor::getCode() {
    return code;
}

std::string Proveedor::getAddress() {
    return address;
}

Proveedor& Proveedor::operator=(Proveedor& AG)
{
    name = AG.name;
    phone = AG.phone;
    code = AG.code;
    address = AG.address;

    return *this;
}

bool Proveedor::operator ==(Proveedor& AG)
{
    if(name == AG.name)
    {
        if(code != AG.code)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool Proveedor::operator!=(Proveedor& A)
{
    return name != A.name;
}

bool Proveedor::operator<=(Proveedor& A)
{
    return name <= A.name;
}

bool Proveedor::operator<(Proveedor& A)
{
    return name < A.name;
}

bool Proveedor::operator>=(Proveedor& A)
{
    return name >= A.name;
}

bool Proveedor::operator>(Proveedor& A)
{
    return name > A.name;
}

std::string Proveedor::toString() {

    std::string myStr("");

    myStr += "Nombre: ";
    myStr += name;
    myStr += "\tTelefono: ";
    myStr += phone;
    myStr += "\t Codigo: ";
    myStr += code;
    myStr += "\t Direccion: ";
    myStr += address;

    return  myStr;
}

std::string Proveedor::toStringComas() { //name,phone,code,address,

    std::string myStr("");

    myStr += name;
    myStr += ",";
    myStr += phone;
    myStr += ",";
    myStr += code;
    myStr += ",";
    myStr += address;
    myStr += ",";

    return  myStr;
}
