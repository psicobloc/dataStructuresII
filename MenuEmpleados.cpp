// Created by Hugo.

#include "MenuEmpleados.h"
using namespace std;

long int MenuEmpleados::searchIndex(std::string codigoEmpleado) {


    string archivoEmpleados, archivoIndice;
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;

    ifstream leerI(archivoIndice, ios::in);

    while(!leerI.eof()) {
        leerI.read((char *) &codigo, sizeof(codigo));
        codigoNuevo = codigo;
        leerI.read((char *) &direccion, sizeof(direccion));

        if (codigoNuevo == codigoAnterior) {
            break;
        }

        codigoAnterior = codigoNuevo;

        if (codigoNuevo == codigoEmpleado) {
            leerI.close();
            return  direccion;
            //direccion = la direccion del registro en empleados.txt
        }
    }


    leerI.close();
    return  0;

}

void MenuEmpleados::agregarNuevoEmpleado() {

    Empleado emplRAM;
    string nombreEmpleado, codigoEmpleado, puestoEmpleado;
    string archivoEmpleados("empleados.txt");
    string archivoIndice("indiceEmpleados.txt");

    long int posInicial;

    //leer puntero

    ifstream empleados(archivoEmpleados, ios::ate);
    posInicial = empleados.tellg();
    if(posInicial == -1)
    {
        posInicial = 0;
    }
    empleados.close();

    cout << "Agregar emplead@s: " << endl << endl;
    cout << "Escribe el nombre:" << endl;
    fflush(stdin);
    getline(cin, nombreEmpleado);
    getline(cin, nombreEmpleado);
    cout << "Escribe el codigo de empleado" << endl;
    fflush(stdin);
    getline(cin, codigoEmpleado);
    cout << "Escribe el puesto" << endl;
    fflush(stdin);
    getline(cin, puestoEmpleado);

    cout << "Agregando...\nNombre:\t" << nombreEmpleado << "\tCodigo:\t" << codigoEmpleado << "\tPuesto:\t" << puestoEmpleado<< endl;

    char codigo[30];
    strcpy(codigo, codigoEmpleado.c_str());

    char nombre[40];
    strcpy(nombre, nombreEmpleado.c_str());

    char puesto[30];
    strcpy(puesto,puestoEmpleado.c_str());

    //todo Validar que no exista el codigo dentro del archivo, buscar en todo el indice

    //Escribir indice
    ofstream escrIndex(archivoIndice, ios::app);

    escrIndex.write((char*)& codigo, sizeof(codigo));
    escrIndex.write((char*)& posInicial, sizeof(long int));
    escrIndex.close();

    //Escribir empleado
    ofstream escrEmpleado(archivoEmpleados, ios::app);

    escrEmpleado.seekp(posInicial);
    escrEmpleado.write((char*)& codigo, sizeof(codigo));
    escrEmpleado.write((char*)& nombre, sizeof(nombre));
    escrEmpleado.write((char*)& puesto, sizeof(puesto));
    escrEmpleado.close();
}

void MenuEmpleados::mostrarEmpleado(std::string codigoEmpleado) {


    string archivoEmpleados, archivoIndice;
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;

    ifstream leerI(archivoIndice, ios::in);
    ifstream leerEmpleado(archivoEmpleados, ios::in);

    while(!leerI.eof()) {
        leerI.read((char *) &codigo, sizeof(codigo));
        codigoNuevo = codigo;
        leerI.read((char *) &direccion, sizeof(direccion));

        if (codigoNuevo == codigoAnterior) {
            break;
        }

        codigoAnterior = codigoNuevo;

        if (codigoNuevo == codigoEmpleado) {
            break;
            //direccion = la direccion del registro en empleados.txt
        }
    }

    leerEmpleado.seekg(direccion);
    leerEmpleado.read((char*)& codigo, sizeof(codigo));

    leerEmpleado.read((char*)& nombre, sizeof(nombre));
    nombreEmpleado = nombre;

    leerEmpleado.read((char*)& puesto, sizeof(puesto));
    puestoEmpleado = puesto;

    cout << "Nombre:  " << nombreEmpleado << "\tCodigo: " << codigoNuevo << "\tPuesto:  " << puestoEmpleado << endl;

    leerEmpleado.close();
    leerI.close();
}

void MenuEmpleados::mostrarTodos() {

    Empleado emplRAM;
    string archivoEmpleados, archivoIndice;
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;

    ifstream leerI(archivoIndice, ios::in);
    ifstream leerEmpleado(archivoEmpleados, ios::in);

    cout << "Emplead@s:" << endl << endl;

    while(!leerI.eof())
    {
        leerI.read((char*)& codigo, sizeof(codigo));
        codigoNuevo = codigo;
        leerI.read((char*)& direccion, sizeof(direccion));

        if(codigoNuevo == codigoAnterior)
        {
            break;
        }

        leerEmpleado.seekg(direccion);
        leerEmpleado.read((char*)& codigo, sizeof(codigo));
        codigoAnterior=codigo;

        if(codigoAnterior == codigoNuevo)
        {
            cout << "algo anda mal, menu empleados, mostrar todos" << endl;
        }

        leerEmpleado.read((char*)& nombre, sizeof(nombre));
        nombreEmpleado = nombre;

        leerEmpleado.read((char*)& puesto, sizeof(puesto));
        puestoEmpleado = puesto;

        cout << "Nombre:  " << nombreEmpleado << "\tCodigo: " << codigoNuevo << "\tPuesto:  " << puestoEmpleado << endl;

    }
    leerEmpleado.close();
    leerI.close();
}

void MenuEmpleados::eliminarEmpleado(string codigoEmpleado) {

    string archivoEmpleados, archivoIndice;
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;

    ifstream leerI(archivoIndice, ios::in);
    ifstream leerEmpleado(archivoEmpleados, ios::in);

    while(!leerI.eof()) {
        leerI.read((char *) &codigo, sizeof(codigo));
        codigoNuevo = codigo;
        leerI.read((char *) &direccion, sizeof(direccion));

        if (codigoNuevo == codigoAnterior) {
            break;
        }

        codigoAnterior = codigoNuevo;

        if (codigoNuevo == codigoEmpleado) {
            break;
            //direccion = la direccion del registro en empleados.txt
        }
    }

    leerEmpleado.seekg(direccion);
    leerEmpleado.read((char*)& codigo, sizeof(codigo));

    leerEmpleado.read((char*)& nombre, sizeof(nombre));
    nombreEmpleado = nombre;

    leerEmpleado.read((char*)& puesto, sizeof(puesto));
    puestoEmpleado = puesto;

    cout << "Nombre:  " << nombreEmpleado << "\tCodigo: " << codigoNuevo << "\tPuesto:  " << puestoEmpleado << endl;

    leerEmpleado.close();
    leerI.close();

}

void MenuEmpleados::modificarEmpleado() {

}

MenuEmpleados::MenuEmpleados() {

}

void MenuEmpleados::mainMenu() {

}
