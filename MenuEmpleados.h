// Created by Hugo.

#ifndef ENTREGABLE1_MENUEMPLEADOS_H
#define ENTREGABLE1_MENUEMPLEADOS_H

#include "Empleado.h"
#include "MenuOrdenCompra.h"

class MenuEmpleados {
private:

    long int searchIndex(std::string codigoEmpleado); //recibe un codigo de empleado, busca en index y regresa el empleado recuperado de empleados.txt
    /// searchIndex busca en el index y en empleados.txt

    void agregarNuevoEmpleado();
    void mostrarEmpleado(std::string codigoEmpleado);
    void mostrarTodos();
    void eliminarEmpleado(std::string codigoEmpleado);
    void modificarEmpleado();

public:
    MenuEmpleados();


    void mainMenu();

};


#endif //ENTREGABLE1_MENUEMPLEADOS_H
