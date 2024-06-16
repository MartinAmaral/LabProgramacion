#ifndef REPRESENTACIONE_H
#define REPRESENTACIONE_H

#include <iostream>
#include <string>
using namespace std;

class RepresentacionE {
    private:
        string codigo;
        string descripcion;


    public:
    // Constructor
        RepresentacionE(string codigo, string descripcion);
        // Destructor
        ~RepresentacionE();

        // Métodos de acceso
        string getDescripcion();
        void setDescripcion(string desc);

        string getCodigo();
        void setCodigo(string cod);

        // Método para mostrar la representación
        void mostrar();
};

#endif // REPRESENTACIONE_H
