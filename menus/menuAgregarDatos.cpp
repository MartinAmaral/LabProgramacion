#include "menuAgregarDatos.h"
#include <iostream>
#include "../entidades/usuario.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include "../entidades/consulta.h"

#include <string>
#include "../entidades/sexo.h"
#include "../entidades/fecha.h"
#include "../entidades/representacionE.h"
#include "../entidades/categorias.h"

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
        
        Usuario* usuarioJA = new Usuario("James","Peer",Masculino,34567645,new Fecha(1988,12,28));
        Usuario* usuarioTM = new Usuario("Tifany","McKensey",Femenino,34562345,new Fecha(1990,1,1));
        Usuario* usuarioDP = new Usuario("Diego","Perez",Masculino,12345435,new Fecha(1980,3,3));
        Usuario* usuarioJM = new Usuario("Juan","Montoya",Masculino,65436667,new Fecha(1970,4,7));
        Usuario* usuarioDC = new Usuario("Debora","Corral",Femenino,43521343,new Fecha(1993,7,13));
        Usuario* usuarioAL = new Usuario("Ana","Lopez",Femenino,98056743,new Fecha(1981,9,24));
       
        // Aca se agregarian uno por uno


        // Consultas consulta 
        // paciente medico consulta reserva
        ConsultaComun * consultaC1 = new ConsultaComun(usuarioTM,usuarioJM,new Fecha(2014,6,23),new Fecha(2014,6,21));
        ConsultaComun * consultaC2 = new ConsultaComun(usuarioTM,usuarioDC,new Fecha(2014,6,22),new Fecha(2014,5,22));
        ConsultaComun * consultaC3 = new ConsultaComun(usuarioJM,usuarioDC,new Fecha(2014,3,16),new Fecha(2014,3,25));
        ConsultaComun * consultaC4 = new ConsultaComun(usuarioDP,usuarioAL,new Fecha(2014,3,1),new Fecha(2014,2,28));
       
        //Consultas Emergencia
        // paciente medico fecha motivo
        ConsultaEmergencia* emergenciaU1 = new ConsultaEmergencia(usuarioTM,usuarioJM,new Fecha(2014,5,23),"Fiebre Alta");
        ConsultaEmergencia* emergenciaU2 = new ConsultaEmergencia(usuarioJM,usuarioDC,new Fecha(2014,5,24),"Asma");
        ConsultaEmergencia* emergenciaU3 = new ConsultaEmergencia(usuarioJM,usuarioAL,new Fecha(2014,3,3),"Mareos");

        //Representacion Estandar y categorias de esas representaciones
        Categoria* categoriaA = new Categoria("A","Afecciones pulmonares");
        Categoria* categoriaB = new Categoria("B","Aparato digestivo");

        RepresentacionE* repreR1 = new RepresentacionE("A01","Asma");
        RepresentacionE* repreR2 = new RepresentacionE("A02","Congestion");
        RepresentacionE* repreR3 = new RepresentacionE("B01","Nauseas");

        // Ni idea como quiere que hagamos los diagnosticos

    }


}
