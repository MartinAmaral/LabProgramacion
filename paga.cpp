#include "paga.h"
#include "moneda.h"
#include "cambio.h"

Paga::Paga(float monto, Moneda moneda){
    this->monto = monto;
    this->moneda = moneda;
}


Paga* Paga::a_dolar(){
    if (moneda == Moneda::usd){
        return this;
    }else{
    moneda = Moneda::usd;
    monto= cambio::a_dolar(monto); 
    return this;
    }
}


Paga* Paga::a_peso(){
    if (moneda == Moneda::us){
        return this;
    }else{

        moneda = Moneda::us;
        monto= cambio::a_peso(monto); 

        return this;
    }
}


float Paga::getMonto() {
        return monto;
    }

void Paga::setMonto(float monto) {
        this->monto = monto;
    }

Moneda Paga::getMoneda() {
        return moneda;
    }

void Paga::setMoneda(Moneda moneda) {
        this->moneda = moneda;
    }
