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

    if ( tipo == 1)
    {
        type = "admin";
    }
    else
    {
        type = "base";
    }

    nuevoUser.setTipoUsuario(type);

    while (password1 != password2)
    {
        cout << "Escribe tu contraseña:\t";
        fflush(stdin);
        getline(cin, password1);
        getline(cin, password1);

        cout << "Escribe tu contraseña de nuevo:\t";
        fflush(stdin);
        getline(cin, password2);
    }

    nuevoUser.setPassword(password2);

    listaRam.insertData(listaRam.getLastPos(), nuevoUser);

    cout << "Usuario creado con exito" << endl  << listaRam.toString() << endl;

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

    cout << "escribiendo lista de usuarios" << endl;
    listaRam.write();
}

void MenuUsuarios::read()
{
    cout << "Leyendo lista de usuarios" << endl;
    listaRam.read();
}

void MenuUsuarios::showAllUsers()
{
cout << "Lista de usuarios" << endl<< endl<< endl;
cout << listaRam.toString() << endl;
}

std::string MenuUsuarios::findUser(std::string name, std::string pass)
{

    Usuario auxUser;
    auxUser.setNombre(name);
    auxUser.setPassword(pass);

    NodoUsuario* auxNodo;

   auxNodo = listaRam.validateUser(auxUser);

    if (auxNodo != nullptr)
    {
        string tipoUsuario;
        tipoUsuario = auxNodo->getData().getTipoUsuario();
        return tipoUsuario;
    } else
    {
        return "invalido";
    }
}

void MenuUsuarios::mainMenu()
{
char opc('X');

    while (opc != 's')
    {
        cout << "Menu de usuarios" << endl;
        cout << "\n1) Agregar nuevo usuario\n2) Eliminar usuario\n3) Mostrar usuarios\n4) Leer del disco\n5) Escribir nueva lista en el disco\n\ns) salir." << endl;
        cout << "Elige la opcion que deseas:\t";
        fflush(stdin);
        cin >> opc;

        switch (opc)
        {
            case '1':
            {
                addUser();
                break;
            }

            case '2':
            {
                deleteUser();
                break;
            }

            case '3':
            {
                showAllUsers();
                break;
            }

            case '4':
            {
                read();
                break;
            }

            case '5':
            {
                write();
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
