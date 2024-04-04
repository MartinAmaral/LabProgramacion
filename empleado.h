#include <string>
#include <Paga.h>
#include <Empresa.h>

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
        Paga getValorHora;

        void setNombre(string nombre);
        void setCI(string ci);
        void setEdad(int edad);
        void setValorHora(Paga* valorHora);

        virtual getSueldoPeso()=0;
        virtual getSueldoDolar()=0;
        virtual ~Empleado();
}