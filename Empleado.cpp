// Created by Hugo.

#include "Empleado.h"

using namespace std;

Empleado::Empleado()
{

}

Empleado::Empleado(Empleado &empl) : nombre(empl.nombre), codigoEmpleado(empl.codigoEmpleado), puesto(empl.puesto)
{
}

void Empleado::setNombre(std::string name) {
nombre = name;
}

void Empleado::setCodigoEmpleado(std::string code) {
codigoEmpleado = code;
}

void Empleado::setPuesto(std::string p) {
puesto = p;
}

std::string Empleado::getNombre() {
    return nombre;
}

std::string Empleado::getCodigoEmpleado() {
    return codigoEmpleado;
}

std::string Empleado::getPuesto() {
    return puesto;
}

std::string Empleado::toString() {
    string myStr("");

    myStr += "Nombre:  ";
    myStr += nombre;
    myStr += "\tCodigo de empleado:  ";
    myStr += codigoEmpleado;
    myStr += "\tPuesto:  ";
    myStr += puesto;
    //myStr += "\n"

    return myStr;
}

bool Empleado::operator==(Empleado &emp) {
    return codigoEmpleado == emp.codigoEmpleado;
}

Empleado &Empleado::operator=(Empleado &emp) {
    nombre = emp.nombre;
    codigoEmpleado = emp.codigoEmpleado;
    puesto = emp.puesto;

    return  *this; // esta linea parece no ser necesaria??
}

#include "Empleado.h"
