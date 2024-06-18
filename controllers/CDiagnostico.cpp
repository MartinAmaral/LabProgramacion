#include "../entidades/medicamento.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include "CDiagnostico.h"

using namespace std;

CDiagnostico* CDiagnostico::InstanceDiagnostico = nullptr;

CDiagnostico* CDiagnostico::getInstanceDiagnostico() {
    if (InstanceDiagnostico == nullptr) {
        InstanceDiagnostico = new CDiagnostico();
    }
    return InstanceDiagnostico;
}
//Devuelve y selecciona la consulta para dar de alta un diagnostico.

        void DevolverConsultas(){

        }

        void SeleccionaConsulta(string ci){

        }

        //Agrega diagnostico y tratamiento a la consulta.

        void AgregarDiagnostico(){

        }

        void AgregarTratamiento(){

        }

        //Listar representaciones estandarizadas, agregar y seleccionar OPCIONAL
        
        void ListarRepresentacionesEstand(){

        }