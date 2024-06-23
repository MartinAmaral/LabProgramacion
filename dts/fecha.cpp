#include "fecha.h"

Fecha::Fecha(int ano,int mes, int dia){
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
}

int Fecha::getAno(){
    return this->ano;
}

int Fecha::getMes(){
    return  this->mes;   
}

int Fecha::getDia(){
    return this->dia;
}

Fecha::~Fecha(){}

