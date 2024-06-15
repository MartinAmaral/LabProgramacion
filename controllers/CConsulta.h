#include <string>
#include "../entidades/usuario.h"
#include "../entidades/medico.h"
// Este controllador se encarga de los siguientes casos de uso:
// Registro de Consulta
// Alta de Diagnostico de Una Consulta

class CConsulta {
    private:
        
    public:
        //Ingresa los datos de consulta
        void ingresarDatosConsulta(string ciMedico, string ciPaciente);
        //Ingresa los datos de una consulta de emergencia
        void ingresarDatosConsultaEmergencia();
        //Ingresa los datos de una consulta comun
        void ingresarDatosConsultaComun();
};