#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Fecha.h"
#include "Pago.h"
#include "Cliente.h"
#define TAM 5

class Prestamo
{
    public:
        Prestamo();
        Prestamo(int, Cliente*, Fecha*, float);
        int getNumeroPrestamo();
        void setNumeroPrestamo(int);
        Cliente* getCliente();
        void setCliente(Cliente*);
        void setFechaAprobacion(Fecha*);
        Fecha* getFechaAprobacion();
        void setMontoAprobado(float);
        float getMontoAprobado();
        bool hacerPago(Pago*);
        Pago** getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();

        virtual ~Prestamo();

    protected:

    private:
        int numeroPrestamo;
        Cliente* cliente;
        Fecha* fechaAprobacion;
        float montoAprobado;
        Pago* lstPagos[TAM];
        float saldoPendiente;
        int contadorPagos;
};

#endif // PRESTAMO_H
