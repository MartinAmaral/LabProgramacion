#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include "paga.h"
#include "empresa.h"
using namespace std;

class Empresa;
class Empleado{
    protected: 
        string nombre;
        string id;
        int edad;
        Paga* valor_hora;
        Empresa* empresa;        

    public:
        Empleado(string nombre,string id,int edad,Paga* valorHora, Empresa* emp);
        string getNombre();
        string getCI();
        int getEdad();
        Paga* getValorHora();
    
        void setNombre(string nombre);
        void setCI(string ci);
        void setEdad(int edad);
        void setValorHora(Paga* valorHora);

        virtual float getSueldoPesos()=0;
        virtual float getSueldoDolar()=0;
        virtual ~Empleado();
};

#endif