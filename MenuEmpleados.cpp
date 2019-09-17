// Created by Hugo.

#include "MenuEmpleados.h"
using namespace std;

long int MenuEmpleados::searchIndex(std::string codigoEmpleado) {


    string archivoEmpleados("empleados.txt"), archivoIndice("indiceEmpleados.txt");
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


    string archivoEmpleados("empleados.txt"), archivoIndice("indiceEmpleados.txt");
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
    string archivoEmpleados("empleados.txt"), archivoIndice("indiceEmpleados.txt");
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

//        if(codigoAnterior == codigoNuevo)
//        {
//            cout << "algo anda mal, menu empleados, mostrar todos" << endl;
//        }

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

    string archivoEmpleados("empleados.txt"), archivoIndice("indiceEmpleados.txt"), indiceTemporal("temporalI.txt"), empleadosTemporal("temporalE.txt");
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    char nombreE[40], puestoE[30], codigoE[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;
    long int nuevaDireccion;

    ifstream leerI(archivoIndice, ios::in);
    ifstream leerEmpleado(archivoEmpleados, ios::in);

    ofstream escribirI_temp(indiceTemporal);
    ofstream escribirE_temp(empleadosTemporal);

    while(!leerI.eof()) {

        ///leer indice

        leerI.read((char *) &codigo, sizeof(codigo));
        codigoNuevo = codigo;
        leerI.read((char *) &direccion, sizeof(direccion));

        ///leer empleados

        leerEmpleado.seekg(direccion);
        leerEmpleado.read((char*)& codigoE, sizeof(codigoE));

        leerEmpleado.read((char*)& nombreE, sizeof(nombreE));
        //nombreEmpleado = nombreE;

        leerEmpleado.read((char*)& puestoE, sizeof(puestoE));
       // puestoEmpleado = puestoE;

        if (codigoNuevo == codigoAnterior) { // si llega al final y lee el ultimo dos veces, se rompe
            break;
        }

        codigoAnterior = codigoNuevo;

        if (codigoNuevo != codigoEmpleado) { // si llegamos al registro rompemos

            ///escribir indice
            direccion = escribirE_temp.tellp();
            escribirI_temp.write((char*)& codigo, sizeof(codigo));
            escribirI_temp.write((char*)& direccion, sizeof(direccion));

            ///escribir empleados

            escribirE_temp.write((char*)& codigoE, sizeof(codigoE));
            escribirE_temp.write((char*)& nombreE, sizeof(nombreE));
            escribirE_temp.write((char*)& puestoE, sizeof(puestoE));
        }
    }

    leerEmpleado.close();
    leerI.close();
    escribirE_temp.close();
    escribirI_temp.close();
    ///cerrar todos los archivos

    remove("empleados.txt");
    rename("temporalE.txt", "empleados.txt");
    remove("indiceEmpleados.txt");
    rename("temporalI.txt", "indiceEmpleados.txt");
}

void MenuEmpleados::modificarEmpleado(string codigoEmpleado) {

    string nombreEmpleadoModificado;
    string puestoEmpleadoModificado;

    cout << "modificar emplead@s: " << endl << endl;
    cout << "Escribe el nuevo nombre:" << endl;
    fflush(stdin);
    //4
    // getline(cin, nombreEmpleadoModificado);
    getline(cin, nombreEmpleadoModificado);
    cout << "Escribe el nuevo puesto" << endl;
    fflush(stdin);
    getline(cin, puestoEmpleadoModificado);


    string archivoEmpleados("empleados.txt"), archivoIndice("indiceEmpleados.txt"), indiceTemporal("temporalI.txt"), empleadosTemporal("temporalE.txt");
    string codigoEmpleadoAux, nombreEmpleado, puestoEmpleado;
    char nombre[40], puesto[30], codigo[30];
    char nombreMod[40], puestoMod[30], codigoMod[30];
    char nombreE[40], puestoE[30], codigoE[30];
    string codigoAnterior, codigoNuevo;
    long int direccion;
    long int nuevaDireccion;

    ifstream leerI(archivoIndice, ios::in);
    ifstream leerEmpleado(archivoEmpleados, ios::in);

    ofstream escribirI_temp(indiceTemporal);
    ofstream escribirE_temp(empleadosTemporal);

    while(!leerI.eof()) {

        ///leer indice

        leerI.read((char *) &codigo, sizeof(codigo));
        leerI.read((char *) &direccion, sizeof(direccion));

        ///leer empleados

        leerEmpleado.seekg(direccion);
        leerEmpleado.read((char*)& codigoE, sizeof(codigoE));
        codigoNuevo = codigoE;

        leerEmpleado.read((char*)& nombreE, sizeof(nombreE));
        //nombreEmpleado = nombreE;

        leerEmpleado.read((char*)& puestoE, sizeof(puestoE));
        // puestoEmpleado = puestoE;

        if (codigoNuevo == codigoAnterior) { // si llega al final y lee el ultimo dos veces, se rompe
            break;
        }

        codigoAnterior = codigoNuevo;

        if (codigoNuevo != codigoEmpleado) { // si llegamos al registro rompemos

            ///escribir indice
            direccion = escribirE_temp.tellp();
            escribirI_temp.write((char*)& codigo, sizeof(codigo));
            escribirI_temp.write((char*)& direccion, sizeof(direccion));

            ///escribir empleados

            escribirE_temp.write((char*)& codigoE, sizeof(codigoE));
            escribirE_temp.write((char*)& nombreE, sizeof(nombreE));
            escribirE_temp.write((char*)& puestoE, sizeof(puestoE));
        }
        else
        {
            ///escribir indice
            direccion = escribirE_temp.tellp();
            escribirI_temp.write((char*)& codigo, sizeof(codigo));
            escribirI_temp.write((char*)& direccion, sizeof(direccion));

            ///escribir empleados
            strcpy(codigoMod, codigoNuevo.c_str());
            strcpy(nombreMod, nombreEmpleadoModificado.c_str());
            strcpy(puestoMod, puestoEmpleadoModificado.c_str());

            escribirE_temp.write((char*)& codigoMod, sizeof(codigoMod));
            escribirE_temp.write((char*)& nombreMod, sizeof(nombreMod));
            escribirE_temp.write((char*)& puestoMod, sizeof(puestoMod));

        }
    }

    leerEmpleado.close();
    leerI.close();
    escribirE_temp.close();
    escribirI_temp.close();
    ///cerrar todos los archivos

    remove("empleados.txt");
    rename("temporalE.txt", "empleados.txt");
    remove("indiceEmpleados.txt");
    rename("temporalI.txt", "indiceEmpleados.txt");

}

MenuEmpleados::MenuEmpleados() {

}

void MenuEmpleados::mainMenu() {

    char opc('x');
    string codigoEmp("");

    while (opc != 's')
    {
        system("cls");
        system("cls");
        cout << "Elija la opcion que desea:\n1) crear empleado\n2) eliminar empleado\n3) modificar empleado\n4) mostrar empleados\n5) buscar empleado\ns) salir"<<endl<<endl;
        fflush(stdin);
        cin>>opc;

        switch(opc)
        {
            case '1':
            {
                agregarNuevoEmpleado();
                break;
            }

            case '2':
            {
                cout << "Escribe el codigo del empleado por favor\n" << endl;
                fflush(stdin);
                getline(cin, codigoEmp);
                getline(cin, codigoEmp);
                eliminarEmpleado(codigoEmp);
                break;
            }
            case '3':
            {
                cout << "Escribe el codigo del empleado por favor\n" << endl;
                fflush(stdin);
                getline(cin, codigoEmp);
                getline(cin, codigoEmp);
                modificarEmpleado(codigoEmp);
                break;
            }
            case '4':
            {
                mostrarTodos();
                break;
            }
            case '5':
            {
                cout << "Escribe el codigo del empleado por favor\n" << endl;
                fflush(stdin);
                getline(cin, codigoEmp);
                getline(cin, codigoEmp);
                mostrarEmpleado(codigoEmp);
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
