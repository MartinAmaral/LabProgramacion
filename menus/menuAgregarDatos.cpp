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
#include "../entidades/categoria.h"
#include "../entidades/diagnostico.h"
#include "../entidades/Farmaco.h"

#include "../fabricas/fabricaCUsuario.h"
#include "../fabricas/fabricaCConsulta.h"

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
       
        // CAMBIAR CONSULTA C2 PARA EL 22 EN VEZ DEL 23
        ConsultaComun * consultaC1 = new ConsultaComun(usuarioTM,usuarioJM,new Fecha(2014,6,23),new Fecha(2014,6,21),true);
        ConsultaComun * consultaC2 = new ConsultaComun(usuarioTM,usuarioDC,new Fecha(2014,6,23),new Fecha(2014,5,22),true);
        ConsultaComun * consultaC3 = new ConsultaComun(usuarioJM,usuarioDC,new Fecha(2014,3,16),new Fecha(2014,3,25),true);
        ConsultaComun * consultaC4 = new ConsultaComun(usuarioDP,usuarioAL,new Fecha(2014,3,1),new Fecha(2014,2,28),false);
       
        ConsultaEmergencia* emergenciaU1 = new ConsultaEmergencia(usuarioTM,usuarioJM,new Fecha(2014,5,23),"Fiebre Alta");
        ConsultaEmergencia* emergenciaU2 = new ConsultaEmergencia(usuarioJM,usuarioDC,new Fecha(2014,5,24),"Asma");
        ConsultaEmergencia* emergenciaU3 = new ConsultaEmergencia(usuarioJM,usuarioAL,new Fecha(2014,3,3),"Mareos");

        Consulta* consultasAgregar[7];

        consultasAgregar[0] = consultaC1;
        consultasAgregar[1] = consultaC2;
        consultasAgregar[2] = consultaC3;
        consultasAgregar[3] = consultaC4;
        consultasAgregar[4] = emergenciaU1;
        consultasAgregar[5] = emergenciaU2;
        consultasAgregar[6] = emergenciaU3;
    
        FabricaCConsulta::getCConsulta()->agregarDatosConsultas(consultasAgregar,7);

        //Representacion Estandar y categorias de esas representaciones
        Categoria* categoriaA = new Categoria("A","Afecciones pulmonares");
        Categoria* categoriaB = new Categoria("B","Aparato digestivo");

        Categoria* catAgregar[2];
        catAgregar[0] = categoriaA;
        catAgregar[1] = categoriaB;
        FabricaCConsulta::getCConsulta()->agregarDatosCategorias(catAgregar,2);

        RepresentacionE* repreR1 = new RepresentacionE("A01","Asma");
        RepresentacionE* repreR2 = new RepresentacionE("A02","Congestion");
        RepresentacionE* repreR3 = new RepresentacionE("B01","Nauseas");
        
        RepresentacionE* repreAgregar[3];
        repreAgregar[0] = repreR1;
        repreAgregar[1] = repreR2;
        repreAgregar[2] = repreR3;

        FabricaCConsulta::getCConsulta()->agregarDatosRepresentaciones(repreAgregar, 3);

        Diagnostico* diagD1 = new Diagnostico(repreR1,"Desc 1");
        Diagnostico* diagD2 = new Diagnostico(repreR2,"Desc 2");
        Diagnostico* diagD3 = new Diagnostico(repreR3,"Desc 3");
        Diagnostico* diagD4 = new Diagnostico(repreR3,"Desc 4");
        Diagnostico* diagD5 = new Diagnostico(repreR2,"Desc 5");
        Diagnostico* diagD6 = new Diagnostico(repreR1,"Desc 6");

        consultaC1->agregarDiagnostico(diagD1);
        consultaC1->agregarDiagnostico(diagD2);
        consultaC3->agregarDiagnostico(diagD3);
        emergenciaU1->agregarDiagnostico(diagD4);
        emergenciaU1->agregarDiagnostico(diagD5);
        emergenciaU1->agregarDiagnostico(diagD6);

        /* Farmaco* farmacoF1 = new Farmaco("M1", "Desc 1", diagD1);
        Farmaco* farmacoF2 = new Farmaco("M2", "Desc 2", diagD1);
        Farmaco* farmacoF3 = new Farmaco("M3", "Desc 3", diagD1);
        Farmaco* farmacoF4 = new Farmaco("M1", "Desc 4", diagD4);
        Farmaco* farmacoF5 = new Farmaco("M2", "Desc 5", diagD5);
        Farmaco* farmacoF6 = new Farmaco("M3", "Desc 6", diagD6);

        Farmaco* farmacoAgregar[6];
        farmacoAgregar[0] = farmacoF1;
        farmacoAgregar[1] = farmacoF2;
        farmacoAgregar[2] = farmacoF3;
        farmacoAgregar[3] = farmacoF4;
        farmacoAgregar[4] = farmacoF5;
        farmacoAgregar[5] = farmacoF6;

        FabricaCConsulta::getCConsulta()->agregarDatosFarmacos(farmacoAgregar, 6);


        Agregar Tratamiento Quirúrgico
        agregarTratamientoQuirurgico("Q1", usuarioJM, new Fecha(2014, 7, 25), "Desc 11", diagD2);
        agregarTratamientoQuirurgico("Q2", usuarioDC, new Fecha(2015, 2, 1), "Desc 22", diagD3);
        */
        cout<< "Datos agregados exitosamente\n";
        hayDatos = true;
    }
}
