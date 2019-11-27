// Created by Hugo.

#ifndef ENTREGABLE1_MENUEMPLEADOS_H
#define ENTREGABLE1_MENUEMPLEADOS_H

#include "Empleado.h"
#include "MenuOrdenCompra.h"

class MenuEmpleados {
private:
    /// searchIndex busca en el index y en empleados.txt

public:
    MenuEmpleados();


    void mainMenu();

    void agregarNuevoEmpleado();
    void mostrarEmpleado(std::string codigoEmpleado);
    void mostrarTodos();
    void eliminarEmpleado(std::string codigoEmpleado);
    void modificarEmpleado(std::string codigoEmpleado);

    long int searchIndex(std::string codigoEmpleado); //recibe un codigo de empleado, busca en index y regresa el empleado recuperado de empleados.txt



};


#endif //ENTREGABLE1_MENUEMPLEADOS_H
