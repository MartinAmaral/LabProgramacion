#ifndef CCONSULTA_H
#define CCONSULTA_H

#include <list>
#include <map>
#include <string>
#include <vector>
#include "../dts/fecha.h"
#include "../entidades/consulta.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include "../entidades/diagnostico.h"
#include "../entidades/categoria.h"
#include "../Interfaces/ICConsulta.h"
#include "../entidades/representacionE.h"
#include "../dts/datosDiagnostico.h"
#include "../entidades/tratamiento.h"
#include "../entidades/farmaco.h"
#include "../entidades/quirurgico.h"

using namespace std;

class CConsulta: public ICConsulta{
    private:
        static CConsulta* instance;
        list<Consulta*> consultas;
        list<Categoria*> categorias;
        list<RepresentacionE*> representaciones;
        Consulta* consultaAgregarDiag = NULL;
        RepresentacionE* representacinAgregar = NULL;
        Diagnostico* diagnostico = NULL;
    public:
        static CConsulta* getInstanceConsulta();
        void altaConsultaComun(int ciMedico,int ciPaciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio) override;
        void altaConsultaEmergencia(int ciMedico, int ciPaciente,Fecha* fechaConsulta,string motivo) override;
        bool consultaExistente(int ciMedico,int ciPaciente,Fecha* fechaConsulta,Fecha* fechaReserva) override;
        
        void agregarDatosConsultas(Consulta* consultas[],int cantidad) override;
        void agregarDatosCategorias(Categoria* categorias[],int cantidad) override;
        void agregarDatosRepresentaciones(RepresentacionE* representaciones[],int cantidad) override;
        //void agregarDatosFarmacos(Farmaco* farmaco[],int cantidad)

        vector<ConsultaDia*> devolverConsultasDia(Fecha* fecha) override;
        DatosDiagnostico* devolverDatosDiagnostico() override;
        void agregarDiagnosticoConsulta(string representacion, string descrip)override;
        void elegirConsultaAgregarDiag(Consulta* consulta) override;
        void agregarTratamiento(Tratamiento* tratamiento) override;
        void nuevoFarmaco(string descripcionTratamiento,string nombreMedicamento);
        //void nuevoQuirurgico(string descripcionTratamiento,Fecha* fechaCirugia);
        ~CConsulta(){};
};

#endif
