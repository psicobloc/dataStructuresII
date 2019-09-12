// Created by hugo on 25/08/19.

#include "menuProv.h"
using namespace std;

void MenuProv::addProv() {
    string name, phone, code, addrs;
    Proveedor nuevoP;
    //char x;

    cout << "Agregar Proveedor" << endl;
    //fflush(stdin);
    cout << "Escribe el nombre del proveedor:\t";
    fflush(stdin);
    getline(cin,name);
    getline(cin,name);
    cout << endl << "Escribe el telefono del proveedor:\t";
    fflush(stdin);
    getline(cin,phone);
    cout << endl << "Escribe el Codigo del proveedor:\t"; //todo /// validar que el codigo no esté repetido.
    fflush(stdin);
    getline(cin,code);
    cout << endl << "Escribe la direccion del proveedor:\t";
    fflush(stdin);
    getline(cin,addrs);

    nuevoP.setName(name);
    nuevoP.setPhone(phone);
    nuevoP.setCode(code);
    nuevoP.setAddrs(addrs);

    listaRAM.insertData(listaRAM.getLastPos(),nuevoP);
}

void MenuProv::modifyProv() { ///se necesitan nombre y codigo para buscar con find Data.

    string code, name, phone, addrs;
    char opc('X');
    Proveedor auxProv;

    cout << "Modificacion de Proveedores\n\nLista de Provedores" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del proveedor que deseas modificar:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del proveedor que deseas modificar:\t";
    fflush(stdin);
    getline(cin, name);

    auxProv.setCode(code);
    auxProv.setName(name);

    NodoProv* auxNode;

    auxNode = listaRAM.findData(auxProv);

    if(!listaRAM.isValidPos(auxNode))
    {
        cout << "El proveedor no existe" << endl;
        return;
    }

    cout << "Modificar Proveedor?\n\t" << auxNode->getData().toString() << endl << " ? [S/N]" << endl;
    fflush(stdin);
    cin >> opc;

    if (opc == 's' || opc == 'S') // modificar
    {

        cout << "Escribe el nuevo nombre del proveedor\t Actual:" << auxNode->getData().getName() << endl;
        fflush(stdin);
        getline(cin,name);

        cout << "Escribe el nuevo telefono del proveedor\t Actual:" << auxNode->getData().getPhone() << endl;
        fflush(stdin);
        getline(cin,phone);

        cout << "Escribe la nueva direccion del proveedor\t Actual:" << auxNode->getData().getAddress() << endl;
        fflush(stdin);
        getline(cin,addrs);

        auxNode->getData().setName(name);
        auxNode->getData().setPhone(phone);
        auxNode->getData().setAddrs(addrs);

        cout << "Proveedor modificado:" << endl << auxNode->getData().toString() << endl;

    } else
    {
        return;
    }


}

void MenuProv::deleteProv() {

    string code, name;
    char opc('X');
    Proveedor auxProv;

    cout << "Eliminacion de Proveedores\n\nLista de Provedores" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del proveedor que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del proveedor que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, name);

    auxProv.setCode(code);
    auxProv.setName(name);

    NodoProv* auxNode;

    auxNode = listaRAM.findData(auxProv);

    if(!listaRAM.isValidPos(auxNode))
    {
        cout << "El proveedor no existe" << endl;
        return;
    }

    cout << "Eliminar Proveedor?\n\t" << auxNode->getData().toString() << endl << " ? [S/N]" << endl;
    fflush(stdin);
    cin >> opc;

    if (opc == 's' || opc == 'S') // eliminar
    {
        listaRAM.deleteData(auxNode);
        cout << "Proveedor eliminado" << endl;
        cout << listaRAM.toString() << endl;

    } else
    {
        return;
    }

}

void MenuProv::searchProv() {
    string code, name;
    Proveedor auxProv;

    cout << "Eliminacion de Proveedores\n\nLista de Provedores" << endl;
    cout << listaRAM.toString() << endl;
    cout << "\n\n\nEscribe el codigo del proveedor que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, code);
    cout << "\n\n\nEscribe el nombre del proveedor que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, name);

    auxProv.setCode(code);
    auxProv.setName(name);

    NodoProv* auxNode;

    auxNode = listaRAM.findData(auxProv);

    if(!listaRAM.isValidPos(auxNode))
    {
        cout << "El proveedor no existe" << endl;
        return;
    }

    cout << "Proveedor encontrado:\t" << auxNode->getData().toString() << endl;
}

void MenuProv::showAllProv() {

    cout << "Lista de Proveedores: " << endl << endl << endl << endl;
    cout << listaRAM.toString() << endl;

}

MenuProv::MenuProv() {
//mainMenu();
}

void MenuProv::mainMenu() {

    char opc('X');

while (opc != 's') {
    cout
            << "Menu de Proveedores:\n\n1)Agregar proveedores\n2)Modificar proveedores\n3)Eliminar proveedores\n4)Buscar Proveedores\n5)Mostrar todos los proveedores\n6)Guardar en el disco\n7)Cargar desde el disco\n\n\ns)SALIR"
            << endl << endl;
    fflush(stdin);
    cin >> opc;

    switch (opc) {
        case '1': {
            addProv();
            break;
        }
        case '2': {
            modifyProv();
            break;
        }
        case '3': {
            deleteProv();
            break;
        }
        case '4': {
            searchProv();
            break;
        }
        case '5': {
            showAllProv();
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

void MenuProv::write() {

    listaRAM.write("proveedores.txt");

}

void MenuProv::read() {

    listaRAM.read("proveedores.txt");

}
