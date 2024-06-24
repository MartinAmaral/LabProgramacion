#include "datosDiagnostico.h"

DatosDiagnostico::DatosDiagnostico(){
}

void DatosDiagnostico::agregarRepresentacion(RepresentacionE* rep){
    this->representaciones.push_back(rep);
}

void DatosDiagnostico::agregarCategoria(Categoria* cat){
   this->diagnosticos.push_back(cat); 
}
        
DatosDiagnostico::~DatosDiagnostico(){

}

