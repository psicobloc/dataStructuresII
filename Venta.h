#ifndef ENTREGABLE1_VENTA_H
#define ENTREGABLE1_VENTA_H

#include "MenuClientes.h"
#include "MenuEmpleados.h"
#include "menuProd.h"

class Venta
{
private:

std::string codigoVenta;
std::string codigoCliente;
std::string codigoEmpleado;
ListProd listaProdVenta;
float  total;

public:

Venta();
Venta(Venta& v);
Venta(ListProd & listaProductos);

void setCodigoVenta(std::string codV);
void setCodigoCliente(std::string codC);
void setCodigoEmpleado(std::string codE);
void setTotal(float t);
void setListaProductosVenta(ListProd& lista);

std::string getCodigoVenta();
std::string getCodigoCliente();
std::string getCodigoEmpleado();
float getTotal();
ListProd getListaProductosVenta();

std::string toString();

Venta& operator = (Venta& v);
bool operator == (Venta& v);

void readListaProductos(std::string fileName); //filename = "venta" + codigoVenta
void writeListaProductos(std::string fileName);

};

#endif //ENTREGABLE1_VENTA_H