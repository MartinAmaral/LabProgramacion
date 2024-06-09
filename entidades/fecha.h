#ifndef FECHA_H
#define FECHA_H

class Fecha{
    public:
        int ano;
        int mes;
        int dia;
        Fecha(int ano, int mes,int dia);
        int getAno();
        int getMes();
        int getDia();
        ~Fecha();
};

#endif  
