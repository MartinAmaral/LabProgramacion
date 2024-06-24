#ifndef ICCONSULTA_H
#define ICCONSULTA_H
#include <string>
#include "../dts/fecha.h"
#include "../entidades/categoria.h"
#include "../entidades/consulta.h"
#include "../entidades/representacionE.h"
#include "../dts/consultaDia.h"
#include <vector>

using namespace std;

class ICConsulta {
    public:
        virtual void altaConsultaComun(int ciMedico,int ciPaciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio)=0;
        virtual void altaConsultaEmergencia(int ciMedico, int ciPaciente,Fecha* fechaConsulta,string motivo)=0;
        virtual bool consultaExistente(int ciMedico,int ciPaciente,Fecha* fechaConsulta,Fecha* fechaReserva)=0;
        
        virtual void agregarDatosConsultas(Consulta* consultas[],int cantidad)=0;
        virtual void agregarDatosCategorias(Categoria* categorias[],int cantidad)=0;
        virtual void agregarDatosRepresentaciones(RepresentacionE* representaciones[],int cantidad)=0;
        
        virtual vector<ConsultaDia*> devolverConsultasDia(Fecha* fecha)=0; 
        virtual void elegirConsultaAgregarDiag(Consulta* consulta)=0;
        virtual ~ICConsulta(){};
};
#endif
