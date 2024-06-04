#ifndef CONSULTA_H
#define CONSULTA_H

#include "fecha.h"
#include <iostream>
#include <string>
using namespace std;
class Consulta
{
    private:
        Fecha fechaConsulta;
        string hora;
    public:
        Consulta(Fecha fecha, string hora);
        ~Consulta();
};

#endif
