
#include "MenuVenta.h"

using namespace std;

MenuVenta::MenuVenta()
{
    listaProductos.read("Productos.txt");
    cout << "leida lista de productos" << endl;

}

void MenuVenta::mainMenu()
{
    char opc('X');


    while (opc != 's') {

        //limpiar pantalla

        cout << "Menu de ventas.\n" << endl;
        cout << "1) Agregar una nueva venta" << endl;
        cout << "2) Modificar una venta" << endl;
        cout << "3) Buscar una venta" << endl; //todo hacer la busqueda con dispersion, no leer toda la lista!!
        cout << "4) Eliminar una venta" << endl;
        cout << "5) Mostrar todas las ventas" << endl;
        //cout << "1) Escribir lista de ventas" << endl;
        //cout << "1) Leer lista de ventas" << endl;
        cout << "s) Salir." << endl;

        cin >> opc;

        switch (opc)
        {

            case '1':
            {
                addVenta();
                break;
            }

            case '2':
            {
                modifyVenta();
                break;
            }

            case '3':
            {
                searchVenta();
                break;
            }

            case '4':
            {
                deleteVenta();
                break;
            }

            case '5':
            {
                showAllVenta();
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

void MenuVenta::addVenta()
{
    string codigoVenta, codigoCliente, codigoEmpleado;
    string codigoProd, amount;
    float total(0.0), precio(0.0), totalOrden(0.0);
    float cantidadProd(0.0);
    char ContinnuarEligiendo('s');
    char data[10];

    Venta nuevaVenta;
    Producto nuevoProducto;
    ListProd nuevaListaProductos;
    MenuClientes mClientes;

    cout << "Crear nueva Venta" << endl;
    cout << "Escribe el Codigo de la Venta:" << endl; //todo codigo autogenerable
    fflush(stdin);
    getline(cin, codigoVenta);
    getline(cin, codigoVenta);
    nuevaVenta.setCodigoVenta(codigoVenta);

    cout << "Escribe el codigo del cliente de la siguiente lista:\n" << endl;
    mClientes.cargarLista(); //todo verificar que el codigo si exista
    mClientes.mostrarLista();

    fflush(stdin);
    getline(cin, codigoCliente);
    nuevaVenta.setCodigoCliente(codigoCliente);

    cout << "Escribe tu codigo de empleado" << endl;
    fflush(stdin);
    getline(cin, codigoEmpleado);
    nuevaVenta.setCodigoEmpleado(codigoEmpleado);

    while (ContinnuarEligiendo == 's') {
        cout << listaProductos.toString() << endl;
        cout << "escribe el codigo del producto que deseas:\t";
        fflush(stdin);
        getline(cin, codigoProd);
        nuevoProducto.setCode(codigoProd);

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

    nuevaVenta.setListaProductosVenta(nuevaListaProductos);
    nuevaVenta.setTotal(totalOrden);
    cout << "Total orden: $" << to_string(totalOrden)  << endl;
    cout << "Creando Venta:" << endl << endl << endl;
    cout << nuevaVenta.toString() << endl << endl;
    listaRam.insertData(listaRam.getLastPos(), nuevaVenta);

}

void MenuVenta::modifyVenta()
{
    string codigoVenta, codigoCliente, codigoEmpleado;
    char modListaProd('n');
    Venta ventaModificada;

    cout << "Modificacion de Ventas" << endl;
    cout << "Escribe el codigo de la venta que deseas modificar" << endl;
    fflush(stdin);
    getline(cin, codigoVenta);
    getline(cin, codigoVenta);

    ventaModificada.setCodigoVenta(codigoVenta);

    if(listaRam.findData(ventaModificada) == nullptr)
    {
        cout << "No existe ninguna venta con ese codigo" << endl;
        return;
    }

    cout << "Escribe el nuevo codigo de cliente" << endl;
    fflush(stdin);
    getline(cin, codigoCliente);
    listaRam.findData(ventaModificada)->getData().setCodigoCliente(codigoCliente);

    cout << "Escribe el nuevo codigo de Empleado" << endl;
    fflush(stdin);
    getline(cin, codigoEmpleado);
    listaRam.findData(ventaModificada)->getData().setCodigoEmpleado(codigoEmpleado);

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

}

void MenuVenta::deleteVenta()
{
    string codigoVenta;
    Venta ventaEliminar;
    char opc('X');
    cout << "Eliminar Factura" << endl;
    cout << "Escribe el codigo de la factura que deseas eliminar" << endl;
    fflush(stdin);
    getline(cin, codigoVenta);
    getline(cin, codigoVenta);
    ventaEliminar.setCodigoVenta(codigoVenta);

    if(listaRam.findData(ventaEliminar) == nullptr)
    {
        cout << "No existe ninguna venta con ese codigo" << endl;
        return;
    }

    cout << "Eliminar venta: " << listaRam.findData(ventaEliminar)->getData().toString() << endl;

    cout << "continuar con la eliminacion? [s->si] [n->no]" << endl;
    fflush(stdin);
    cin >> opc;

    if(opc == 's')
    {
        listaRam.deleteData(listaRam.findData(ventaEliminar));
        cout << "Eliminado" << endl;
    }
}

void MenuVenta::searchVenta()
{

    string codigoVenta;
    Venta ventaBuscar, ventaEncontrada;
    cout << "Buscar factura" << endl;
    cout << "Escribe el codigo de la factura que deseas buscar" << endl;
    fflush(stdin);
    getline(cin, codigoVenta);
    getline(cin, codigoVenta);

    ventaBuscar.setCodigoVenta(codigoVenta);

    if(listaRam.findData(ventaBuscar) == nullptr)
    {
        cout << "No existe ninguna venta con ese codigo" << endl;
        return;
    }

    ventaEncontrada = listaRam.findData(ventaBuscar)->getData();

    cout << "Venta encontrada: \n\n" << ventaEncontrada.toString() << endl;
}

void MenuVenta::showAllVenta()
{
    cout << "Lista de ventas" << endl << endl << endl;
    cout << listaRam.toString() << endl;

}
