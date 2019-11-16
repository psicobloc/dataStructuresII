
#include "Venta.h"

Venta::Venta() : listaProdVenta()
{}

Venta::Venta(Venta &v) : codigoVenta(v.codigoVenta), codigoCliente(v.codigoCliente), codigoEmpleado(v.codigoEmpleado),
                         listaProdVenta(v.listaProdVenta), total(v.total)
{}

Venta::Venta(ListProd &listaProductos) : listaProdVenta(listaProductos)
{}

void Venta::setCodigoVenta(std::string codV)
{
    codigoVenta = codV;
}

void Venta::setCodigoCliente(std::string codC)
{
    codigoCliente = codC;
}

void Venta::setCodigoEmpleado(std::string codE)
{
    codigoEmpleado = codE;
}

void Venta::setTotal(float t)
{
    total = t;
}

void Venta::setListaProductosVenta(ListProd &lista)
{
    listaProdVenta = lista;
}

std::string Venta::getCodigoVenta()
{
    return codigoVenta;
}

std::string Venta::getCodigoCliente()
{
    return codigoCliente;
}

std::string Venta::getCodigoEmpleado()
{
    return codigoEmpleado;
}

float Venta::getTotal()
{
    return total;
}

ListProd Venta::getListaProductosVenta()
{
    return listaProdVenta;
}

std::string Venta::toString()
{
    std::string mystr("Codigo de venta:");

    mystr += codigoVenta;
    mystr += "\tCodigo cliente:\t";
    mystr += codigoCliente;
    mystr += "\tCodigo de empleado:\t";
    mystr += codigoEmpleado;
    mystr += "\n\nLista de productos:\n";
    mystr += listaProdVenta.toString();
    mystr += "\tTotal:\t";
    mystr += std::to_string(total);

    return mystr;
}

Venta &Venta::operator=(Venta &v)
{
    codigoVenta = v.codigoVenta;
    codigoCliente = v.codigoCliente;
    codigoEmpleado = v.codigoEmpleado;
    listaProdVenta = v.listaProdVenta;
    total = v.total;
}

void Venta::readListaProductos(std::string fileName) //filename = "venta" + codigoVenta
{
listaProdVenta.read(fileName);
}

void Venta::writeListaProductos(std::string fileName) //filename = "venta" + codigoVenta
{
listaProdVenta.write(fileName);
}

bool Venta::operator==(Venta &v)
{
    return v.codigoVenta == codigoVenta;
}


