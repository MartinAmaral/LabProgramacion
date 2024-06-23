#include "CUsuarioYSesion.h"
#include <string>
#include "../entidades/administrativo.h"
#include "../entidades/socio.h"
#include "../entidades/medico.h"

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
        
InfoUsuarioDT* CUsuarioYSesion::devolverInfo(int cedula){
    Usuario* user = usuarios[cedula];
    return new InfoUsuarioDT(user->getNombre(),user->getApellido(),user->getSexo(),user->getFechaNacimiento(),user->getTipoUsuario());
}

void CUsuarioYSesion::altaUsuario(InfoUsuarioDT* info,int cedula){
    Usuario* nuevoUsuario;
    if(info->getTipo() == Admin || info->getTipo() == SocioAdmin){
        nuevoUsuario = new Administrativo(info->getNombre(),info->getApellido(),info->getSexo(),cedula,
                                          info->getFechaNacimiento(),info->getTipo());
    } else if (info->getTipo() == Medico || info->getTipo() == SocioMedico){
        nuevoUsuario = new class Medico(info->getNombre(),info->getApellido(),info->getSexo(),cedula,
                                          info->getFechaNacimiento(),info->getTipo());
    } else {
        nuevoUsuario = new class Socio(info->getNombre(),info->getApellido(),info->getSexo(),cedula,
                                          info->getFechaNacimiento(),info->getTipo());
    }

    Administrativo * admin = dynamic_cast<Administrativo*>(this->usuarioActivo);
    admin->agregarUsuarioDadoAlta(nuevoUsuario);
    this->usuarios[cedula] = nuevoUsuario;
}

bool CUsuarioYSesion::esActivo(int cedula){
    Usuario* usuario = this->usuarios[cedula];
    return usuario->getActivo();
}

void CUsuarioYSesion::reactivarUsuario(int cedula){
    Usuario* usuario = this->usuarios[cedula];
    usuario->setActivo(true);
}

CUsuarioYSesion::~CUsuarioYSesion(){

}
