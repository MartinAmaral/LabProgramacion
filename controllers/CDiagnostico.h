#ifndef CDIAGNOSTICO_H
#define CDIAGNOSTICO_H

#include <string>
#include "../entidades/usuario.h"
#include "../entidades/diagnostico.h"
// Este controllador se encarga de los siguientes casos de uso:
// Alta de representación estandarizada de diagnósticos
// Listar representaciones estandarizadas OPCIONAL
using namespace std;

class CDiagnostico //: public ICDiagnostico
 {
    private:
    static CDiagnostico* InstanceDiagnostico();
        
    public:
        static CDiagnostico* getInstanceDiagnostico();
        //Devuelve y selecciona la consulta para dar de alta un diagnostico.
        void DevolverConsultas();
        void SeleccionaConsulta(string ci);

        //Agrega diagnostico y tratamiento a la consulta.
        void AgregarDiagnostico();
        void AgregarTratamiento();

        //Listar representaciones estandarizadas, agregar y seleccionar OPCIONAL
        void ListarRepresentacionesEstand();        
};
#endif
