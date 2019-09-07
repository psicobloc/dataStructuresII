// Created by hugo on 28/08/19.

#ifndef ENTREGABLE1_PRODUCTO_H
#define ENTREGABLE1_PRODUCTO_H

#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>


class Producto {
private:

std::string nombre;
std::string codigo;
std::string precio;
std::string cantidad;

public:
    Producto();
    Producto(Producto&);

    void setName(std::string& name);
    void setCode(std::string& code);
    void setPrice(std::string& price);
    void setAmount(std::string& amo);

    std::string getName();
    std::string getCode();
    std::string getPrice();
    std::string getAmount();

    Producto& operator = (Producto&);
    bool operator == (Producto&);
    bool operator != (Producto&);
    bool operator <= (Producto&);
    bool operator < (Producto&);
    bool operator >= (Producto&);
    bool operator > (Producto&);

    std::string toString();

};


#endif //ENTREGABLE1_PRODUCTO_H
