// Created by hugo 

#include "MenuUsuarios.h"

using namespace std;

MenuUsuarios::MenuUsuarios()
{
//leer lista de usuarios
read();
}

void MenuUsuarios::addUser()
{

    string name,type;
    string password1("uno");
    string password2("dos");
    int tipo;
    Usuario nuevoUser;


    cout << "Agregar nuevo usuario:" << endl;
    cout << "Escribe el nombre del nuevo usuario" << endl;
    fflush(stdin);
    getline(cin, name);
    getline(cin, name);
    nuevoUser.setNombre(name);
    cout << "Escribe el numero del tipo de usuario:\n1) Administrador\n2) Usuario normal" << endl;
    fflush(stdin);
    cin >> tipo;

    tipo == 1 ? type = "admin" : type = "base"; //validar
    nuevoUser.setTipoUsuario(type);

    while (password1 != password2)
    {
        cout << "Escribe tu contraseña:\t";
        fflush(stdin);
        getline(cin, password1);

        cout << "Escribe tu contraseña de nuevo:\t";
        fflush(stdin);
        getline(cin, password2);
    }

    nuevoUser.setPassword(password2);

    listaRam.insertData(listaRam.getLastPos(), nuevoUser);

    cout << "Usuario creado con exito" << endl  << listaRam.findData(nuevoUser)->getData().toString() << endl;

}

void MenuUsuarios::deleteUser()
{

    string name;
    Usuario userDelete;
    char opc('X');

    cout << "Escribe el nombre del usuario que deseas eliminar:\t";
    fflush(stdin);
    getline(cin, name);
    getline(cin, name);
    userDelete.setNombre(name);

    NodoUsuario* auxNode;
    auxNode = listaRam.findData(userDelete);

    if (!listaRam.isValidPos(auxNode))
    {
        cout << "El usuario con nombre:\t" << name << " no existe" << endl;
        //getline(cin, name);
        return;
    }

    cout << "\n\n Continuar eliminando el usuario " << auxNode->getData().toString() << " ? (1->si / 2-> no)" << endl;
    fflush(stdin);
    cin >> opc;

    if (opc != '1')
    {
        return;
    }

    listaRam.deleteData(auxNode);
    cout << "\nUsuario eliminado" << endl;
    cout << listaRam.toString() << endl;

}

void MenuUsuarios::write()
{

}

void MenuUsuarios::read()
{

}

void MenuUsuarios::showAllUsers()
{

}

void MenuUsuarios::mainMenu()
{


    cout << "Menu de usuarios" << endl;
    cout << "\n1) Agregar nuevo usuario\n2) Eliminar usuario\n3) Mostrar usuarios\n4) Leer del disco\n5) Escribir nueva lista en el disco" << endl;

}
