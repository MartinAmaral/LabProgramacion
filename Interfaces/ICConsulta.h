#ifndef ICCONSULTA_H
#define ICCONSULTA_H
#include <string>
using namespace std;

class ICConsulta {

    public:
        //Ingresa los datos de consulta
        virtual void ingresarDatosConsulta(string ciMedico, string ciPaciente);
        //Ingresa los datos de una consulta de emergencia
        virtual void ingresarDatosConsultaEmergencia();
        //Ingresa los datos de una consulta comun
        virtual void ingresarDatosConsultaComun();
        virtual ~ICConsulta(){};
};
#endif
