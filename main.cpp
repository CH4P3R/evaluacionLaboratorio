#include <iostream>
#include <stdint.h>
#include "Cliente.h"
#include "Fecha.h"
#include "Prestamo.h"
#include "Pago.h"
#include "stdlib.h"

#define TAM 5

using namespace std;

int mostrarMenu(){
    int opcion = 0;
    cout << "*****************************" << endl;
    cout << "       MENU DE OPCIONES       " << endl;
    cout << "*****************************" << endl;
    cout << "1.Agregar clientes a la lista" << endl;
    cout << "2.Agregar prestamo a la lista" << endl;
    cout << "3.Hacer pagos de prestamos" << endl;
    cout << "4.Mostrar lista de clientes" << endl;
    cout << "5.Mostrar lista de prestamos" << endl;
    cout << "6.Mostrar detalles del prestamo" << endl;
    cout << "7.Salir" << endl;
    cout << "*****************************" << endl;
    cout << "Digite una opcion: ";
    cin >> opcion;
    return opcion;
}

Cliente* agregarCliente() {
    int codigo;
    string nombre, apellido;
    Cliente* punteroCliente = NULL;
    cout << "------------------------------" << endl;
    cout << "Digite el codigo del cliente: ";
    cin >> codigo;
    cout << "Digite el nombre del cliente: ";
    cin >> nombre;
    cout << "Digite el apellido del cliente: ";
    cin >> apellido;
    punteroCliente = new Cliente(codigo, nombre, apellido);
    return punteroCliente;
}

Cliente* buscarCliente(Cliente** listaDeClientes, int contadorClientes, int codigoCliente) {
    for(int i = 0; i < contadorClientes; i++) {
        if(listaDeClientes[i]->getIdCliente() == codigoCliente) {
            return listaDeClientes[i];
        }
    }
    return nullptr;
}

Prestamo* buscarPrestamo(Prestamo** listaPrestamos, int contadorPrestamos, int codigoPrestamo){
    for(int i = 0; i < contadorPrestamos; i++) {
        if(listaPrestamos[i]->getNumeroPrestamo() == codigoPrestamo){
            return listaPrestamos[i];
        }
        return nullptr;
    }
}

Prestamo* agregarPrestamo(Cliente* lstCliente[], int contadorClientes, Cliente* cliente){
    int numeroPrestamo;
    int numeroCliente;
    float montoAprobado;
    int dia, mes, anio;
    Prestamo* prestamo = nullptr;

    if(cliente != nullptr) {
        cout << "------------------------------" << endl;
        cout << "Ingrese el numero de prestamo: ";
        cin >> numeroPrestamo;
        cout << "-------------------------------------------------" << endl;
        cout << "Ingrese la fecha de aprobacion: (dia, mes, anio)" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "\nMes: ";
        cin >> mes;
        cout << "\nAnio: ";
        cin >> anio;
        cout << "------------------------------" << endl;
        cout << "Digite el monto aprobado: $";
        cin >> montoAprobado;

        Fecha* fecha = new Fecha(dia, mes, anio);
        prestamo = new Prestamo(numeroPrestamo, cliente, fecha, montoAprobado);
        return prestamo;
    }else{
        cout << "*****************************" << endl;
        cout << "No se encontro ningun cliente" << endl;
        cout << "*****************************" << endl;
    }

}

Pago* agregarPago(Pago* listaPagos[], int contadorPagos, Prestamo* listaPrestamos[], int contadorPrestamo, Prestamo* prestamo) {
    int numeroPrestamo, dia, mes, anio;
    float montoPago;
    Pago* pago = nullptr;

    if(prestamo != nullptr){
        cout << "--------------------------------------" << endl;
        cout << "ingrese la fecha del pago (dd/mm/aa): " << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "\nMes: ";
        cin >> mes;
        cout << "\nAnio: ";
        cin >> anio;
        cout << "---------------------------------" << endl;
        cout << "ingrese el moto del pago (Saldo $" << prestamo->getSaldoPendiente() << ") :" << endl << "$";
        cin >> montoPago;
        Fecha* fecha = new Fecha(dia, mes, anio);
        pago = new Pago(fecha, montoPago);
       if(prestamo->hacerPago(pago)){
            cout << "****************************" << endl;
            cout << "El pago se realizo con exito" << endl;
            cout << "****************************" << endl;
       }else{
            cout << "***********************************" << endl;
            cout << "El monto del pago es mayor al saldo" << endl;
            cout << "***********************************" << endl;
       }
    }

    return pago;
}

void mostrarListaDeClientes(Cliente* listaDeClientes[], int contadorClientes){
    if(contadorClientes != 0){
        cout << "------------------------------" << endl;
        cout << "Codigo\tNombre\tApellido" << endl;
        for(int i = 0; i < contadorClientes; i++){
            cout << listaDeClientes[i]->getIdCliente() << "\t";
            cout << listaDeClientes[i]->getNombre() << "\t";
            cout << listaDeClientes[i]->getApellido() << "\n";
            cout << "------------------------------" << endl;
        }
    }else{
        cout << "********************************" << endl;
        cout << "La lista de los clientes esta vacia"  << endl;
        cout << "********************************" << endl;
    }
}

void mostrarListaDePrestamo(Prestamo* listaDePrestamo[], int contadorPrestamo){
    if(contadorPrestamo != 0){
        cout << "------------------------------" << endl;
        cout << "numero\tmonto\tsaldo" << endl;
        for(int i = 0; i < contadorPrestamo; i++){
            cout << listaDePrestamo[i]->getNumeroPrestamo() << "\t";
            cout << "$" << listaDePrestamo[i]->getMontoAprobado() << "\t";
            cout << "$" << listaDePrestamo[i]->getSaldoPendiente() << "\n";
            cout << "------------------------------" << endl;
        }
    }else{
        cout << "********************************" << endl;
        cout << "la lista de prestamos esta vacia" << endl;
        cout << "********************************" << endl;
    }
}

void mostrarDetallesPrestamo(Prestamo* listaDePrestamos[], int contadorPrestamo, int numeroPrestamo){
    Prestamo* prestamo = buscarPrestamo(listaDePrestamos, contadorPrestamo, numeroPrestamo);
    if(prestamo){
        cout << "Cliente: " << prestamo->getCliente()->getNombre() << " " << prestamo->getCliente()->getApellido() << endl;
        if(prestamo->getContadorPagos() != 0) {
        cout << "Saldo pendiente: $" << prestamo->getSaldoPendiente() << endl;
            cout << "Pagos: " << endl;
            cout << "Fecha\t\tmonto\t" << endl;
            Pago** pagos = prestamo->getLstPagos();
            for(int i = 0; i < prestamo->getContadorPagos(); i++){
                pagos[i]->getFechaPago()->mostrarFecha();
                cout << "\t\t";
                cout << "$" << pagos[i]->getMontoPago() << endl;
            }
        }
    }else{
        cout << "******************************" << endl;
        cout << "No se encontro ningun prestamo" << endl;
        cout << "******************************" << endl;
    }
}

int main()
{
    int contadorClientes = 0, contadorPrestamos = 0, contadorPagos = 0, opcion = 0;
    Cliente* cliente = nullptr;
    Prestamo* prestamo = nullptr;
    Pago* pago = nullptr;
    Cliente* listaClientes[TAM];
    Prestamo* listaPrestamo[TAM];
    Pago* listaPagos[TAM];


    do{
        system("cls");
        opcion = mostrarMenu();
        switch(opcion){
            case 1:
                if (contadorClientes < TAM){
                listaClientes[contadorClientes] = agregarCliente();
                contadorClientes++;
                cout << "******************************" << endl;
                cout << "El cliente se agrego con exito" << endl;
                cout << "******************************" << endl;
                }else{
                    cout << "*******************************" << endl;
                    cout << "la lista de clientes esta llena" << endl;
                    cout << "*******************************" << endl;
                }
                break;

            case 2:
                if (contadorPrestamos < TAM) {
                    int idCliente;
                    cout << "------------------------------" << endl;
                    cout << "Digite el id del cliente: ";
                    cin >> idCliente;
                    cliente = buscarCliente(listaClientes, contadorClientes, idCliente);
                    if(cliente != nullptr) {
                        listaPrestamo[contadorPrestamos] = agregarPrestamo(listaClientes, contadorClientes, cliente);
                        contadorPrestamos++;
                        cout << "***********************************" << endl;
                        cout << "El prestamo se realizo exitosamente" << endl;
                        cout << "***********************************" << endl;
                    }else{
                        cout << "******************************" << endl;
                        cout << "No se encontro ningun cliente" << endl;
                        cout << "******************************" << endl;
                    }

                } else {
                    cout << "********************************" << endl;
                    cout << "La lista de prestamos esta llena" << endl;
                    cout << "********************************" << endl;
                }
                break;

            case 3:
                int numeroPago;

                if(contadorPagos < TAM){
                    cout << "--------------------------------------------------------------" << endl;
                    cout << "Digite el numero del prestamo al cual le va a realizar un pago: ";
                    cin >> numeroPago;
                    prestamo = buscarPrestamo(listaPrestamo, contadorPrestamos, numeroPago);
                    if(prestamo != nullptr) {
                        listaPagos[contadorPagos] = agregarPago(listaPagos, contadorPagos, listaPrestamo, contadorPrestamos, prestamo);
                        contadorPagos++;
                    } else {
                        cout << "******************************" << endl;
                        cout << "No se encontro ningun prestamo" << endl;
                        cout << "******************************" << endl;
                    }
                } else {
                    cout << "****************************" << endl;
                    cout << "La lista de pagos esta llena" << endl;
                    cout << "****************************" << endl;
                }
                break;

            case 4:
                mostrarListaDeClientes(listaClientes, contadorClientes);
                break;

            case 5:
                mostrarListaDePrestamo(listaPrestamo, contadorPrestamos);
                break;

            case 6:
                int numeroPrestamo;
                cout << "ingrese el numero de prestamo a consultar" << endl;
                cout << "numero prestamo: ";
                cin >> numeroPrestamo;
                mostrarDetallesPrestamo(listaPrestamo, contadorPrestamos, numeroPrestamo);

            default:
                break;
        }
        system("pause");
    } while(opcion != 7);

    return 0;
}


