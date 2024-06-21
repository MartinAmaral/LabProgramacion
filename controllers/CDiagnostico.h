#ifndef CDIAGNOSTICO_H
#define CDIAGNOSTICO_H

#include <string>
#include "../entidades/usuario.h"
#include "../entidades/diagnostico.h"

using namespace std;

class CDiagnostico {
private:
    static CDiagnostico* InstanceDiagnostico; // Debe ser una variable estática, no una función

public:
    static CDiagnostico* getInstanceDiagnostico();

    // Métodos para el controlador CDiagnostico
    void DevolverConsultas();
    void SeleccionaConsulta(string ci);
    void AgregarDiagnostico();
    void AgregarTratamiento();
    void ListarRepresentacionesEstand();  // Método opcional

    // Constructor y destructor si es necesario
    CDiagnostico();  // Constructor
    ~CDiagnostico();  // Destructor
};

#endif
