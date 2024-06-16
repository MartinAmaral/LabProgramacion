#include "CUsuarioYSesion.h"
#include <string>
#include "../entidades/usuario.h"
using namespace std;

CUsuarioYSesion& CUsuarioYSesion::getInstanceUsuario() {
    return InstanceUsuario;
}
void CUsuarioYSesion::ingresarCi(int ci){
    this->ciIniciarSesion = ci;
}

bool CUsuarioYSesion::ingresarPass(string pass){

    Usuario* user; // deberiamos buscarlo con la ciIniciarSesion y guardarlo
    return user->comprobarPass(pass);
}

void CUsuarioYSesion::asignarSesion(){
    Usuario* user; // buscar por cedula
    this->usuarioActivo = user;
    this->ciIniciarSesion =0;
}

void CUsuarioYSesion::cancelarInicioSesion(){
    this->ciIniciarSesion = 0;
}

bool CUsuarioYSesion::Esactivo(){
    return this->usuarioActivo;
}

void CUsuarioYSesion::cerrarSesion(){
   this->usuarioActivo = NULL;
}

void CUsuarioYSesion::reactivarUsuario(){
    Usuario* user; // buscar por cedula
}

Usuario* CUsuarioYSesion::getUsuarioActivo(){
    return this->usuarioActivo; 
}


