#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <stdio.h>
#include <iostream>

using namespace std;

class Medicamento{

    private:
        string nombre;
    public:
        Medicamento(string nombre);
        string getnombreM();
        void setNombreM(string nombre);
        ~Medicamento();
};

#endif
