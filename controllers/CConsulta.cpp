#include <string>
#include "../entidades/usuario.h"
#include "../dts/fecha.h"
#include "CConsulta.h"
#include "../fabricas/fabricaCUsuario.h"

using namespace std;

CConsulta* CConsulta::instance = NULL;

CConsulta* CConsulta::getInstanceConsulta() {
    if (instance == NULL) {
        instance = new CConsulta();
    }
    return instance;
}

void CConsulta::altaConsultaComun(int ciMedico,int ciPaciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio){
    Usuario* medico = FabricaCUsuario::getCUsuario()->getUsuario(ciMedico); 
    Usuario* paciente = FabricaCUsuario::getCUsuario()->getUsuario(ciPaciente); 
    ConsultaComun* consulta = new ConsultaComun(medico,paciente,fechaConsulta,fechaReserva,asistio);
    this->consultas.push_front(consulta);
}
        
void CConsulta::altaConsultaEmergencia(int ciMedico, int ciPaciente,Fecha* fechaConsulta,string motivo){
    Usuario* medico = FabricaCUsuario::getCUsuario()->getUsuario(ciMedico); 
    Usuario* paciente = FabricaCUsuario::getCUsuario()->getUsuario(ciPaciente); 
    ConsultaEmergencia* consulta = new ConsultaEmergencia(medico,paciente,fechaConsulta,motivo);
    this->consultas.push_front(consulta);
}
        
bool CConsulta::consultaExistente(int ciMedico,int ciPaciente,Fecha* fechaConsulta,Fecha* fechaReserva){
    for (Consulta* cons : this->consultas) {
        ConsultaComun* consultaCheck = dynamic_cast<ConsultaComun*>(cons);
        if(!consultaCheck) continue;
        
        if(consultaCheck->getMedico()->getCI() == ciMedico && consultaCheck->getPaciente()->getCI() == ciMedico){
            Fecha* fecha = consultaCheck->getFechaConsulta(); 
            if(fecha->getDia() == fechaConsulta->getDia() && fecha->getMes() == fechaConsulta->getMes() 
                && fecha->getAno() == fechaConsulta->getAno()){
                return true;
            }
            fecha = consultaCheck->getFechaConsulta(); 
            if(fecha->getDia() == fechaReserva->getDia() && fecha->getMes() == fechaReserva->getMes() 
                && fecha->getAno() == fechaReserva->getAno()){
                return true;
            }
        }
    }
    return false;
}
        
void CConsulta::agregarDatosConsultas(Consulta* consultas[],int cantidad){
    int index =0;
    while(index<cantidad){
        this->consultas.push_front(consultas[index]); 
        index ++;
    }
}
        
void CConsulta::agregarDatosCategorias(Categoria* categorias[],int cantidad){
    int index =0;
    while(index<cantidad){
        this->categorias.push_front(categorias[index]); 
        index ++;
    }

}
        
void CConsulta::agregarDatosRepresentaciones(RepresentacionE* representaciones[],int cantidad){
    int index =0;
    while(index<cantidad){
        this->representaciones.push_front(representaciones[index]); 
        index ++;
    }
}

void CConsulta::elegirConsultaAgregarDiag(Consulta* consulta){
    this->consultaAgregarDiag = consulta;
}
        
void CConsulta::agregarDiagnosticoConsulta(string representacion, string descrip){
    RepresentacionE* rep = NULL;

    for (RepresentacionE* r : this->representaciones) {
        if(r->getCodigo() == representacion){
            rep = r;
            break;
        }
    }

    Diagnostico* diag = new Diagnostico(rep,descrip);
    consultaAgregarDiag->agregarDiagnostico(diag);
}

vector<ConsultaDia*> CConsulta::devolverConsultasDia(Fecha* fecha){
    vector<ConsultaDia*> resultado;
    for (Consulta* con : this->consultas) {
        Fecha* f = con->getFechaConsulta();
        if(f->getDia() == fecha->getDia() && f->getMes() == fecha->getMes() && f->getAno() == fecha->getAno()){
           resultado.push_back(new ConsultaDia(con->getPaciente()->getCI(),con)); 
        }
    }
    return resultado;
}
        
DatosDiagnostico* CConsulta::devolverDatosDiagnostico(){
    
    DatosDiagnostico* res = new DatosDiagnostico();

    for(Categoria* c: this->categorias){
        res->agregarCategoria(c);
    }
    for(RepresentacionE* r: this->representaciones){
        res->agregarRepresentacion(r);
    }
    return res;
}




