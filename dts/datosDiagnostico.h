#ifndef DATOSDIAGNOSTICO_H
#define DATOSDIAGNOSTICO_H

#include "../entidades/representacionE.h"
#include "../entidades/categoria.h"
#include <list>

class DatosDiagnostico{
    private:
        list<RepresentacionE*> representaciones;
        list<Categoria*> diagnosticos;
    public:
        DatosDiagnostico();
        void agregarRepresentacion(RepresentacionE* rep);
        void agregarCategoria(Categoria* cat);
        ~DatosDiagnostico();
};

#endif
