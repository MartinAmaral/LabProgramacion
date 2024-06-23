#include "usuario.h"
#include <ctime>
#include "sexo.h"
#include "fecha.h"

Usuario::Usuario(string nombre,string apellido,Sexo sexo,int CI,Fecha* fechaNacimiento,TipoUsuario tipo)
:nombre(nombre), apellido(apellido), sexo(sexo), CI(CI), fechaNacimiento(fechaNacimiento), tipoUsuario(tipo) {
    this->contrasena = "";
    this->activo = false;
}

bool Usuario::getActivo(){
    return this->activo;
}

int Usuario::getCI(){
    return CI;
}

Sexo Usuario::getSexo(){
    return this->sexo;;
}

Fecha* Usuario::getFechaNacimiento(){
    return this->fechaNacimiento;
}

string Usuario::getNombre(){
    return this->nombre;
}

string Usuario::getApellido(){
    return this->apellido;
}

string Usuario::getContrasena(){
    return this->contrasena;
}
        
TipoUsuario Usuario::getTipoUsuario(){
    return this->tipoUsuario;
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
    int edad = anioActual - fechaNacimiento->getAno();
    // Ajustar la edad si aún no ha cumplido años este año
    if (mesActual < fechaNacimiento->getMes() ||
        (mesActual == fechaNacimiento->getMes() && diaActual < fechaNacimiento->getDia())) {
        edad--;
    }
    return edad;
}

        
void Usuario::setActivo(bool estado){
    this->activo = estado;
}
        
void Usuario::setCI(int ci){
    this->CI = ci;
}
        
void Usuario::setSexo(Sexo sexo){
    this->sexo = sexo;
}
        
void Usuario::setFechaNacimiento(Fecha* fecha){
    delete this->fechaNacimiento;
    this->fechaNacimiento = fecha;
}
        
void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}
        
void Usuario::setApellido(string apellido){
    this->apellido = apellido;
}
        
void Usuario::setContrasena(string contra){
    this->contrasena = contra;
}

bool Usuario::comprobarPass(string pass){
    return pass == this->contrasena;
}

Usuario::~Usuario() {
    if (fechaNacimiento != NULL) {
        delete fechaNacimiento;
    }
}
