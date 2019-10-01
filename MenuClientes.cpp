// Created by Hugo.

#include "MenuClientes.h"

using namespace std;

///@escritura codigo[50], nombre[50], estado[50], direccion[50], RFC[13], tipoC[10]

MenuClientes::MenuClientes() {}

void MenuClientes::setClienteRam(Cliente clnt)
{
    clienteRAM = clnt;
}

Cliente MenuClientes::getClienteRam()
{
    return clienteRAM;
}

void MenuClientes::create()
{
    Cliente auxCliente;
    string myStr("");
    string codCliente("");
    string nomEdo("");
    string archivoClientes("clientes.txt");  //municipios.txt
    string inde("indexInv.txt");             //index.txt

//posición inicial para escribir en clientes.txt

    long int posInicial;
    ifstream posIn(archivoClientes, ios::ate);
    posInicial = posIn.tellg();
    if (posInicial == -1)
    {
        posInicial = 0;
    }
    posIn.close();

//Creacion de cliente

    cout << "Creación de Clientes\n\nEscribe el Codigo del cliente" << endl; //todo validar codigos, o hacer una funcion que asigen codigos aleatorios y los valide contra la lista recien leida
    fflush(stdin);
    getline(cin,codCliente);
    getline(cin,codCliente);
    auxCliente.setCodigoCliente(codCliente);

    cout << "Escribe el nombre del cliente:\t" << endl;
    fflush(stdin);
    getline(cin, myStr);
    //getline(cin, nomCliente);
    auxCliente.setName(myStr);

    cout << "Escribe el nombre de estado" << endl;
    fflush(stdin);
    getline(cin,nomEdo);
    auxCliente.setEstado(nomEdo);

    cout << "Escribe el resto de la direccion del cliente" << endl;
    fflush(stdin);
    getline(cin,myStr);
    auxCliente.setDireccion(myStr);

    cout << "Escribe el RFC del cliente" << endl;
    fflush(stdin);
    getline(cin,myStr);
    auxCliente.setRfc(myStr);

    cout << "Escribe el tipo de cliente que es " << auxCliente.getName()<< " (Mayoreo/Menudeo)" << endl;
    fflush(stdin);
    getline(cin,myStr);
    auxCliente.setTipoCliente(myStr);

    char auxChar[50];
    strcpy(auxChar,auxCliente.getCodigoCliente().c_str());

    if (invertidaRAM.isListaEdosEmpty())
    {
        invertidaRAM.crearEstado(nomEdo,codCliente); // porque aqui hacemos 2 veces la creacion?
    }
    invertidaRAM.crearEstado(nomEdo,codCliente);

    ///escribir indice
    ofstream escrIndex(inde, ios::app);
    escrIndex.write((char*)& auxChar, sizeof auxChar); //escribir el codigo
    escrIndex.write((char*)& posInicial, sizeof posInicial); //escribir la posición donde escribiremos el registro
    escrIndex.close();

    ofstream escribirCliente(archivoClientes, ios::app);
    escribirCliente.seekp(posInicial);

    ///escribir cliente
    escribirCliente.write((char*)&auxChar, sizeof auxChar);

    char nam[50];
    strcpy(nam,auxCliente.getName().c_str());
    escribirCliente.write((char*)&nam,sizeof nam);

    char estado[50];
    strcpy(estado, auxCliente.getEstado().c_str());
    escribirCliente.write((char*)& estado, sizeof estado);

    char direccion[50];
    strcpy(direccion, auxCliente.getDireccion().c_str());
    escribirCliente.write((char*)& direccion, sizeof direccion);

    char rfc[13];
    strcpy(rfc, auxCliente.getRfc().c_str());
    escribirCliente.write((char*)& rfc, sizeof rfc);

    char tipoC[10];
    strcpy(tipoC, auxCliente.getTipoCliente().c_str());
    escribirCliente.write((char*)& tipoC, sizeof tipoC);

    escribirCliente.close();
}

void MenuClientes::show()
{
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    long int start;
    Cliente auxCliente;
    auxCliente.setCodigoCliente("");

    string archivoInd("indexInv.txt");
    string archivoClientes("clientes.txt");

    ifstream leerI(archivoInd, ios::in);
    ifstream leerCliente(archivoClientes, ios::in);

    while (!leerCliente.eof())
    {
        leerI.read((char*)& codigo, sizeof codigo);
        leerI.read((char*)& start, sizeof start);

        /// /// /// /// /// /// /// /// /// /// /// /// ///

        leerCliente.seekg(start);
        leerCliente.read((char*)& codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
         break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerCliente.read((char*)&nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerCliente.read((char*)& estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerCliente.read((char*)&direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerCliente.read((char*)&rfc, sizeof rfc);
        string rfcStr(rfc);
        auxCliente.setRfc(rfcStr);

        leerCliente.read((char*)&tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        cout << auxCliente.toString() << endl;
    }
    leerI.close();
    leerCliente.close();
}

void MenuClientes::update()
{

}

void MenuClientes::deleteC()
{

}

void MenuClientes::mainMenu()
{

    char opc('x');
    string edo("");


    while (opc != 's')
    {
        system("cls");
        cout << endl  << "menu principal" << endl << "1)agregar cliente\n2)mostrar clientes\n3)mostrar clientes por estado\n4)cargar lista" << endl;
        fflush(stdin);
        cin >> opc;
        //cin >> opc;

        switch (opc)
        {
            case '1':
            {
                create();
                break;
            }

            case '2':
            {
                show();
                break;
            }

            case '3':
            {
                cout << endl << "Escribe el estado:\t";
                fflush(stdin);
                getline(cin, edo);
                getline(cin, edo);
                mostrarClientesPorEdo(edo);
                break;
            }

            case '4':
            {
                cargarLista();
                break;
            }

            case '5':
            {

                break;
            }




            default:
                break;
        }
    }

}

void MenuClientes::cargarLista()
{
    string ind("indexInv.txt"), clnt("clientes.txt");
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    long int start;
    Cliente auxCliente;

    if(invertidaRAM.getAnclaEstados() != nullptr)
    {
        invertidaRAM.deleteAll(); //limpiamos las listas antes de leer del archivo
    }

    if (ListaClientesRAM.isEmpty())
    {
        ListaClientesRAM.deleteAll();
    }

    ifstream leerI(ind, ios::in);
    ifstream leerCliente(clnt, ios::in);

    while (!leerCliente.eof()) //&& !leerI.eof()
    {
        //leer indice
        leerI.read((char*)& codigo, sizeof codigo);
        leerI.read((char*)& start, sizeof start);

        //leer cliente
        leerCliente.seekg(start);
        leerCliente.read((char*)& codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
            break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerCliente.read((char*)&nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerCliente.read((char*)& estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerCliente.read((char*)&direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerCliente.read((char*)&rfc, sizeof rfc);
        string rfcStr(rfc);
        auxCliente.setRfc(rfcStr);

        leerCliente.read((char*)&tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        ListaClientesRAM.insertData(ListaClientesRAM.getLastPos(), auxCliente);

        if (invertidaRAM.isListaEdosEmpty())
        {
            invertidaRAM.crearEstado(estadoStr, codigoStr);
        }
        invertidaRAM.crearEstado(estadoStr, codigoStr);
    }

    leerCliente.close();
    leerI.close();
}

void MenuClientes::mostrarLista()
{
cout << endl << endl << endl << ListaClientesRAM.toString() << endl;
}

void MenuClientes::mostrarClientesPorEdo(std::string edo)///@escritura codigo[50], nombre[50], estado[50], direccion[50], RFC[13], tipoC[10]

{
    string ind("indexInv.txt"), clnt("clientes.txt");
    string codigoStr(""), codigoAnt("");
    NodoInv* auxEdo(invertidaRAM.findEdo(edo));
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    long int start;
    Cliente auxCliente;

    if (auxEdo == nullptr)
    {
        cout << "problema con la busqueda del estado, no existe" << endl;
        system("pause");
        return;
    }

    NodoInv* auxNodoInv(auxEdo->getSecundario());

    cout << invertidaRAM.estadosToString() << endl << endl;

    cout << endl << "Estado:\t" << edo << endl << "Clientes:" << endl;
    cout << invertidaRAM.clientesToString(edo) << endl << endl;

    ifstream leerI(ind);
    ifstream leerClientes(clnt);

    while (auxNodoInv != nullptr)
    {
        while (auxNodoInv->getLLave() != codigoStr) // leemos los registros hasta encontrar el codigo que es igual al nodo.
        {
            leerI.read((char*)& codigo, sizeof codigo);
            leerI.read((char*)& start, sizeof start);
            codigoStr = codigo;
        }

        //leer cliente
        leerClientes.seekg(start);
        leerClientes.read((char*)& codigo, sizeof codigo);
        codigoStr = codigo;
        if (codigoAnt == codigoStr)
        {
            break;
        }
        leerClientes.read((char*)& nombre, sizeof nombre);
        leerClientes.read((char*)& estado, sizeof estado);
        leerClientes.read((char*)& direccion, sizeof direccion);
        leerClientes.read((char*)& rfc, sizeof rfc);
        leerClientes.read((char*)& tipoC, sizeof tipoC);

        //convertir a string
        string nombreStr(nombre);
        string estadoStr(estado);
        string direccionStr(direccion);
        string rfcStr(rfc);
        string tipocStr(tipoC);

        //crear cliente
        auxCliente.setName(nombre);
        auxCliente.setCodigoCliente(codigoStr);
        auxCliente.setEstado(estadoStr);
        auxCliente.setDireccion(direccionStr);
        auxCliente.setRfc(rfcStr);
        auxCliente.setTipoCliente(tipocStr);

        cout << auxCliente.toString() << endl;
        codigoAnt = codigoStr;
        auxNodoInv = auxNodoInv->getSecundario();
    }
    leerClientes.close();
    leerI.close();
}

void MenuClientes::mostrarLlistaInvertida()
{

}
