#include "fecha.h"
#include <ctime>

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

int Fecha::getEdad(){

    std::time_t t = std::time(0);
    std::tm* fechaHoy = std::localtime(&t);

    int currentDay = fechaHoy->tm_mday;
    int currentMonth = fechaHoy->tm_mon + 1;
    int currentYear = fechaHoy->tm_year + 1900;

    int age = currentYear - this->ano;

    if (currentMonth < this->mes || (currentMonth == this->mes && currentDay < this->dia)) {
        age--;
    }

	return age;
}

Fecha::~Fecha(){}

