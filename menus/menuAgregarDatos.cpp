#include "menuAgregarDatos.h"
#include <iostream>
#include "../entidades/usuario.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"

#include <string>
#include "../entidades/sexo.h"
#include "../entidades/fecha.h"

void MenuAgregarDatos::AgregarDatos(){

    if(this->hayDatos){
        std::cout << "Los Datos ya fueron agregados.\n";
    }
    else{
        // Agregar usuarios
        Fecha* fecha = new Fecha(1988,12,28);
        Usuario* usuarioJA = new Usuario("James","Peer",Masculino,34567645,fecha);

        fecha = new Fecha(1990,1,1);
        Usuario* usuarioTM = new Usuario("James","Peer",Masculino,34567645,fecha);

        fecha = new Fecha(1980,3,3);
        Usuario* usuarioDP = new Usuario("James","Peer",Masculino,34567645,fecha);

        fecha = new Fecha(1970,4,7); 
        usuarioAgregar = new Usuario("James","Peer",Masculino,34567645,fecha);

        fecha = new Fecha(1993,7,13); 
        usuarioAgregar = new Usuario("James","Peer",Masculino,34567645,fecha);

        fecha = new Fecha(1981,9,24); 
        usuarioAgregar = new Usuario("James","Peer",Masculino,34567645,fecha);
        
        // Consultas consulta 
      
        fecha = new Fecha(2014,6,23);
        ConsultaComun * consultaAgregar = new ConsultaComun(fecha,);
    
    }


}
