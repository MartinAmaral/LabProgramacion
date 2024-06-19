#ifndef FARMACO_H
#define FARMACO_H

#include "tratamiento.h"
#include <string>
#include "fecha.h"
using namespace std;

class Farmaco : public Tratamiento {
private:
    string nombreMedicamento;
public:
    Farmaco(string descripcion, string nombreMedicamento);
    ~Farmaco();
};
#endif
