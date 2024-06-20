#include "usuario.h"
#include <ctime>
#include "sexo.h"
#include "fecha.h"


Usuario::Usuario(string nombre,string apellido,Sexo sexo,int CI,Fecha* FechaNacimiento,TipoUsuario tipo){
    this->nombre = nombre;
    this->apellido = apellido;
    this->sexo = sexo;
    this->CI = CI;
    this->contrasena = "";
    if (this->fechaNacimiento != NULL){
        delete fechaNacimiento;
    }
    this->fechaNacimiento = FechaNacimiento;
    this->tipoUsuario = tipo;
}

int Usuario::getCI(){
    return CI;
}

string Usuario::getContrasena(){
    return contrasena;
}


int Usuario::getEdad() {
    if (fechaNacimiento == NULL) {
        return -1; // Indica que no hay fecha de nacimiento
    }
    time_t tiempoActual = time(0);
    struct tm* ahora = localtime(&tiempoActual);
    int anioActual = 1900 + ahora->tm_year;
    int mesActual = 1 + ahora->tm_mon;
    int diaActual = ahora->tm_mday;
    int edad = anioActual - fechaNacimiento->ano;
    // Ajustar la edad si aún no ha cumplido años este año
    if (mesActual < fechaNacimiento->mes ||
        (mesActual == fechaNacimiento->mes && diaActual < fechaNacimiento->dia)) {
        edad--;
    }
    return edad;
}

bool Usuario::comprobarPass(string pass){
    return pass == this->contrasena;
}

Usuario::~Usuario() {
    if (fechaNacimiento != NULL) {
        delete fechaNacimiento;
    }
}
