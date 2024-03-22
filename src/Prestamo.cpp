#include "Prestamo.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"

Prestamo::Prestamo(){
    this->numeroPrestamo = 0;
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contadorPagos = 0;
}

Prestamo::Prestamo(int _numeroPrestamo,Cliente* _cliente, Fecha* _fechaAprobacion, float _montoAprobado ){
    this->numeroPrestamo = _numeroPrestamo;
    this->cliente = _cliente;
    this->fechaAprobacion = _fechaAprobacion;
    this->montoAprobado = _montoAprobado;
    this->saldoPendiente = this->montoAprobado;
    this->contadorPagos = 0;
}

int Prestamo::getNumeroPrestamo(){
    return this->numeroPrestamo;
}

void Prestamo::setNumeroPrestamo(int _numeroPrestamo){
    this->numeroPrestamo = _numeroPrestamo;
}

Cliente* Prestamo::getCliente(){
    return this->cliente;
}

void Prestamo::setCliente(Cliente* _cliente){
    this->cliente = _cliente;
}

void Prestamo::setFechaAprobacion(Fecha* _fechaAprobacion){
    this->fechaAprobacion = _fechaAprobacion;
}

Fecha* Prestamo::getFechaAprobacion(){
    return this->fechaAprobacion;
}

void Prestamo::setMontoAprobado(float _montoAprobado){
    this->montoAprobado = _montoAprobado;
}

float Prestamo::getMontoAprobado(){
    return this->montoAprobado;
}

bool Prestamo::hacerPago(Pago* _hacerPago){
    bool pagoHecho = false;
    if(this->saldoPendiente >= _hacerPago->getMontoPago()){
        this->saldoPendiente = this->saldoPendiente - _hacerPago->getMontoPago();
        this->lstPagos[this->contadorPagos] = _hacerPago;
        this->contadorPagos++;
        pagoHecho = true;
    }
    return pagoHecho;
}

Pago** Prestamo::getLstPagos(){
    return this->lstPagos;
}

float Prestamo::getSaldoPendiente(){
    return this->saldoPendiente;
}

int Prestamo::getContadorPagos(){
    return this->contadorPagos;
}

Prestamo::~Prestamo(){
    //dtor
}
