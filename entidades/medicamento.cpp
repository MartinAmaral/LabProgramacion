#include "medicamento.h"
#include "usuario.h"

Medicamento::Medicamento(string nombre){
    this->nombre = nombre;
    
}

string Medicamento::getnombreM(){
    return nombre;

}


Medicamento::~Medicamento(){}
