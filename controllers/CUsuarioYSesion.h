#ifndef CUSUARIOYSESION_H
#define CUSUARIOYSESION_H

#include <string>
#include "../entidades/usuario.h"
#include "../Interfaces/ICUsuarioYSesion.h"
#include <map>
// Este controllador se encarga de los siguientes casos de uso:
// Iniciar Sesión
// Cerrar Sesión
// Alta/Reactivación de Usuario

using namespace std;

class CUsuarioYSesion : public ICUsuarioYSesion {
    private:
        int ciIniciarSesion;
        Usuario* usuarioPorDefecto = NULL;
        Usuario* usuarioActivo = NULL;
        static CUsuarioYSesion* instanceController;
        map<int,Usuario*> usuarios;        
    public:
        CUsuarioYSesion();
        static CUsuarioYSesion* getInstanceUsuario();
        //Generales
        Usuario* getUsuarioActivo() override;
        bool existeUsuario(int CI) override;
        Usuario* getUsuario(int ci) override;
        TipoUsuario getTipoUsuario(int ci) override;
        void inicializarUsuarios(Usuario* usuarios[],int cantidad) override;
        //Iniciar Sesion
        void ingresarCiIS(int ci) override; 
        bool ingresarPassIS(std::string pass) override; 
        void asignarSesion() override; 
        bool esAdminDefecto() override; 
        void asignarContrasena(std::string contra) override; 
        void recordarCiIS(int ci) override; 
        bool usuarioSinContrasena() override; 
        bool esActivoIS() override; 
        //Cerrar Sesion
        void cerrarSesion() override; 
        // Alta/Reactivación de Usuario
        void reactivarUsuario() override; 
        ~CUsuarioYSesion();
}; 
#endif

