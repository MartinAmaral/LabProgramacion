#include "medicamento.h"

Medicamento::Medicamento(string nombre){
    this->nombre = nombre;
}

string Medicamento::getnombreM(){
    return nombre;

}
void Medicamento::setNombreM(string nombre) {
    this->nombre = nombre;
}

Medicamento::~Medicamento(){}
