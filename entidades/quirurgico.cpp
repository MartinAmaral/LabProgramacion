#include "quirurgico.h"
#include "fecha.h"


Quirurgico::Quirurgico(string descripcion, Fecha* fecha)
    : Tratamiento(descripcion), fecha(fecha) {}

Quirurgico::~Quirurgico() {
    delete fecha;
}