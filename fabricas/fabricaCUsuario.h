#ifndef FABRICACUSUARIO_H
#define FABRICACUSUARIO_H
#include "../Interfaces/ICUsuarioYSesion.h"

class FabricaCUsuario{
    public:
         static ICUsuarioYSesion* getCUsuario();
};

#endif  
