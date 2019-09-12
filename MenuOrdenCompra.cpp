// Created by Hugo.

#include "MenuOrdenCompra.h"

using namespace std;

void MenuOrdenCompra::addOrden() { // todo validar que todos los codigo existan

    string codigo, codigoUsuario, codigoProv;
    string codigoProducto;
    float total;
    char ContinnuarEligiendo('s');

    OrdenCompra nuevaOrden;
    Producto nuevoProducto;
    ListProd nuevaListaProductos;

    cout << "Crear nueva orden de compra (pedido a proveedores)" << endl;
    cout << "Escribe el Codigo de la orden de compra:" << endl;
    fflush(stdin);
    getline(cin, codigo);
    //getline(cin, codigo);
    nuevaOrden.setCode(codigo);

    cout << "Escribe el codigo del Usuario:" << endl;
    fflush(stdin);
    getline(cin, codigoUsuario);
    nuevaOrden.setUserCode(codigoUsuario);

    cout << "Escribe el codigo del proveedor" << endl;
    fflush(stdin);
    getline(cin, codigoProv);
    nuevaOrden.setCodigoProveedor(codigoProv);

    ///precio es un string.
    cout << "A continuacion debes elegir los productos que se necesitan de la lista" << endl;
    while (ContinnuarEligiendo == 's') {
        cout << listaProductos.toString() << endl;
        cout << "escribe el codigo del producto que deseas:\t";
        fflush(stdin);
        getline(cin, codigoProducto);
        nuevoProducto.setCode(codigoProducto);

        if(listaProductos.findData(nuevoProducto) == nullptr)
        {
            cout << "El codigo de producto es incorrecto" << endl;
        }
        else
        {
            nuevoProducto = listaProductos.findData(nuevoProducto)->getData();
            cout << "agregando nuevo producto:\n" << nuevoProducto.toString() << endl;
            nuevaListaProductos.insertData(nuevaListaProductos.getLastPos(),nuevoProducto);
            //sumar precio del producto al total
            total += stof(nuevoProducto.getPrice());
        }

        cout << "Seguir eligiendo productos? [s->si] [n->no]" << endl;
        fflush(stdin);
        cin >> ContinnuarEligiendo;
    }
    nuevaOrden.setListaProdOrdenCompra(nuevaListaProductos);
    nuevaOrden.setTotalPedido(total);
}

void MenuOrdenCompra::modifyOrden() {

    string codigo, codigoUsuario, codigoProv;
    char modListaProd('n');

    OrdenCompra ordenModificada, nuevaOrden;

    cout << "Modificacion de orden de compra" << endl;
    cout << "Escribe el codigo de la orden de compra que deseas modificar" << endl;
    fflush(stdin);
    getline(cin, codigo);
    //getline(cin, codigo);
    ordenModificada.setCode(codigo);

    if(listaRam.findData(ordenModificada) == nullptr)
    {
        cout << "No existe ninguna orden de compra con ese codigo" << endl;
        return;
    }

    nuevaOrden = listaRam.findData(ordenModificada)->getData();

    cout << "Escribe el nuevo codigo de usuario" << endl;
    fflush(stdin);
    getline(cin, codigoUsuario);

    cout << "Escribe el nuevo codigo de proveedor" << endl;
    fflush(stdin);
    getline(cin, codigoProv);

    cout << "Desea modificar la lista de productos? [s->si][n->no]" << endl;
    fflush(stdin);
    cin >> modListaProd;

    if (modListaProd == 's')
    {
        MenuProd M;
        M.setList(listaProductos);
        M.modifyProd();
        M.showAllProd();
    }

}

void MenuOrdenCompra::deleteOrden() {

    string codigo;
    OrdenCompra ordenEliminar;
    char opc('x');

    cout << "Eliminar Orden de Compra" << endl;
    cout << "Escribe el codigo de la orden de compra que deseas eliminar" << endl;
    fflush(stdin);
    getline(cin, codigo);
    //getline(cin, codigo);
    ordenEliminar.setCode(codigo);

    if(listaRam.findData(ordenEliminar) == nullptr)
    {
        cout << "No existe ninguna orden de compra con ese codigo" << endl;
        return;
    }

    cout << "continuar con la eliminacion? [s->si] [n->no]" << endl;
    fflush(stdin);
    cin >> opc;

    if(opc == 's')
    {
        listaRam.deleteData(listaRam.findData(ordenEliminar));
        cout << "Eliminado" << endl;
    }

}

void MenuOrdenCompra::searchOrden() {

    string codigo;
    OrdenCompra ordenBuscar, ordenEncontrada;
    char opc('x');

    cout << "Buscar Orden de Compra" << endl;
    cout << "Escribe el codigo de la orden de compra que deseas buscar" << endl;
    fflush(stdin);
    getline(cin, codigo);
    //getline(cin, codigo);
    ordenBuscar.setCode(codigo);

    if(listaRam.findData(ordenBuscar) == nullptr)
    {
        cout << "No existe ninguna orden de compra con ese codigo" << endl;
        return;
    }

    ordenEncontrada = listaRam.findData(ordenBuscar)->getData();

    cout << "Orden encontrada:" << endl << endl << ordenEncontrada.toString() << endl;

}

void MenuOrdenCompra::showAllOrden() {
cout << "Mostrar lista de ordenes de compra" << endl;
cout << endl << endl << listaRam.toString() << endl;
}

void MenuOrdenCompra::write() {
listaRam.write("listaOrdenesCompra.txt");
}

void MenuOrdenCompra::read() {
listaRam.read("listaOrdenesCompra.txt");
}

MenuOrdenCompra::MenuOrdenCompra() {
    listaProductos.read("Productos.txt");
    listaProvedores.read("proveedores.txt");

    //mainMenu();
}

void MenuOrdenCompra::mainMenu() {

    char opc('x');

    while (opc != 's')
    {
        cout << "Menu de Ordenes de Compra\n"<< endl;
        cout << "1) Crear orden de compra"<< endl;
        cout << "2) Modificar orden de compra"<< endl;
        cout << "3) Eliminar orden de compra"<< endl;
        cout << "4) Mostrar ordenes de compra"<< endl;
        cout << "5) Buscar ordenes de compra"<< endl;
        cout << "6) Guardar ordenes de compra"<< endl;
        cout << "7) Leer lista de ordenes de compra"<< endl;
        cout << "S) salir"<< endl;
        fflush(stdin);
        cin >> opc;

        switch(opc)
        {
            case '1':
            {
                addOrden();
                break;
            }

            case '2':
            {
                modifyOrden();
                break;
            }

            case '3':
            {
                deleteOrden();
                break;
            }

            case '4':
            {
                showAllOrden();
                break;
            }

            case '5':
            {
                searchOrden();
                break;
            }

            case '6':
            {
                write();
                break;
            }

            case '7':
            {
                read();
                break;
            }

            default:
            {
                cout << "Opcion invalida, s para salir" << endl;
                break;
            }
        }
    }

}
