#include "usuario.h"
#include <ctime>
#include "sexo.h"
#include "fecha.h"


//Iniciar Sesion
Usuario::Usuario(int ci,string contrasena){

    this->CI = ci;
    this->contrasena = contrasena;
}

int Usuario::getCI(){
    return CI;
}

string Usuario::getContrasena(){
    return contrasena;
}


bool Usuario::comprobarPass(string pass){
    return pass == this->contrasena;
}


//Alta reactivacion

int Usuario::getEdad() const {
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

Usuario Usuario::getUsuario(){
    return Usuario(nombre, apellido, sexo, activo);
}

Usuario::Usuario(string nombre,string contrasena,Sexo sexo, Fecha FechaNacimiento){

    this->nombre = nombre;
    this->apellido = apellido;
    this->sexo = sexo;
    this->fechaNacimiento = fechaNacimiento;
    //Tipo de Usuario? hacemos enum?
}