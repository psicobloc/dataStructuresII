// Created by hugo 

#include "MenuPrincipal.h"

using namespace std;

MenuPrincipal::MenuPrincipal(std::string tipoU, std::string nombreU) : tipoDeUsuario(tipoU), nombreUsuario(nombreU)
{}

void MenuPrincipal::menuAdministradores()
{
    char opc('X');

    while (opc != 's')
    {
        system("cls");
        system("cls");
        cout << "Menu de administradores" << endl;
        cout << "Escribe la opcion que deseas:" << endl;
        cout << "1) Menu de productos [campos de dimension]" << endl;
        cout << "2) Menu de proveedores [delimitadores]" << endl;
        cout << "3) Menu de ventas [Dispersion *incompleto]" << endl;
        cout << "4) Menu de clientes [Listas invertidas]" << endl;
        cout << "5) Menu de empleados [Indices]" << endl;
        cout << "6) Menu de facturacion [serializacion]" << endl;
        cout << "7) Menu de ordenes de compra [Longitud fija]" << endl;
        cout << "8) Menu de usuarios [Extra]" << endl;
        cout << "\n\ns) salir" << endl;
        fflush(stdin);
        cin >> opc;

        switch (opc)
        {
            case '1':
            {
                mProductos.mainMenu();
                break;
            }

            case '2':
            {
                mProveedores.mainMenu();
                break;
            }

            case '3':
            {
                mVenta.mainMenu();
                break;
            }

            case '4':
            {
                mClientes.mainMenu();
                break;
            }

            case '5':
            {
                mEmpleados.mainMenu();
                break;
            }

            case '6':
            {
                mFacturas.mainMenu();
                break;
            }

            case '7':
            {
                mOrdenCompra.mainMenu();
                break;
            }

            case '8':
            {
                menuUsuarios();
                break;
            }

            default:
            {
                cout << "Opcion incorrecta" << endl;
                break;
            }
        }
    }
}

void MenuPrincipal::menuBase() //menu de usuarios base
{
    char opc('x');

    while (opc != 's')
    {
        system("cls");
        system("cls");
        cout << "Menu de usuarios sin privilegios" << endl;
        cout << "Escribe la opcion que deseas:" << endl;
        cout << "1) Menu de productos [campos de dimension]" << endl;
        cout << "2) Menu de proveedores [delimitadores]" << endl;
        cout << "3) Menu de ventas [Dispersion *incompleto]" << endl;
        cout << "4) Menu de clientes [Listas invertidas]" << endl;
        cout << "5) Menu de empleados [Indices]" << endl;
        cout << "6) Menu de facturacion [serializacion]" << endl;
        cout << "7) Menu de ordenes de compra [Longitud fija]" << endl;
        
        cout << "\n\ns) salir" << endl;
        fflush(stdin);
        cin >> opc;

        switch (opc)
        {
            case '1':
            {
                menuProductosBase();
                break;
            }

            case '2':
            {
                menuProveedoresBase();
                break;
            }

            case '3':
            {
                menuVentaBase();
                break;
            }

            case '4':
            {
                menuClientesBase();
                break;
            }

            case '5':
            {
                menuEmpleadosBase();
                break;
            }

            case '6':
            {
                menuFacturasBase();
                break;
            }

            case '7':
            {
                menuOrdenCompraBase();
                break;
            }

            default:
            {
                cout << "Opcion incorrecta" << endl;
                break;
            }
        }
    }
}

void MenuPrincipal::menuUsuarios()
{
///menu de usuarios al que solo accede root

    if (tipoDeUsuario != "root")
    {
        cout << "\n\n\n\n Unicamente root puede modificar usuarios, Lista de usuarios:\n\n" << endl;
        mUsuarios.showAllUsers();
        return;
    } else
    {
        mUsuarios.mainMenu();
    }
}

void MenuPrincipal::menuVentaBase()
{
    char opc('X');


    while (opc != 's') {

        //limpiar pantalla

        cout << "Menu de ventas.\n" << endl;
        cout << "1) Agregar una nueva venta" << endl;
        cout << "2) Mostrar todas las ventas" << endl;
        cout << "3) Escribir lista de ventas" << endl;
        cout << "4) Leer lista de ventas" << endl;
        cout << "s) Salir." << endl;

        cin >> opc;

        switch (opc)
        {
            case '1':
            {
                mVenta.addVenta();
                break;
            }

            case '2':
            {
                mVenta.showAllVenta();
                break;
            }

            case '3':
            {
               mVenta.write();
                break;
            }

            case '4':
            {
               mVenta.read();
                break;
            }

            default:
            {
                cout << "opcion invallida" << endl;
                break;
            }
        }
    }
}

void MenuPrincipal::menuClientesBase()
{

    char opc('x');
    string edo;


    while (opc != 's')
    {
        system("cls");
        cout << endl << "menu principal" << endl
             << "1)mostrar clientes\n2)mostrar clientes por estado\n3)cargar lista\n4)Mostrar lista invertida\n5)Mostrar lista normal\ns)salir"
             << endl;
        fflush(stdin);
        cin >> opc;
        //cin >> opc;

        switch (opc)
        {
            case '1':
            {
                mClientes.show();
                break;
            }

            case '2':
            {
                cout << endl << "Escribe el estado:\t";
                fflush(stdin);
                getline(cin, edo);
                getline(cin, edo);
                mClientes.mostrarClientesPorEdo(edo);
                break;
            }

            case '3':
            {
                mClientes.cargarLista();
                break;
            }

            case '4':
            {
                mClientes.mostrarLlistaInvertida();
                break;
            }

            case '5':
            {
                mClientes.mostrarLista();
                break;
            }

            default:
                cout << "Opcion invalida, s para salir" << endl;
                break;
        }
    }

}

void MenuPrincipal::menuEmpleadosBase()
{
    char opc('x');
    string codigoEmp;

    while (opc != 's')
    {
        system("cls");
        system("cls");
        cout << "Elija la opcion que desea:\n1) mostrar empleados\n2) buscar empleado\ns) salir"<<endl<<endl;
        fflush(stdin);
        cin>>opc;

        switch(opc)
        {

            case '1':
            {
                mEmpleados.mostrarTodos();
                break;
            }
            case '2':
            {
                cout << "Escribe el codigo del empleado por favor\n" << endl;
                fflush(stdin);
                getline(cin, codigoEmp);
                getline(cin, codigoEmp);
                mEmpleados.mostrarEmpleado(codigoEmp);
                break;
            }

            default:
            {
                cout << "opcion invalida" << endl;
                break;
            }
        }
    }
}

void MenuPrincipal::menuFacturasBase()
{
    char opc('x');

    while (opc != 's')
    {
        cout << "Menu de facturas\n"<< endl;
        cout << "1) Crear factura"<< endl;
        cout << "2) Mostrar facturas"<< endl;
        cout << "3) Buscar facturas"<< endl;
        cout << "4) Guardar facturas"<< endl;
        cout << "5) Leer lista de facturas"<< endl;
        cout << "S) salir"<< endl;
        fflush(stdin);
        cin >> opc;

        switch(opc)
        {
            case '1':
            {
                mFacturas.addFactura();
                break;
            }

            case '2':
            {
                mFacturas.showAllFactura();
                break;
            }

            case '3':
            {
                mFacturas.searchFactura();
                break;
            }

            case '4':
            {
                mFacturas.write();
                break;
            }

            case '5':
            {
                mFacturas.read();
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

void MenuPrincipal::menuOrdenCompraBase()
{
    char opc('x');

    while (opc != 's')
    {
        cout << "Menu de Ordenes de Compra\n"<< endl;
        cout << "1) Mostrar ordenes de compra"<< endl;
        cout << "2) Buscar ordenes de compra"<< endl;
        cout << "3) Leer lista de ordenes de compra"<< endl;
        cout << "S) salir"<< endl;
        fflush(stdin);
        cin >> opc;

        switch(opc)
        {
            case '1':
            {
                mOrdenCompra.showAllOrden();
                break;
            }

            case '2':
            {
                mOrdenCompra.searchOrden();
                break;
            }

            case '3':
            {
                mOrdenCompra.read();
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

void MenuPrincipal::menuProductosBase()
{
    char opc('X');

    while (opc != 's') {
        cout
                << "Menu de Productos para usuarios base:\n\n1)Buscar Productos\n2)Mostrar todos los Productos\n3)Cargar desde el disco\n\n\ns)SALIR"
                << endl << endl;
        fflush(stdin);
        cin >> opc;

        switch (opc) {
            case '1': {
                mProductos.searchProd();
                break;
            }
            case '2': {
                mProductos.showAllProd();
                break;
            }
            case '3': {
                mProductos.read();
                break;
            }

            default: {
                cout << opc << " No es una de las opciones del menu, s para salir" << endl;
                break;
            }
        }
    }
}

void MenuPrincipal::menuProveedoresBase()
{
    char opc('X');

    while (opc != 's') {
        cout
                << "Menu de Proveedores:\n1)Buscar Proveedores\n2)Mostrar todos los proveedores\n3)Cargar desde el disco\n\n\ns)SALIR"
                << endl << endl;
        fflush(stdin);
        cin >> opc;

        switch (opc) {
            case '1': {
                mProveedores.searchProv();
                break;
            }
            case '2': {
                mProveedores.showAllProv();
                break;
            }
            case '3': {
                mProveedores.read();
                break;
            }
            default: {
                cout << opc << " No es una de las opciones del menu, s para salir" << endl;
                break;
            }
        }
    }
}
