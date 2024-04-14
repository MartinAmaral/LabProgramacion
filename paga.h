#ifndef PAGA_H
#define PAGA_H

#include "moneda.h"

using namespace std;

class Paga{
private:
    float monto;
    Moneda moneda;

public:
   
    Paga(float monto,Moneda moneda);
    float getMonto();
    Moneda getMoneda();
    Paga* a_dolar();
    Paga* a_peso();
    void setMonto(float monto);
    void setMoneda(Moneda moneda);   
    
};

#endif
