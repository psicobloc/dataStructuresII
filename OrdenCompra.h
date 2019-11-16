
#ifndef ENTREGABLE1_ORDENCOMPRA_H
#define ENTREGABLE1_ORDENCOMPRA_H
                                        ///registros de Longitud Fija
#include "listProd.h"
#include "menuProd.h"
#include "menuProv.h"
#include "listProv.h"

class OrdenCompra /// Pedidos a Proveedores
{
private:

    std::string code;               //** se guarda en listaPedidos.txt
    std::string userCode;           //** se guarda en listaPedidos.txt
    std::string codigoProveedor;    //** se guarda en listaPedidos.txt
   /// en menu de pedidos mejor //ListProd listaCompletaProductos; //cargar del disco la lista completa de productos
   /// en menu de pedidos mejor //ListaProv listaProveedoresCompleta; // no se guarda, solo se lee.
    ListProd listaProdOrdenCompra;   // productos específicos a esta orden de compra (pedido a proveedores), nombre del archivo es el codigo de la orden de compra
    float totalPedido;              //** se guarda en listaPedidos.txt

public:

    OrdenCompra();
    OrdenCompra(OrdenCompra& pedido);

    OrdenCompra( ListProd& lista);

    void setCode(std::string);
    void setUserCode(std::string);
    void setCodigoProveedor(std::string);      /// se busca en menu de pedidos buscando en la lista de proveedores y se asigna a esta variable
    void setListaProdOrdenCompra(ListProd& lista); /// la lista se escoge y se crea en menu de pedidos y cuando esta lista se asiga a la orden de compra.
    void setTotalPedido(float);

    std::string getCode();
    std::string getUserCode();
    std::string getProvCode();
    ListProd getListaProdOrdenCompra();
    float getTotalPedido();

    void read(std::string filename);
    void write(std::string filename); //solamente escribe la lista de productos, la orden se escribe en listaOrdenCompra

    std::string toString();

    OrdenCompra& operator = (OrdenCompra& pedido);
    bool operator == (OrdenCompra& pedido);

    // operators?

};
#endif //ENTREGABLE1_ORDENCOMPRA_H