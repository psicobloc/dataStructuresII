//
// Created by hugo on 28/08/19.
//

#include "producto.h"

using  namespace std;

Producto::Producto() {

}

Producto::Producto(Producto & P) : nombre(P.nombre), codigo(P.codigo), precio(P.precio), cantidad(P.cantidad)
{

}

void Producto::setName(std::string &name)
{
nombre = name;

}

void Producto::setCode(std::string &code) {

    codigo = code;

}

void Producto::setPrice(std::string &price) {
precio = price;

}

void Producto::setAmount(std::string &amo) {
cantidad = amo;
}

std::string Producto::getName() {
    return nombre;
}

std::string Producto::getCode() {
    return codigo;
}

std::string Producto::getPrice() {
    return precio;
}

std::string Producto::getAmount() {
    return cantidad;
}

Producto &Producto::operator=(Producto & P) {
    nombre = P.nombre;
    codigo = P.codigo;
    precio = P.precio;
    cantidad = P.cantidad;

}

bool Producto::operator==(Producto &P) {
    return codigo == P.codigo;
}

bool Producto::operator!=(Producto &P) {
    return codigo != P.codigo;
}

/// cambiarlo a comparar magnitudes de la cantidad de producto
//bool Producto::operator<=(Producto &P) {
//    return codigo <= P.codigo;
//
//}
//
//bool Producto::operator<(Producto &P) {
//    return codigo < P.codigo;
//
//}
//
//bool Producto::operator>=(Producto &P) {
//    return codigo >= P.codigo;
//
//}
//
//bool Producto::operator>(Producto &P) {
//    return codigo > P.codigo;
//
//}

std::string Producto::toString() {

    string myStr("");

    myStr += "nombre\t";
    myStr += nombre;
    myStr += "\tcodigo\t";
    myStr += codigo;
    myStr += "\tprecio\t";
    myStr += precio;
    myStr += "\tcantidad\t";
    myStr += cantidad;
    myStr += "\n";

    return myStr;
}
