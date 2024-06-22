#ifndef ICUSUARIOYSESION_H
#define ICUSUARIOYSESION_H
#include "../entidades/usuario.h"
#include <string>

class ICUsuarioYSesion {
    public:
        //Generales
        virtual Usuario* getUsuarioActivo() =0;
        virtual bool existeUsuario(int CI)=0;
        virtual Usuario* getUsuario(int ci) =0;
        virtual TipoUsuario getTipoUsuario(int ci) =0;
        virtual void inicializarUsuarios(Usuario* usuarios[],int cantidad)=0;

        //Iniciar Sesion
        virtual void ingresarCiIS(int ci) =0;
        virtual bool ingresarPassIS(std::string pass)=0;
        virtual void asignarSesion()=0; 
        virtual bool esAdminDefecto()=0;
        virtual void asignarContrasena(std::string contra)=0;
        virtual void recordarCiIS(int ci)=0;
        virtual bool usuarioSinContrasena()=0;
        virtual bool esActivoIS()=0; 
        //Cerrar Sesion
        virtual void cerrarSesion()=0; 

        // Alta/Reactivación de Usuario
        virtual void reactivarUsuario()=0; 
        // Usuarios dados de alta y reactivados
        virtual ~ICUsuarioYSesion(){}
};

#endif

