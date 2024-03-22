#include "Cliente.h"
#include <string.h>

Cliente::Cliente(int _idCliente, string _nombre, string _apellido)
{
    this -> idCliente = _idCliente;
    this -> nombre = _nombre;
    this -> apellido = _apellido;
}
int Cliente::getIdCliente(){
    return this -> idCliente;
}
string Cliente::getNombre(){
    return this -> nombre;
}
string Cliente::getApellido(){
    return this -> apellido;
}

Cliente::~Cliente()
{
    //dtor
}
