#ifndef ICUSUARIOYSESION_H
#define ICUSUARIOYSESION_H
#include "../controllers/CusuarioYSesion.h"
class ICUsuarioYSesion {

    public:
        virtual Usuario* getUsuarioActivo();
    //Iniciar Sesion
        virtual void ingresarCi(int ci);
        virtual bool ingresarPass(std::string pass); // hicimos esta funcion dos veces
        virtual void asignarSesion();
        virtual void cancelarInicioSesion();
        virtual bool Esactivo();
        //Cerrar Sesion
        virtual void cerrarSesion();

        // Alta/Reactivación de Usuario
        virtual void reactivarUsuario();
        // Usuarios dados de alta y reactivados
        virtual ~ICUsuarioysesion(){};
};

#endif

