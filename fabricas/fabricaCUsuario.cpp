#include "fabricaCUsuario.h"
#include "../controllers/CUsuarioYSesion.h"

ICUsuarioYSesion* FabricaCUsuario::getCUsuario(){
    return CUsuarioYSesion::getInstanceUsuario();
}
