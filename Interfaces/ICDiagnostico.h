#ifndef ICDIAGNOSTICO_H
#define ICDIAGNOSTICO_H
#include "../controllers/CDiagnostico.h"

class ICDiagnostico {
    public:

        //Devuelve y selecciona la consulta para dar de alta un diagnostico.
        virtual void DevolverConsultas();
        virtual void SeleccionaConsulta(string ci);

        //Agrega diagnostico y tratamiento a la consulta.
        virtual void AgregarDiagnostico();
        virtual void AgregarTratamiento();

        //Listar representaciones estandarizadas, agregar y seleccionar OPCIONAL
        virtual void ListarRepresentacionesEstand();
        virtual ~ICDiagnostico(){};
};
#endif