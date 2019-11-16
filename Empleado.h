// Created by Hugo.

#ifndef ENTREGABLE1_EMPLEADO_H
#define ENTREGABLE1_EMPLEADO_H

#include "MenuOrdenCompra.h" //solo para importar librerias

class Empleado {

private:
    std::string nombre;
    std::string codigoEmpleado;
    std::string puesto;

public:
    Empleado();
    Empleado(Empleado& empl);

    void setNombre(std::string name);
    void setCodigoEmpleado(std::string code);
    void setPuesto(std::string p);

    std::string getNombre();
    std::string getCodigoEmpleado();
    std::string getPuesto();

    std::string toString();

    bool operator == (Empleado& emp);
    Empleado& operator = (Empleado& emp);

};

#endif //ENTREGABLE1_EMPLEADO_H