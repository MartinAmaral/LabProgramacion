#include "CUsuarioYSesion.h"
#include <string>

using namespace std;

CUsuarioYSesion* CUsuarioYSesion::instanceController = nullptr;

CUsuarioYSesion* CUsuarioYSesion::getInstanceUsuario() {
    if (instanceController == nullptr) {
        instanceController = new CUsuarioYSesion();
    }
    return instanceController;
}
Usuario* CUsuarioYSesion::getUsuarioActivo(){
    return usuarioActivo;
}

bool CUsuarioYSesion::existeUsuario(int CI){
    //revisar en un diccionario
    return true;
}

void CUsuarioYSesion::ingresarCiIS(int ci){
    this->ciIniciarSesion = ci;
}

bool CUsuarioYSesion::ingresarPassIS(string pass){

    if(ciIniciarSesion == this->cedulaAdminDefecto && pass == this->contrasenaAdmin)
        return true;

    Usuario* user; // deberiamos buscarlo con la ciIniciarSesion y guardarlo
    
    return user->comprobarPass(pass);
}

void CUsuarioYSesion::asignarSesion(){
    Usuario* user; // buscar por cedula
    this->usuarioActivo = user;
    this->ciIniciarSesion =0;
}

bool CUsuarioYSesion::esAdminDefecto(){
    if(this->ciIniciarSesion == this->cedulaAdminDefecto)
        return true;
    return false;
}

void asignarContrasena(string contra){
    Usuario* usuario;
    usuario->setContrasena(contra);
}

bool CUsuarioYSesion::esActivoIS(){
    Usuario* usuario;
    return usuario->getActivo(); 
}

void CUsuarioYSesion::cerrarSesion(){
   this->usuarioActivo = NULL;
}

void CUsuarioYSesion::reactivarUsuario(){
    Usuario* user; // buscar por cedula
    user->setActivo(true);
}



