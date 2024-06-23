#ifndef FECHA_H
#define FECHA_H

class Fecha{
    private:
        int ano;
        int mes;
        int dia;

    public:
        Fecha(int ano, int mes,int dia);
        int getAno();
        int getMes();
        int getDia();
        int getEdad();
        ~Fecha();
};

#endif  
