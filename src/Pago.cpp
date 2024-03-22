#include "Pago.h"

Pago::Pago(Fecha* _fechaPago, float _montoPago)
{
    this -> fechaPago = _fechaPago;
    this -> montoPago = _montoPago;
}
Fecha* Pago::getFechaPago(){
    return this -> fechaPago;
}
float Pago::getMontoPago(){
    return this -> montoPago;
}

Pago::~Pago()
{
    //dtor
}
