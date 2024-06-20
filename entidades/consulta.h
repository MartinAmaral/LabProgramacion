#ifndef CONSULTA_H
#define CONSULTA_H

#include "fecha.h"
#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

class Consulta {
protected: 
    Fecha* fechaConsulta;
    string hora;
    Usuario* paciente;
    Usuario* medico;
public:
    
    Fecha* getFechaConsulta();
    string getHora();
    Usuario* getPaciente();
    Usuario* getMedico();

    void setFechaConsulta(Fecha* fecha);
    void setHora(string hora);
    void setPaciente(Usuario* paciente);
    void setMedico(Usuario* medico);

    virtual ~Consulta() = 0;
};

#endif
