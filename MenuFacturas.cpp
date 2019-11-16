// Created by Hugo.

#include "MenuFacturas.h"

using namespace std;

MenuFacturas::MenuFacturas()
{
    listaProductos.read("Productos.txt");
    cout << "leida lista productos" << endl;
}

void MenuFacturas::mainMenu()
{
char opc('x');

    //cout << "Menu orden compra" << endl;

    while (opc != 's')
    {
        cout << "Menu de facturas\n"<< endl;
        cout << "1) Crear factura"<< endl;
        cout << "2) Modificar factura"<< endl;
        cout << "3) Eliminar factura"<< endl;
        cout << "4) Mostrar facturas"<< endl;
        cout << "5) Buscar facturas"<< endl;
        cout << "6) Guardar facturas"<< endl;
        cout << "7) Leer lista de facturas"<< endl;
        cout << "S) salir"<< endl;
        fflush(stdin);
        cin >> opc;

        switch(opc)
        {
            case '1':
            {
                addFactura();
                break;
            }

            case '2':
            {
                modifyFactura();
                break;
            }

            case '3':
            {
                deleteFactura();
                break;
            }

            case '4':
            {
                showAllFactura();
                break;
            }

            case '5':
            {
                searchFactura();
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

void MenuFacturas::addFactura()
{
    string codigoF, codigoC, codigoV, rfc;
    string codigoProducto, amount, RFCstring;
    float total(0.0), precio(0.0), totalOrden(0.0);
    float cantidadProd(0.0);
    char ContinnuarEligiendo('s');
    char data[10];

    Factura nuevaFactura;
    Producto nuevoProducto;
    ListProd nuevaListaProductos;

    cout << "Crear nueva Factura" << endl;
    cout << "Escribe el Codigo de la factura:" << endl; //todo codigo autogenerable
    fflush(stdin);
    getline(cin, codigoF);
    getline(cin, codigoF);
    nuevaFactura.setCodigoFactura(codigoF);


    cout << "Escribe el codigo de la venta:" << endl;
    fflush(stdin);
    getline(cin, codigoV);
    nuevaFactura.setCodigoVenta(codigoV);


    cout << "Escribe el codigo del cliente de la siguiente lista:\n" << endl;
    MenuClientes mClientes;
    mClientes.cargarLista();

    mClientes.mostrarLista();

    fflush(stdin);
    getline(cin, codigoC);
    nuevaFactura.setCodigoCliente(codigoC); // todo verificar que el codigo exista

    //crear un cliente con ese codigo y buscarlo en la lista para resolver todo.

    cout << "Escribe el rfc del cliente:\n" << endl;
    fflush(stdin);
    getline(cin, RFCstring);
    nuevaFactura.setRFC(RFCstring);
    cout << "\n\nnuevafctura\n\n" << nuevaFactura.toString() << endl << endl;

    ///precio es un string.
    cout << "A continuacion debes elegir los productos que se vendieron de la siguiente lista" << endl;
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
            //sumar precio del producto al total
            cout << "Cantidad de producto: " << endl;
            cin >> cantidadProd;
            precio = stof(nuevoProducto.getPrice());
            cout << "Precio: " << precio << endl;
            total = precio*cantidadProd;
            cout << " total " << total << endl;
            totalOrden += total;
            sprintf(data, "%f", cantidadProd);
            amount += data;
            nuevoProducto.setAmount(amount);
            cout << "agregando nuevo producto:\n" << nuevoProducto.toString() << endl;
            nuevaListaProductos.insertData(nuevaListaProductos.getLastPos(),nuevoProducto);

        }

        cout << "Seguir eligiendo productos? [s->si] [n->no]" << endl;
        fflush(stdin);
        cin >> ContinnuarEligiendo;
        amount = "";
    }
    nuevaFactura.setListaProdFactura(nuevaListaProductos);
    nuevaFactura.setTotal(totalOrden);
    cout << "Total orden: " << to_string(totalOrden) << " $" << endl;
    cout << "Creando factura:" << endl << endl << endl ;
    cout << nuevaFactura.toString() << endl << endl;
    listaRam.insertData(listaRam.getLastPos(), nuevaFactura);
}

void MenuFacturas::modifyFactura()
{
    string codigoF, codigoC, codigoV, rfc;
    char modListaProd('n');

    /*    */
    Factura facturaModificada, nuevaFactura;

    cout << "Modificacion de Facturas" << endl;
    cout << "Escribe el codigo de la factura que deseas modificar" << endl;
    fflush(stdin);
    getline(cin, codigoF);
    //getline(cin, codigoF);

    facturaModificada.setCodigoFactura(codigoF);

    if(listaRam.findData(facturaModificada) == nullptr)
    {
        cout << "No existe ninguna factura con ese codigo" << endl;
        return;
    }

    nuevaFactura = listaRam.findData(facturaModificada)->getData();

    cout << "Escribe el nuevo codigo de cliente" << endl;
    fflush(stdin);
    getline(cin, codigoC);
    listaRam.findData(facturaModificada)->getData().setCodigoCliente(codigoC);

    cout << "Escribe el nuevo codigo de venta" << endl;
    fflush(stdin);
    getline(cin, codigoV);
    listaRam.findData(facturaModificada)->getData().setCodigoVenta(codigoV);

    cout << "Escribe el nuevo rfc" << endl;
    fflush(stdin);
    getline(cin, rfc);
    listaRam.findData(facturaModificada)->getData().setRFC(rfc);
///rfc

//todo modificar lista de productos

//    cout << "Desea modificar la lista de productos? [s->si][n->no]" << endl;
//    fflush(stdin);
//    cin >> modListaProd;
//
//    if (modListaProd == 's')
//    {
//        MenuProd M;
//        M.setList(listaProductos);
//        M.modifyProd();
//        M.showAllProd();
//    }

///modificar el total y el iva.

    /* * */


}

void MenuFacturas::deleteFactura()
{
    /*  *  *  */

    string codigo;
    Factura facturaEliminar;
    char opc('x');

    cout << "Eliminar Factura" << endl;
    cout << "Escribe el codigo de la factura que deseas eliminar" << endl;
    fflush(stdin);
    getline(cin, codigo);
    getline(cin, codigo);
    facturaEliminar.setCodigoFactura(codigo);

    if(listaRam.findData(facturaEliminar) == nullptr)
    {
        cout << "No existe ninguna factura con ese codigo" << endl;
        return;
    }

    cout << "Eliminar:\n" << listaRam.findData(facturaEliminar)->getData().toString() << endl;

    cout << "continuar con la eliminacion? [s->si] [n->no]" << endl;
    fflush(stdin);
    cin >> opc;

    if(opc == 's')
    {
        listaRam.deleteData(listaRam.findData(facturaEliminar));
        cout << "Eliminado" << endl;
    }

    /*  *  *  */
}

void MenuFacturas::searchFactura()
{
    string codigo;
    Factura facturaBuscar, facturaEncontrada;

    cout << "Buscar factura" << endl;
    cout << "Escribe el codigo de la factura que deseas buscar" << endl;
    fflush(stdin);
    getline(cin, codigo);
    //getline(cin, codigo);
    facturaBuscar.setCodigoFactura(codigo);

    if(listaRam.findData(facturaBuscar) == nullptr)
    {
        cout << "No existe ninguna factura con ese codigo" << endl;
        return;
    }

    facturaEncontrada = listaRam.findData(facturaBuscar)->getData();

    cout << "factura encontrada:" << endl << endl << facturaEncontrada.toString() << endl;

}

void MenuFacturas::showAllFactura()
{

cout << "Mostrar lista de facturas" << endl;
cout << endl << endl << listaRam.toString() << endl;

}

void MenuFacturas::write()
{

listaRam.write("listaFacturas.bin");

}

void MenuFacturas::read()
{

    listaRam.read("listaFacturas.bin");

}
