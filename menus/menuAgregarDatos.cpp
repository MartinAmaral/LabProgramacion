#include "menuAgregarDatos.h"
#include <iostream>

#include "../entidades/usuario.h"
#include "../entidades/administrativo.h"
#include "../entidades/medico.h"
#include "../entidades/socio.h"

#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include "../entidades/consulta.h"

#include <string>
#include "../dts/fecha.h"
#include "../entidades/representacionE.h"

#include "../fabricas/fabricaCUsuario.h"

void MenuAgregarDatos::AgregarDatos(){

    if(this->hayDatos){
        std::cout << "Los Datos ya fueron agregados.\n";
    }
    else{
        Usuario* usuariosAgregar[6];
        Usuario* usuarioJA = new Administrativo("James","Peer",Masculino,34567645,new Fecha(1988,12,28),Admin);
        Usuario* usuarioTM = new class Socio("Tifany","McKensey",Femenino,34562345,new Fecha(1990,1,1),Socio);
        Usuario* usuarioDP = new class Socio("Diego","Perez",Masculino,12345435,new Fecha(1980,3,3),Socio);
        Usuario* usuarioJM = new class Medico("Juan","Montoya",Masculino,65436667,new Fecha(1970,4,7),SocioMedico);
        Usuario* usuarioDC = new class Medico("Debora","Corral",Femenino,43521343,new Fecha(1993,7,13),Medico);
        Usuario* usuarioAL = new class Medico("Ana","Lopez",Femenino,98056743,new Fecha(1981,9,24),Medico);
       
        usuariosAgregar[0] = usuarioJA;
        usuariosAgregar[1] = usuarioTM;
        usuariosAgregar[2] = usuarioDP;
        usuariosAgregar[3] = usuarioJM;
        usuariosAgregar[4] = usuarioDC;
        usuariosAgregar[5] = usuarioAL;

        FabricaCUsuario::getCUsuario()->inicializarUsuarios(usuariosAgregar,6);
        /*
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
        */
        cout<< "Datos agregados exitosamente\n";
        hayDatos = true;
    }
}
