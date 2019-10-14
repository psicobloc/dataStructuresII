// Created by Hugo.

#include "Factura.h"

using namespace std;

Factura::Factura() : listaProdFactura()
{}

Factura::Factura(Factura &fac) : codigoFactura(fac.codigoFactura), codigoCliente(fac.codigoCliente), rfcCliente(fac.rfcCliente), codigoVenta(fac.codigoVenta),listaProdFactura(fac.listaProdFactura), total(fac.total), iva(fac.iva)
{

}

Factura::Factura(ListProd &lista) : listaProdFactura(lista)
{
}

void Factura::setCodigoFactura(std::string codF)
{
codigoFactura = codF;
}

void Factura::setCodigoCliente(std::string codC)
{
codigoCliente = codC;

/// buscar cliente en la lista de clientes cargada desde menu clientes
///retrieve el cliente con el codigo == codC
///usar setear el rfc.

MenuClientes mClientes;
mClientes.cargarLista();
ListaClientes listClnts(mClientes.getListaClientesRam());
///find data nos da el nodo
///retrieve nos regresa el cliente
///seteamos el rfc del cliente

Cliente auxCliente;
auxCliente.setCodigoCliente(codC);
NodoCliente* auxNodo;
auxNodo = listClnts.findData(auxCliente);
Cliente clnt(listClnts.retrieve(auxNodo));

string rfcReal;
rfcReal = clnt.getRfc();

setRFC(rfcReal);
}

void Factura::setRFC(std::string rfc)
{
rfcCliente = rfc;
}

void Factura::setCodigoVenta(std::string codV)
{
codigoVenta = codV;
}

void Factura::setListaProdFactura(ListProd &lista)
{
listaProdFactura = lista;
}

void Factura::setTotal(float tot)
{
total = tot;
setIva();
}

void Factura::setIva()
{
iva = total*0.16;
}

std::string Factura::getCodigoFactura()
{
    return codigoFactura;
}

std::string Factura::getCodCliente()
{
    return codigoCliente;
}

std::string Factura::getCodVenta()
{
    return codigoVenta;
}

std::string Factura::getRFC()
{
    return rfcCliente;
}

ListProd Factura::getListaProdFactura()
{
    return listaProdFactura;
}

float Factura::getTotal()
{
    return total;
}

float Factura::getIVA()
{
    return iva;
}

std::string Factura::toString()
{
    string mystr("Codigo:\t");

    mystr += codigoFactura;
    mystr += "\tCodigo cliente:\t";
    mystr += codigoCliente;
    mystr += "\nRFC:\t";
    mystr += rfcCliente;
    mystr += "\tCodigo de venta\t";
    mystr += codigoVenta;
    mystr += "\n\nLista de productos:\n";
    mystr += listaProdFactura.toString();
    mystr += "\n\nIVA:\t";
    mystr += iva;
    mystr += "\tTotal:\t";
    mystr += total;

}

void Factura::read() //al leer hay que preguntar cual es el codigo de factura.
{
    string mySTR("factura");
    mySTR += codigoFactura;
    mySTR += ".txt";

listaProdFactura.read(mySTR); //@nombre del archivo = "factura" + codigoFactura + ".txt"
}

void Factura::write()
{

    string mySTR("factura");
    mySTR += codigoFactura;
    mySTR += ".txt";

listaProdFactura.write(mySTR);
}

Factura &Factura::operator=(Factura &fac)
{

}

bool Factura::operator==(Factura &fac)
{
    return codigoFactura == fac.codigoFactura;
}
