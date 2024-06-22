#ifndef CONSULTA_H
#define CONSULTA_H

#include "fecha.h"
#include <iostream>
#include <string>
#include "usuario.h"
#include "diagnostico.h"
#include <map>

using namespace std;

class Consulta {
protected:
    Fecha* fechaConsulta = NULL;
    string hora;
    Usuario* paciente = NULL;
    Usuario* medico = NULL;
    map<string, Diagnostico*> diagnosticos; // Vector para almacenar diagnósticos
public:
    Fecha* getFechaConsulta();
    string getHora();
    Usuario* getPaciente();
    Usuario* getMedico();
    Consulta(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta);
    void setFechaConsulta(Fecha* fecha);
    void setHora(string hora);
    void setPaciente(Usuario* paciente);
    void setMedico(Usuario* medico);
    void agregarDiagnostico(Diagnostico* diagnostico);

    virtual ~Consulta() = 0;
};
#endif
