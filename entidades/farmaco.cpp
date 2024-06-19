#include "farmaco.h"
#include "fecha.h"


Farmaco::Farmaco(string descripcion, string nombreMedicamento)
    : Tratamiento(descripcion), nombreMedicamento(nombreMedicamento) {}

Farmaco::~Farmaco() {}