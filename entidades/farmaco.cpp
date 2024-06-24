#include "farmaco.h"

Farmaco::Farmaco(string descripcion, string nombreMedicamento)
    : Tratamiento(descripcion), nombreMedicamento(nombreMedicamento) {}

Farmaco::~Farmaco() {}

const std::string& Farmaco::getNombreMedicamento() const {
    return nombreMedicamento;
}
