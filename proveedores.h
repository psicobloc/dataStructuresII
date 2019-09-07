// Created by hugo on 23/08/19.
#ifndef ENTREGABLE1_PROVEEDORES_H
#define ENTREGABLE1_PROVEEDORES_H

#include <string>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

class Proveedor{

private:
    std::string name;
    std::string phone;
    std::string code;
    std::string address;

public:
    Proveedor();
    Proveedor(Proveedor&);

    void setName(std::string& nombre);
    void setPhone(std::string& tel);
    void setCode(std::string& codigo);
    void setAddrs(std::string& dir);

    std::string getName();
    std::string getPhone();
    std::string getCode();
    std::string getAddress();

    Proveedor& operator = (Proveedor&);
    bool operator == (Proveedor&);
    bool operator != (Proveedor&);
    bool operator <= (Proveedor&);
    bool operator < (Proveedor&);
    bool operator >= (Proveedor&);
    bool operator > (Proveedor&);

    ///hace falta toString.
    std::string toString();
    std::string toStringComas();//name,phone,code,address,


    friend std::istream& operator >> (std::istream&, Proveedor&);
    friend std::ostream& operator << (std::ostream&, Proveedor&);
};

#endif //ENTREGABLE1_PROVEEDORES_H
