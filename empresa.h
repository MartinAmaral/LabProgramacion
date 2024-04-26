#ifndef EMPRESA_H
#define EMPRESA_H
#define MAX_EMPLEADO 50
#include <string>
#include "empleado.h"
using namespace std;

class Empleado;
class Empresa{
private:
    string nombre;
    string nombre_legal;
    int rut;
    Empleado* empleados [MAX_EMPLEADO] ;

public:
    Empresa(string nombre, string nombre_legal,int rut, Empleado* emp );
    float total_sueldo_peso();
    float total_sueldo_dolar();

    string getNombre();
    string getNombreLegal();
    int getRut();
    Empleado** getEmpleados();

    void setNombre(string nombre);
    void setNombreLegal(string nombre_legal);
    void setRut(int rut); 
    ~Empresa();
};

#endif
