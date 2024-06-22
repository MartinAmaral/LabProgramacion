#include "CUsuarioYSesion.h"
#include <string>
#include "../entidades/administrativo.h"

using namespace std;

CUsuarioYSesion* CUsuarioYSesion::instanceController = NULL;

CUsuarioYSesion::CUsuarioYSesion(){
    this->ciIniciarSesion = 0;
    Administrativo* adminDef = new Administrativo("admin","defecto",Masculino,26,NULL,Admin);
    adminDef->setContrasena("de redes");
    adminDef->setActivo(true);
    this->usuarioPorDefecto = adminDef;
}

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
    return this->usuarios.find(CI) != this->usuarios.end();
} 

Usuario* CUsuarioYSesion::getUsuario(int ci){
    return this->usuarios[ci];
}
        
TipoUsuario CUsuarioYSesion::getTipoUsuarioActivo(){
    return this->usuarioActivo->getTipoUsuario();
}
        
void CUsuarioYSesion::inicializarUsuarios(Usuario* usuarios[], int cantidad){
    int index =0;
    while(index<cantidad){
        this->usuarios[usuarios[index]->getCI()] = usuarios[0];  
        index ++;
    }
}

void CUsuarioYSesion::ingresarCiIS(int ci){
    this->ciIniciarSesion = ci;
}

bool CUsuarioYSesion::ingresarPassIS(string pass){

    if(ciIniciarSesion == usuarioPorDefecto->getCI() && usuarioPorDefecto->comprobarPass(pass))
        return true;

    Usuario* user = usuarios[this->ciIniciarSesion];
    return user->comprobarPass(pass);
}

void CUsuarioYSesion::asignarSesion(){
    Usuario* user = usuarios[this->ciIniciarSesion];
    this->usuarioActivo = user;
    this->ciIniciarSesion =0;
}

void CUsuarioYSesion::asignarSesionDefecto(){
    usuarioActivo = usuarioPorDefecto;
}

bool CUsuarioYSesion::esAdminDefecto(){
    return usuarioPorDefecto->getCI() == ciIniciarSesion;
}

void CUsuarioYSesion::asignarContrasena(string contra){
    Usuario* usuario = this->usuarios[this->ciIniciarSesion];
    usuario->setContrasena(contra);
}
        
void CUsuarioYSesion::recordarCiIS(int ci){
    this->ciIniciarSesion = ci;
}
        
bool CUsuarioYSesion::usuarioSinContrasena(){
    Usuario* usuario = this->usuarios[this->ciIniciarSesion];
    return usuario->getContrasena() == "";
}

bool CUsuarioYSesion::esActivoIS(){
    Usuario* usuario = this->usuarios[this->ciIniciarSesion];
    return usuario->getActivo(); 
}

void CUsuarioYSesion::cerrarSesion(){
   this->usuarioActivo = NULL;
}

bool CUsuarioYSesion::esActivo(int cedula){
    Usuario* usuario = this->usuarios[cedula];
    return usuario->getActivo();
}

void CUsuarioYSesion::reactivarUsuario(int cedula){
    Usuario* usuario = this->usuarios[cedula];
    usuario->setActivo(true);
}



