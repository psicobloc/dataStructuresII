// Created by Hugo.

#ifndef ENTREGABLE1_FACTURA_H
#define ENTREGABLE1_FACTURA_H

#include "listProd.h"
#include "menuProd.h"
#include "ListaClientes.h" //funcion retrieve
#include "MenuClientes.h"  //cargar lista de clientes y get lista de clientes ram.


class Factura ///@nombre del archivo = "factura" + codigoFactura + ".txt"
{
private:
    std::string codigoFactura; ///maximo 15chars todos los codigos
    std::string codigoCliente; // de aquí se obtiene al informacion del cliente.
    std::string rfcCliente;
    std::string codigoVenta; //aun no se crea el objeto venta...
    ListProd listaProdFactura;
    float total;
    float iva;

public:
    Factura();
    Factura(Factura& fac);
    Factura(ListProd& lista);

    void setCodigoFactura(std::string codF);
    void setCodigoCliente(std::string codC); //manda llamar a setRFC
    void setRFC(std::string rfc);
    void setCodigoVenta(std::string codV);
    void setListaProdFactura(ListProd& lista);
    void setTotal(float tot);               //manda llamar a set IVA
    void setIva();

    std::string getCodigoFactura();
    std::string getCodCliente();
    std::string getCodVenta();
    std::string getRFC();
    ListProd getListaProdFactura();
    float getTotal();
    float getIVA();

    std::string toString();

    void read(std::string);        //se lee y escribe solamente la lista de productos
    void write(std::string);       //la factura se escribe en la lista de facturas

    Factura& operator = (Factura& fac);
    bool operator == (Factura& fac);
};


#endif //ENTREGABLE1_FACTURA_H
