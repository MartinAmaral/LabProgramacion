#include <string>
#include "../entidades/usuario.h"
// Este controllador se encarga de los siguientes casos de uso:
// Iniciar Sesión
// Cerrar Sesión
// Alta/Reactivación de Usuario
// Usuarios dados de alta y reactivados

class CUsuarioYSesion {
    private:
        int ciIniciarSesion =0;
        Usuario* usuarioActivo = NULL;
    public:
        //Iniciar Sesion
        void ingresarCi(int ci);
        bool ingresarPass(std::string pass); // hicimos esta funcion dos veces
        void asignarSesion();
        void cancelarInicioSesion();
 
        //Cerrar Sesion
        void cerrarSesion();

        // Alta/Reactivación de Usuario

        // Usuarios dados de alta y reactivados
};
