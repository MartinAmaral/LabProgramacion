#include <string>
#include "paga.h"
#include "empresa.h"
using namespace std;

class Empleado{
    private: 
        string nombre;
        string id;
        int edad;

    public:
        Empleado(string nombre,string id,Paga valorHora, Empresa* emp);
        string getNombre();
        string getCI();
        int getEdad();
        Paga* getValorHora;

        void setNombre(string nombre);
        void setCI(string ci);
        void setEdad(int edad);
        void setValorHora(Paga* valorHora);

        virtual float getSueldoPeso()=0;
        virtual float getSueldoDolar()=0;
        virtual ~Empleado();
};