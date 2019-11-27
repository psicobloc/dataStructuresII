// Created by Hugo.

#include "MenuClientes.h"

using namespace std;

///@escritura codigo[50], nombre[50], estado[50], direccion[50], RFC[13], tipoC[10]

MenuClientes::MenuClientes() : ListaClientesRAM()
{
    //ListaClientesRAM.deleteAll();
    if (ListaClientesRAM.isEmpty())
    {
        cout << "constructor menu clientes lista empty" << endl;
    }
}

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
    string archivoClientes("clientes.txt");
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

    cout << "Creación de Clientes\n\nEscribe el Codigo del cliente"
         << endl; //todo validar codigos, o hacer una funcion que asigen codigos aleatorios y los valide contra la lista recien leida
    fflush(stdin);
    getline(cin, codCliente);
    getline(cin, codCliente);
    auxCliente.setCodigoCliente(codCliente);

    cout << "Escribe el nombre del cliente:\t" << endl;
    fflush(stdin);
    getline(cin, myStr);
    //getline(cin, nomCliente);
    auxCliente.setName(myStr);

    cout << "Escribe el nombre de estado" << endl;
    fflush(stdin);
    getline(cin, nomEdo);
    auxCliente.setEstado(nomEdo);

    cout << "Escribe el resto de la direccion del cliente" << endl;
    fflush(stdin);
    getline(cin, myStr);
    auxCliente.setDireccion(myStr);

    cout << "Escribe el RFC del cliente" << endl;
    fflush(stdin);
    getline(cin, myStr);
    auxCliente.setRfc(myStr);

    cout << "Escribe el tipo de cliente que es " << auxCliente.getName() << " (Mayoreo/Menudeo)" << endl;
    fflush(stdin);
    getline(cin, myStr);
    auxCliente.setTipoCliente(myStr);

    char auxChar[50];
    strcpy(auxChar, auxCliente.getCodigoCliente().c_str());

    if (invertidaRAM.isListaEdosEmpty())
    {
        invertidaRAM.crearEstado(nomEdo, codCliente); // porque aqui hacemos 2 veces la creacion?
    }
    invertidaRAM.crearEstado(nomEdo, codCliente);

    ///insertar a listaClientesRam

    ///escribir indice
    ofstream escrIndex(inde, ios::app);
    escrIndex.write((char *) &auxChar, sizeof auxChar); //escribir el codigo
    escrIndex.write((char *) &posInicial, sizeof posInicial); //escribir la posición donde escribiremos el registro
    escrIndex.close();

    ofstream escribirCliente(archivoClientes, ios::app);
    escribirCliente.seekp(posInicial);

    ///escribir cliente
    escribirCliente.write((char *) &auxChar, sizeof auxChar);

    char nam[50];
    strcpy(nam, auxCliente.getName().c_str());
    escribirCliente.write((char *) &nam, sizeof nam);

    char estado[50];
    strcpy(estado, auxCliente.getEstado().c_str());
    escribirCliente.write((char *) &estado, sizeof estado);

    char direccion[50];
    strcpy(direccion, auxCliente.getDireccion().c_str());
    escribirCliente.write((char *) &direccion, sizeof direccion);

    char rfc[13];
    strcpy(rfc, auxCliente.getRfc().c_str());
    escribirCliente.write((char *) &rfc, sizeof rfc);

    char tipoC[10];
    strcpy(tipoC, auxCliente.getTipoCliente().c_str());
    escribirCliente.write((char *) &tipoC, sizeof tipoC);

    escribirCliente.close();
}

void MenuClientes::show()
{
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    long int start;
    Cliente auxCliente;
    string a("");
    auxCliente.setCodigoCliente(a);

    string archivoInd("indexInv.txt");
    string archivoClientes("clientes.txt");

    ifstream leerI(archivoInd, ios::in);
    ifstream leerCliente(archivoClientes, ios::in);

    while (!leerCliente.eof())
    {
        leerI.read((char *) &codigo, sizeof codigo);
        leerI.read((char *) &start, sizeof start);

        /// /// /// /// /// /// /// /// /// /// /// /// ///

        leerCliente.seekg(start);
        leerCliente.read((char *) &codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
            break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerCliente.read((char *) &nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerCliente.read((char *) &estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerCliente.read((char *) &direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerCliente.read((char *) &rfc, sizeof rfc);
        string rfcStr(rfc);
        auxCliente.setRfc(rfcStr);

        leerCliente.read((char *) &tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        cout << auxCliente.toString() << endl;
    }
    leerI.close();
    leerCliente.close();
}

void MenuClientes::update()
{
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    string nameStr, stateStr, addStr, rfcStr, typeStr;
    long int start, posInicial;
    Cliente auxCliente, clienteModificar;
    string a("");
    auxCliente.setCodigoCliente(a);
    string codigoModificar;
    bool bandera(false);
    string archivoInd("indexInv.txt");
    string archivoClientes("clientes.txt");
    string indTemporal("tempi.txt");
    string clienteTemp("tempclnt.txt");

    cout << "Ingrese el codigo del cliente que desea modificar" << endl;
    fflush(stdin);
    getline(cin, codigoModificar);
    getline(cin, codigoModificar);

    ifstream leerIndex(archivoInd, ios::in);

    while (!leerIndex.eof())
    {
        leerIndex.read((char *) &codigo, sizeof codigo);
        leerIndex.read((char *) &start, sizeof start);

        string codigoLeido(codigo);

        if (codigoLeido == codigoModificar)
        {
            bandera = true;
            break;
        }
    }

    leerIndex.close();

    if (!bandera)
    {
        cout << "No se encontro el codigo en la lista..." << endl;
        return;
    }
    string codigoMod(codigo);
    clienteModificar.setCodigoCliente(codigoMod);

    //estaria bien imprimir el cliente
    cout << "Escribe el nuevo nombre del cliente:\t" << endl;
    fflush(stdin);
    getline(cin, nameStr);
    clienteModificar.setName(nameStr);

    cout << "Escribe el nombre del nuevo estado" << endl;
    fflush(stdin);
    getline(cin, stateStr);
    clienteModificar.setEstado(stateStr);

    cout << "Escribe el resto de la direccion del cliente" << endl;
    fflush(stdin);
    getline(cin, addStr);
    clienteModificar.setDireccion(addStr);

    cout << "Escribe el nuevo RFC del cliente" << endl;
    fflush(stdin);
    getline(cin, rfcStr);
    clienteModificar.setRfc(rfcStr);

    cout << "Escribe el nuevo tipo de cliente " << auxCliente.getName() << " (Mayoreo/Menudeo)" << endl;
    fflush(stdin);
    getline(cin, typeStr);
    clienteModificar.setTipoCliente(typeStr);

    //modificacion
    ifstream leerInd(archivoInd, ios::in);
    ifstream leerClientes(archivoClientes, ios::in);
    ofstream escrindexTemp(indTemporal, ios::app);
    ofstream escribirClientesTemp(clienteTemp, ios::app);

    while (!leerInd.eof())
    {
        //leer indice
        leerInd.read((char *) &codigo, sizeof codigo);
        leerInd.read((char *) &start, sizeof start);

        //leer de clientes.txt
        leerClientes.seekg(start);
        leerClientes.read((char *) &codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
            break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerClientes.read((char *) &nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerClientes.read((char *) &estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerClientes.read((char *) &direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerClientes.read((char *) &rfc, sizeof rfc);
        string rfcString(rfc);
        auxCliente.setRfc(rfcString);

        leerClientes.read((char *) &tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        //crear nuevo indice

        posInicial = escribirClientesTemp.tellp();
        escrindexTemp.write((char *) &codigo, sizeof codigo);
        escrindexTemp.write((char *) &posInicial, sizeof posInicial);

        if (codigoMod != codigoStr) //copiar del archivo
        {
            escribirClientesTemp.write((char *) &codigo, sizeof codigo);

            char nam[50];
            strcpy(nam, auxCliente.getName().c_str());
            escribirClientesTemp.write((char *) &nam, sizeof nam);


            strcpy(estado, auxCliente.getEstado().c_str());
            escribirClientesTemp.write((char *) &estado, sizeof estado);


            strcpy(direccion, auxCliente.getDireccion().c_str());
            escribirClientesTemp.write((char *) &direccion, sizeof direccion);


            strcpy(rfc, auxCliente.getRfc().c_str());
            escribirClientesTemp.write((char *) &rfc, sizeof rfc);


            strcpy(tipoC, auxCliente.getTipoCliente().c_str());
            escribirClientesTemp.write((char *) &tipoC, sizeof tipoC);

        } else //escribir nuevo registro
        {
            escribirClientesTemp.write((char *) &codigo, sizeof codigo);

            char namMod[50];
            strcpy(namMod, clienteModificar.getName().c_str());
            escribirClientesTemp.write((char *) &namMod, sizeof namMod);

            char estadoMod[50];
            strcpy(estadoMod, clienteModificar.getEstado().c_str());
            escribirClientesTemp.write((char *) &estadoMod, sizeof estadoMod);

            char direccionMod[50];
            strcpy(direccionMod, clienteModificar.getDireccion().c_str());
            escribirClientesTemp.write((char *) &direccionMod, sizeof direccionMod);

            char rfcMod[13];
            strcpy(rfcMod, clienteModificar.getRfc().c_str());
            escribirClientesTemp.write((char *) &rfcMod, sizeof rfcMod);

            char tipoCMod[10];
            strcpy(tipoCMod, clienteModificar.getTipoCliente().c_str());
            escribirClientesTemp.write((char *) &tipoCMod, sizeof tipoCMod);

        }
    }

    leerClientes.close();
    leerInd.close();
    escribirClientesTemp.close();
    escrindexTemp.close();

    remove("clientes.txt");
    rename("tempclnt.txt", "clientes.txt");
    remove("indexInv.txt");
    rename("tempi.txt", "indexInv.txt");

    cargarLista();
}

void MenuClientes::deleteC()
{
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    string nameStr, stateStr, addStr, rfcStr, typeStr;
    long int start, posInicial;
    Cliente auxCliente, clienteModificar;
    string a("");
    auxCliente.setCodigoCliente(a);
    string codigoEliminar;
    bool bandera(false);
    string archivoInd("indexInv.txt");
    string archivoClientes("clientes.txt");
    string indTemporal("tempi.txt");
    string clienteTemp("tempclnt.txt");

    cout << "Ingrese el codigo del cliente que desea eliminar" << endl;
    fflush(stdin);
    getline(cin, codigoEliminar);
    getline(cin, codigoEliminar);

    ifstream leerIndex(archivoInd, ios::in);

    while (!leerIndex.eof())
    {
        leerIndex.read((char *) &codigo, sizeof codigo);
        leerIndex.read((char *) &start, sizeof start);

        string codigoLeido(codigo);

        if (codigoLeido == codigoEliminar)
        {
            bandera = true;
            break;
        }
    }

leerIndex.close();

    if(!bandera)
    {
        cout<<"No se encontro el codigo en la lista..."<<endl;
        return;
    }

    //eliminacion
    ifstream leerClientes(archivoClientes,ios::in);
    ifstream leerInd(archivoInd,ios::in);
    ofstream escribirClientesTemp(clienteTemp,ios::out);
    ofstream escrindexTemp(indTemporal,ios::app);

    while (!leerInd.eof())
    {
        //leer indice
        leerInd.read((char *) &codigo, sizeof codigo);
        leerInd.read((char *) &start, sizeof start);

        //leer de clientes.txt
        leerClientes.seekg(start);
        leerClientes.read((char *) &codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
            break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerClientes.read((char *) &nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerClientes.read((char *) &estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerClientes.read((char *) &direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerClientes.read((char *) &rfc, sizeof rfc);
        string rfcString(rfc);
        auxCliente.setRfc(rfcString);

        leerClientes.read((char *) &tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        //crear nuevo indice

        posInicial = escribirClientesTemp.tellp();
        escrindexTemp.write((char *) &codigo, sizeof codigo);
        escrindexTemp.write((char *) &posInicial, sizeof posInicial);

        if (codigoEliminar != codigo) //copiar del archivo
        {
            escribirClientesTemp.write((char *) &codigo, sizeof codigo);

            char nam[50];
            strcpy(nam, auxCliente.getName().c_str());
            escribirClientesTemp.write((char *) &nam, sizeof nam);


            strcpy(estado, auxCliente.getEstado().c_str());
            escribirClientesTemp.write((char *) &estado, sizeof estado);


            strcpy(direccion, auxCliente.getDireccion().c_str());
            escribirClientesTemp.write((char *) &direccion, sizeof direccion);


            strcpy(rfc, auxCliente.getRfc().c_str());
            escribirClientesTemp.write((char *) &rfc, sizeof rfc);


            strcpy(tipoC, auxCliente.getTipoCliente().c_str());
            escribirClientesTemp.write((char *) &tipoC, sizeof tipoC);

        }

    }

    leerClientes.close();
    leerInd.close();
    escribirClientesTemp.close();
    escrindexTemp.close();

    remove("clientes.txt");
    rename("tempclnt.txt", "clientes.txt");
    remove("indexInv.txt");
    rename("tempi.txt", "indexInv.txt");

    cargarLista();

}

void MenuClientes::mainMenu()
{

    char opc('x');
    string edo("");


    while (opc != 's')
    {
        //system("cls");
        cout << endl << "menu principal" << endl
             << "1)agregar cliente\n2)mostrar clientes\n3)mostrar clientes por estado\n4)cargar lista\n5)Mostrar lista invertida\n6)Modificar Clientes\n7)Eliminar clientes\n8)Mostrar lista normal\ns)salir"
             << endl;
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
                mostrarLlistaInvertida();
                break;
            }

            case '6':
            {
                update();
                break;
            }

            case '7':
            {
                deleteC();
                break;
            }

            case '8':
            {
                mostrarLista();
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

    if (invertidaRAM.getAnclaEstados() != nullptr)
    {
        invertidaRAM.deleteAll(); //limpiamos las listas antes de leer del archivo
    }

    ifstream leerI(ind, ios::in);
    ifstream leerCliente(clnt, ios::in);

    while (!leerCliente.eof()) //&& !leerI.eof()
    {
        //leer indice
        leerI.read((char *) &codigo, sizeof codigo);
        leerI.read((char *) &start, sizeof start);

        //leer cliente
        leerCliente.seekg(start);
        leerCliente.read((char *) &codigo, sizeof codigo);
        string codigoStr(codigo);

        if (auxCliente.getCodigoCliente() == codigoStr) //criterio de paro
        {
            break;
        }

        auxCliente.setCodigoCliente(codigoStr);

        leerCliente.read((char *) &nombre, sizeof nombre);
        string nombreStr(nombre);
        auxCliente.setName(nombreStr);

        leerCliente.read((char *) &estado, sizeof estado);
        string estadoStr(estado);
        auxCliente.setEstado(estadoStr);

        leerCliente.read((char *) &direccion, sizeof direccion);
        string direccionStr(direccion);
        auxCliente.setDireccion(direccionStr);

        leerCliente.read((char *) &rfc, sizeof rfc);
        string rfcStr(rfc);
        auxCliente.setRfc(rfcStr);

        leerCliente.read((char *) &tipoC, sizeof tipoC);
        string tipoCStr(tipoC);
        auxCliente.setTipoCliente(tipoCStr);

        ListaClientesRAM.insertData(ListaClientesRAM.getLastPos(), auxCliente);

        //cout << getListaClientesRam().toString() << endl;
        if (invertidaRAM.isListaEdosEmpty())
        {
            invertidaRAM.crearEstado(estadoStr, codigoStr);

        }
        invertidaRAM.crearEstado(estadoStr, codigoStr);
        cout << "insertando a lista invertida" << endl;
    }

    leerCliente.close();
    leerI.close();
}

void MenuClientes::mostrarLista()
{
    cout << endl << endl << endl << ListaClientesRAM.toString() << endl;
}

void MenuClientes::mostrarClientesPorEdo(std::string edo)
{
    string ind("indexInv.txt"), clnt("clientes.txt");
    string codigoStr(""), codigoAnt("");
    NodoInv *auxEdo(invertidaRAM.findEdo(edo));
    char codigo[50], nombre[50], estado[50], direccion[50], rfc[13], tipoC[10];
    long int start;
    Cliente auxCliente;

    if (auxEdo == nullptr)
    {
        cout << "problema con la busqueda del estado, no existe" << endl;
        system("pause");
        return;
    }

    NodoInv *auxNodoInv(auxEdo->getSecundario());

    cout << invertidaRAM.estadosToString() << endl << endl;

    cout << endl << "Estado:\t" << edo << endl << "Clientes:" << endl;
    cout << invertidaRAM.clientesToString(edo) << endl << endl;

    ifstream leerI(ind);
    ifstream leerClientes(clnt);

    while (auxNodoInv != nullptr)
    {
        while (auxNodoInv->getLLave() !=
               codigoStr) // leemos los registros hasta encontrar el codigo que es igual al nodo.
        {
            leerI.read((char *) &codigo, sizeof codigo);
            leerI.read((char *) &start, sizeof start);
            codigoStr = codigo;
        }

        //leer cliente
        leerClientes.seekg(start);
        leerClientes.read((char *) &codigo, sizeof codigo);
        codigoStr = codigo;
        if (codigoAnt == codigoStr)
        {
            break;
        }
        leerClientes.read((char *) &nombre, sizeof nombre);
        leerClientes.read((char *) &estado, sizeof estado);
        leerClientes.read((char *) &direccion, sizeof direccion);
        leerClientes.read((char *) &rfc, sizeof rfc);
        leerClientes.read((char *) &tipoC, sizeof tipoC);

        //convertir a string
        string nombreStr(nombre);
        string estadoStr(estado);
        string direccionStr(direccion);
        string rfcStr(rfc);
        string tipocStr(tipoC);

        //crear cliente
        auxCliente.setName(nombreStr);
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
    string llave("");

    NodoInv *auxEdo(invertidaRAM.getAnclaEstados());
    NodoInv *sec(nullptr);
    NodoInv *prim(nullptr);

    cout << "Estados" << endl;

    while (auxEdo != nullptr)
    {
        auto a = auxEdo;
        auto sigSec = auxEdo->getSecundario();
        auto sigPrim = auxEdo->getPrimario();
        llave = auxEdo->getLLave();

        cout << "Nombre de estado:  " << llave << "   Direccion:  " << a << "  Sig. Edo.  " << sigPrim
             << " Primer cliente: " << sigSec << endl;
        auxEdo = auxEdo->getPrimario();
    }

    cout << endl << endl;

    NodoInv *auxCliente(invertidaRAM.getAnclaClientes());

    while (auxCliente != nullptr)
    {
        auto actual = auxCliente;
        auto sigSecClt = auxCliente->getSecundario();
        auto sigPrimClt = auxCliente->getPrimario();
        llave = auxCliente->getLLave();

        cout << "Clave de cliente:  " << llave << "   Direccion:  " << actual << "  Sig. Cliente del estado  "
             << sigSecClt << " Siguiente cliente de la lista: " << sigPrimClt << endl;
        auxCliente = auxCliente->getPrimario();
    }
}

ListaClientes& MenuClientes::getListaClientesRam()
{
    return ListaClientesRAM;
}
