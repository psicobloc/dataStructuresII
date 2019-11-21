
#include "Usuario.h"

using namespace std;

Usuario::Usuario() : tipoUsuario("base")
{}

void Usuario::setNombre(std::string name)
{
nombre = name;
}

void Usuario::setTipoUsuario(std::string type)
{
tipoUsuario = type;
}

void Usuario::setPassword(std::string pass)
{
    string hashedP;

    hashedP = hashPass(pass);
    password = hashedP;
}

std::string Usuario::getName()
{
    return nombre;
}

std::string Usuario::getTipoUsuario()
{
    return tipoUsuario;
}

std::string Usuario::getPassword()
{
    return password;
}

std::string Usuario::toString()
{
    string myStr("Tipo de usuario:\t");
    myStr += tipoUsuario;
    myStr += "\tNombre:\t";
    myStr += nombre;

    return myStr;
}

std::string Usuario::hashPass(std::string plainPass)
{
    //todo comprobar funcionamiento.
    ///hashing algorithm

    unsigned char digest[SHA256_DIGEST_LENGTH];
    char str[plainPass.length()];
    sprintf(str,plainPass.c_str()); /// comprobar conversion de strings a char array.

    SHA256((unsigned char*)&str, strlen(str), (unsigned char*)&digest);

    char mdString[SHA256_DIGEST_LENGTH*2+1];

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    printf("SHA256 digest: %s\n", mdString);

    string result(mdString);

    return  result;
}
