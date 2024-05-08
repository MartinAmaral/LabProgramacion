#include "usuario.h"


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


