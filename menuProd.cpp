//
// Created by hugo on 28/08/19.
//

#include "menuProd.h"

using namespace std;

void MenuProd::addProd() {
    string name, price, code, amo;
    Producto nuevoP;

    cout << "Agregar Producto" << endl;
    //fflush(stdin);
    cout << "Escribe el nombre del Producto:\t";
    //cin >> x;
    fflush(stdin);
    fflush(stdin);
    getline(cin,name);
    getline(cin,name);
    cout << endl << "Escribe el Codigo del Producto:\t";
    fflush(stdin);
    getline(cin,code);
    cout << endl << "Escribe el Precio del Producto:\t"; //todo /// validar que el codigo no esté repetido.
    fflush(stdin);
    getline(cin,price);
    cout << endl << "Escribe la cantidad del Producto:\t";
    fflush(stdin);
    getline(cin,amo);

    nuevoP.setName(name);
    nuevoP.setPrice(price);
    nuevoP.setCode(code);
    nuevoP.setAmount(amo);

    cout << nuevoP.toString() << endl;

    listaRAM.insertData(listaRAM.getLastPos(),nuevoP);
}

void MenuProd::modifyProd() { ///se necesitan nombre y codigo para buscar con find Data.

    string code, name, price, amo;
    char opc('X');
    Producto auxProd;

    cout << "Modificacion de Productos\n\nLista de Productos" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del Producto que deseas modificar:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del Producto que deseas modificar:\t";
    fflush(stdin);
    getline(cin, name);

    auxProd.setCode(code);
    auxProd.setName(name);

    NodeProd* auxNode;

    auxNode = listaRAM.findData(auxProd);

    if(!listaRAM.isValidPos(auxNode))
    {
        cout << "El producto no existe" << endl;
        return;
    }

    cout << "Modificar Producto?\n\t" << auxNode->getData().toString() << endl << " ? [S/N]" << endl;
    fflush(stdin);
    cin >> opc;

    if (opc == 's' || opc == 'S') // todo modificar
    {
        cout << "Escribe el nuevo nombre del producto\t Actual: " << auxNode->getData().getName() << endl;
        fflush(stdin);
        getline(cin, name);

        cout << "Escribe el nuevo precio del producto\t Actual: " << auxNode->getData().getPrice() << endl;
        fflush(stdin);
        getline(cin, price);

        cout << "Escribe la nueva cantidad del producto\t Actual: " << auxNode->getData().getAmount() << endl;
        fflush(stdin);
        getline(cin, amo);

        auxNode->getData().setName(name);
        auxNode->getData().setPrice(price);
        auxNode->getData().setAmount(amo);

        cout << "Producto modificado:\n" << auxNode->getData().toString() << endl;

    } else
    {
        return;
    }

}

void MenuProd::deleteProd() {

    string code, name;
    char opc('X');
    Producto auxProd;

    cout << "Eliminacion de Productos\n\nLista de Productos" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del Producto que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del Producto que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, name);

    auxProd.setCode(code);
    auxProd.setName(name);

    NodeProd* auxNode;

    auxNode = listaRAM.findData(auxProd);

    if(!listaRAM.isValidPos(auxNode))
    {
        cout << "El producto no existe" << endl;
        return;
    }

    cout << "Eliminar Producto?\n\t" << auxNode->getData().toString() << endl << " ? [S/N]" << endl;
    fflush(stdin);
    cin >> opc;

    if (opc == 's' || opc == 'S') // eliminar
    {
        listaRAM.deleteData(auxNode);
        cout << "producto eliminado" << endl;
        cout << listaRAM.toString() << endl;
    } else
    {
        return;
    }

}

void MenuProd::searchProd()
{
    string code, name;
    Producto auxProd;

    cout << "Eliminacion de Productos\n\nLista de Productos" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del Producto que buscas:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del Producto que buscas:\t";
    fflush(stdin);
    getline(cin, name);

    auxProd.setCode(code);
    auxProd.setName(name);

    NodeProd *auxNode;

    auxNode = listaRAM.findData(auxProd);

    if (!listaRAM.isValidPos(auxNode))
    {
        cout << "El producto no existe" << endl;
        return;
    }

    cout << "Producto encontrado:\n" << auxNode->getData().toString() << endl;

}

void MenuProd::showAllProd() {

    cout << "Lista de Productos: " << endl << endl << endl << endl;
    cout << listaRAM.toString() << endl;

}

MenuProd::MenuProd() {
    //mainMenu();
}

void MenuProd::mainMenu() {

    char opc('X');

    while (opc != 's') {
        cout
                << "Menu de Productos:\n\n1)Agregar Productos\n2)Modificar Productos\n3)Eliminar Productos\n4)Buscar Productos\n5)Mostrar todos los Productos\n6)Guardar en el disco\n7)Cargar desde el disco\n\n\ns)SALIR"
                << endl << endl;
        fflush(stdin);
        cin >> opc;

        switch (opc) {
            case '1': {
                addProd();
                break;
            }
            case '2': {
                modifyProd();
                break;
            }
            case '3': {
                deleteProd();
                break;
            }
            case '4': {
                searchProd();
                break;
            }
            case '5': {
                showAllProd();
                break;
            }
            case '6': {
                write();
                break;
            }
            case '7': {
                read();
                break;
            }
            default: {
                cout << opc << " No es una de las opciones del menu, s para salir" << endl;
                break;
            }
        }

    }

}

void MenuProd::write() {

    listaRAM.write("Productos.txt");

}

void MenuProd::read() {

    listaRAM.read("Productos.txt");

}

void MenuProd::setList(ListProd &lista) {
listaRAM = lista;
}
