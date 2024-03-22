#ifndef FECHA_H
#define FECHA_H

class Fecha
{
    public:
        Fecha(int, int, int);
        void mostrarFecha();
        virtual ~Fecha();

    protected:

    private:
        int dia;
        int mes;
        int year;
};

#endif // FECHA_H
