#ifndef MENUSESION_H
#define MENUSESION_H

#include <string>
#include "../Interfaces/ICUsuarioYSesion.h"
class MenuSesion {
    private:
        ICUsuarioYSesion* controllerSesion = NULL;
        void darAlta(int cedula);
    public:
        void iniciarSesion();
        void cerrarSesion();
        void altaUsuario();
};
#endif
