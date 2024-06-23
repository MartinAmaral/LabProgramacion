#ifndef ICCONSULTA_H
#define ICCONSULTA_H
#include <string>
#include "../entidades/fecha.h"
using namespace std;

class ICConsulta {
    public:
        virtual void altaConsultaComun(int ciMedico,int ciPaciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio)=0;
        virtual void altaConsultaEmergencia(int ciMedico, int ciPaciente,Fecha* fechaConsulta,string motivo)=0;
        virtual bool consultaExistente(int ciMedico,int ciPaciente,Fecha* fechaConsulta,Fecha* fechaReserva)=0;
        
        virtual ~ICConsulta()=0;
};
#endif
