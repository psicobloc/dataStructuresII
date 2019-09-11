
#include "OrdenCompra.h"
using namespace std;

OrdenCompra::OrdenCompra() : listaProdOrdenCompra()
{

}



OrdenCompra::OrdenCompra(OrdenCompra &pedido) : code(pedido.code), userCode(pedido.userCode), codigoProveedor(pedido.codigoProveedor), listaProdOrdenCompra(pedido.listaProdOrdenCompra), totalPedido(pedido.totalPedido)
{

}

OrdenCompra::OrdenCompra(ListProd& lista) : listaProdOrdenCompra(lista)
{

}

void OrdenCompra::setCode(string codigo) {
code = codigo;
}

void OrdenCompra::setUserCode(string code) {
userCode = code;
}

void OrdenCompra::setCodigoProveedor(string code) {
codigoProveedor = code;

}

void OrdenCompra::setListaProdOrdenCompra(ListProd& lista) {
listaProdOrdenCompra = lista;
}

void OrdenCompra::setTotalPedido(float total) {
totalPedido = total;
}

std::string OrdenCompra::getCode() {
    return code;
}

std::string OrdenCompra::getUserCode() {
    return userCode;
}

std::string OrdenCompra::getProvCode() {
    return codigoProveedor;
}

ListProd OrdenCompra::getListaProdOrdenCompra() {
    return listaProdOrdenCompra; // & ?
}

float OrdenCompra::getTotalPedido() {
    return totalPedido;
}

void OrdenCompra::read() {




}

void OrdenCompra::write() {





}

//string code, userCode, codigoPproveedor
//ListProd listaProdOrdenCompra
//float totalPedido

std::string OrdenCompra::toString() {

    string ordenString("");

    ordenString += "\nCodigo de orden de pago:  ";
    ordenString += code;
    ordenString += "\nCodigo de usuario que realizo la orden:  ";
    ordenString += userCode;
    ordenString += "\nCodigo del proveedor:  ";
    ordenString += codigoProveedor;
    ordenString += "\nLista de productos en la orden:\n\n";
    ordenString += listaProdOrdenCompra.toString();
    ordenString += "\n\n\t\tTOTAL:  ";
    ordenString += totalPedido;
    ordenString += " $\n";

    return  ordenString;
}
