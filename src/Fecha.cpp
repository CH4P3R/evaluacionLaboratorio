#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int _dia, int _mes, int _year)
{
    this -> dia = _dia;
    this -> mes = _mes;
    this -> year = _year;
}
void Fecha::mostrarFecha(){
    cout << this -> dia << "/" << this -> mes << "/" << this -> year << endl;
}

Fecha::~Fecha()
{
    //dtor
}
