#include "fabricaCConsulta.h"
#include "../controllers/CConsulta.h"

ICConsulta* FabricaCConsulta::getCConsulta(){
    return CConsulta::getInstanceConsulta();
}
