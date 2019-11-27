#include <iostream>
#include "menuProv.h"
#include "menuProd.h"
#include "MenuOrdenCompra.h"
#include "MenuEmpleados.h"
#include "MenuClientes.h"
#include "MenuFacturas.h"
#include "MenuVenta.h"
#include "MenuUsuarios.h"
#include "MenuPrincipal.h"

using namespace std;

int main() {
    string username;
    string password;
    char opcRoot('x');

    string tipoUsuario;

    MenuUsuarios mu;

    mu.read();

    bool loged = false;

    while (loged == false)
    {
        cout << "Escribe el nombre de usuario" << endl;
        fflush(stdin);
        getline(cin, username);

        cout << "Escribe tu contraseña" << endl;
        getline(cin, password);

        tipoUsuario = mu.findUser(username,password);

        if (tipoUsuario != "invalido")
        {
            cout << "Bienvenido Usuario "<< username << endl;
            cout << "Tipo de usuario:\t" << tipoUsuario;
            loged = true;
        } else
        {
            cout << "ingreso incorrecto" << endl;
        }
    }

    MenuPrincipal menuP(tipoUsuario,username);

    if (tipoUsuario == "admin")
    {
        menuP.menuAdministradores();
    } else if (tipoUsuario == "base")
    {
        menuP.menuBase();
    } else if (tipoUsuario == "root")
    {
        while (opcRoot != 's')
        {
            cout << "Menu Root:\n\n1) Menu usuarios\n2) Menu admin\ns) salir" << endl;
            fflush(stdin);
            cin >> opcRoot;

            switch (opcRoot)
            {
                case '1':
                {
                    menuP.menuUsuarios();
                    break;
                }

                case '2':
                {
                    menuP.menuAdministradores();
                    break;
                }

                default:
                    break;
            }
        }
    }
    cout << "\n\n\n\nHasta luego!\n\n" << endl;
}