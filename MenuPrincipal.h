// Created by hugo 

#ifndef ENTREGABLE1_MENUPRINCIPAL_H
#define ENTREGABLE1_MENUPRINCIPAL_H

#include "menuProd.h"
#include "menuProv.h"
#include "MenuUsuarios.h"
#include "MenuVenta.h"
#include "MenuClientes.h"
#include "MenuEmpleados.h"
#include "MenuFacturas.h"
#include "MenuOrdenCompra.h"


class MenuPrincipal
{
private:
    std::string tipoDeUsuario;
    std::string nombreUsuario;

    MenuUsuarios mUsuarios;
    MenuVenta mVenta;
    MenuClientes mClientes;
    MenuEmpleados mEmpleados;
    MenuFacturas mFacturas;
    MenuOrdenCompra mOrdenCompra;
    MenuProd mProductos;
    MenuProv mProveedores;

public:

    MenuPrincipal(std::string tipoU, std::string nombreU); ///solamente sirve si se hizo login

    void menuAdministradores(); /// todas las funcionalidades menos el menu de usuarios;
    void menuUsuarios(); /// solamente si tipoDeUsuario == 'root'
    void menuVentaBase();
    void menuClientesBase();
    void menuEmpleadosBase();
    void menuFacturasBase();
    void menuOrdenCompraBase();
    void menuProductosBase();
    void menuProveedoresBase();
    void menuBase();


};
#endif //ENTREGABLE1_MENUPRINCIPAL_H
