#include <iostream>
#include <string>
#include <limits>
#include "menuSesion.h"
#include "../Interfaces/ICUsuarioYSesion.h"
#include "../fabricas/fabricaCUsuario.h"
#include "../dts/infoUsuarioDT.h"

using namespace std;

bool contrasenaValida(string contra){
    if(contra.length() <6 || contra.length() >9 )
        return false;
    for (char ch : contra) {
        if (!std::isalpha(ch) && !std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

void MenuSesion::iniciarSesion(){
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario(); 

    if(controllerSesion->getUsuarioActivo() != NULL){
        cout<<"Ya hay una sesion iniciada\n";
        return;
    }
    int cedula = -33;
    cout << "Ingrese su cedula (solo numero) o -1 para cancelar:\n";
    do {
        cin >> cedula; 
	    if(cin.fail() || cedula<0){
		    if (cedula == -1){
                return;
            }
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        cedula = -33;
        } 
       else if(!controllerSesion->existeUsuario(cedula)){ 
            std::cout << "\nLa cedula ingresada no existe en el sistema, intentelo de nuevo.\n\n";
            cedula = -33;
        } 
        else{
            controllerSesion->recordarCiIS(cedula);
        }
    }while(cedula == -33);

    if (controllerSesion->esAdminDefecto()){
        string contra = "";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
        cout << "\nBienvenido/a Admin. Ingrese su contrasena o salir para salir: ";
        std::cin >> contra; 

        while(!controllerSesion->ingresarPassIS(contra)){
            if(contra == "salir"){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            std::cout << "\nContrasena invalida, intentelo de nuevo o escriba salir para salir.\n\n";
            std::cin >> contra; 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controllerSesion->asignarSesionDefecto();
        cout<< "\nSesion Admin Default iniciada \n";
        return;
    }
    else if (controllerSesion->usuarioSinContrasena()) { //primera vez que entra al sistema
	    string nuevaContra = "";
        std::cout << "\nUsuario sin contrasena. Ingrese su contrasena para ser guardada por el sistema. \n";
	    std::cout << "La contrasena debe ser de entre 6 y 9 caracteres largo y caracteres alfanumericos.\n";
	    std::cout << "Escriba salir para volver al menu principal.\n";
        
        cin >> nuevaContra;
        while (!contrasenaValida(nuevaContra)) {
            if(nuevaContra == "salir"){
                return;
            }
            cout << "Ingrese una contrasena valida o escriba 'salir' para salir\n";
            cin >> nuevaContra;
        }
        controllerSesion->asignarContrasena(nuevaContra);
        controllerSesion->asignarSesion();
        cout <<"\nLa Sesion ha sido asginada con exito.Bienvenido\n";
    }
    else{
        string contra = "";
        cout << "\nIngrese su contrasena o 'salir' para salir:\n";
        cin >> contra; 
        while (!contrasenaValida(contra)) { 
            if(contra == "salir"){
                return;
            }
            cout << "\nIngrese una contrasena valida o escriba 'salir' para salir\n";
            cin >> contra; 
        }
        if (!controllerSesion->esActivoIS()){
            cout << "\nUsuario inactivo, no se puede realizar el inicio de sesión\n";
            return;
        }
        controllerSesion->asignarSesion();
        cout <<"\nLa Sesion ha sido asginada con exito.Bienvenido\n";
    }
}

void MenuSesion::cerrarSesion(){
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario(); 

    if (controllerSesion->getUsuarioActivo() == NULL){
        cout << "No hay ninguna sesion iniciada.!\n";
    }
    else{
        controllerSesion->cerrarSesion();
        cout << "La Sesion ha sido cerrada con exito.\n";
    }
}

void MenuSesion::altaUsuario(){
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario();
    if (controllerSesion->getUsuarioActivo() == NULL){
        cout << "No hay ninguna sesion iniciada.!\n";
        return;
    }
    if (controllerSesion->getTipoUsuarioActivo() == Admin || controllerSesion->getTipoUsuarioActivo() == SocioAdmin ){
    }
    else{
        cout<< "Se necesita a un Usuario administrativo para dar de alta o Reactivar a un usuario.\n";
        return;
    }

    int cedula = -33;
	do{
        cout << "\nIngrese la cedula a dar de alta o reactivar o ingrese -1 para salir.\n";
        cin >> cedula; 

        if(cin.fail() || cedula<0 || cedula ==26){
	        if (!cin.fail() && cedula == -1) return;
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            darAlta(cedula);
            cout <<"!!!Caso con la cedula: " <<cedula <<" terminado\n";
            cedula = -33;
        }
        cedula = -33;
    }while(cedula == -33);
}

void MenuSesion::darAlta(int cedula){

    if (controllerSesion->existeUsuario(cedula)){
       
        InfoUsuarioDT* info = controllerSesion->devolverInfo(cedula);
        
        cout << "Nombre: " << info->getNombre() << " Apellido: " << info->getApellido() << "\n";
        
        string sexo;
        if(info->getSexo() == Masculino)
            sexo= "Masculino";
        else sexo = "Femenino";
        cout << "Sexo: " << sexo << " Edad: " << info->getFechaNacimiento()->getEdad() << "\n";

        cout << "Categorias: ";

        switch (info->getTipo()) {
            case Admin:
                cout <<"Administrativo";
            break;
            case Socio:
                cout << "Socio";
                break;
            case Medico:
                cout <<"Medico";
                break;
            case SocioAdmin:
                cout <<"Socio y Administrativo";
                break;
            case SocioMedico:
                cout <<"Socio y Medico";
                break;
        }

        cout <<"\n";

        if(controllerSesion->esActivo(cedula)){
            cout << "El usuario se encuentra activo\n";
        }
        else cout << "El usuario se encuentra inactivo\n";

        delete info;

        if(!controllerSesion->esActivo(cedula)){
            cout << "Quiere reactivar a este Usuario?\n";
            int valor =-1;
            do{
                cout<< "Ingresa 1 para reactivar el usuario y 0 para no \n";
                cin >> valor; 
                if(cin.fail() || valor<0 || valor >1){
                    cin.clear(); 
	                cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valor = -1;
                }
            }while(valor<0);
            if(valor == 1){
                controllerSesion->reactivarUsuario(cedula);
                cout << "El usuario con cedula: " << cedula << "ha sido reactivado\n";
            }
            else cout << "El usuario no ha sido reactivado\n";
            return;
        }
    }
    else {
        cout << "\nUsuario no se encuentra el sistema\n";
        cout << "Ingrese los datos del usuario a dar de alta\n";

        string nombre;
        cout << "\nIngrese el nombre: ";
        cin >> nombre;
        
        string apellido;
        cout << "\nIngrese el apellido: ";
        cin >> apellido;

        int sexoN = -1;
        do{
            cout<< "\nIngrese 1 para Masculino o 0 para Femenino \n";
            cin >> sexoN; 
            if(cin.fail() || sexoN<0 || sexoN >1){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                sexoN = -1;
            }
        }while(sexoN<0);

        Sexo sexo; 
        if(sexoN ==1)
            sexo = Masculino;
        else sexo = Femenino;
        
        Fecha* fecha;
        int dia = -1;
        do{
            cout<< "\nIngrese el dia de nacimiento: \n";
            cin >> dia; 
            if(cin.fail() || dia<=0 || dia >31){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                dia = -1;
            }
        }while(dia<0);
        
        int mes = -1;
        do{
            cout<< "\nIngrese el mes de nacimiento: \n";
            cin >> mes; 
            if(cin.fail() || mes<=0 || mes >12){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                mes = -1;
            }
        }while(mes<0);
        
        int ano = -1;
        do{
            cout<< "\nIngrese el ano de nacimiento: \n";
            cin >> ano; 
            if(cin.fail() || ano<0 || ano >2024){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ano = -1;
            }
        }while(ano<0);

        fecha = new Fecha(ano, mes, dia);

        int tipoN = -1;
        do{
            cout<< "\nIngrese 0 para cancelar la alta de usuario\n";
            cout <<"Ingrese 1 para socio, 2 para medico, 3 para admin, 4 para socio-medico, 5 para socio-admin:\n";
            cin >> tipoN; 
            if(cin.fail() || tipoN<0 || tipoN >5){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tipoN = -1;
            }
        }while(tipoN<0);
        
        if (tipoN == 0){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            delete fecha;
            cout<<"Alta de Usuario cancelada!\n";
            return;
        }
        
        TipoUsuario tipo;

        if(tipoN == 1)
            tipo = Socio;
        else if (tipoN == 2)
            tipo = Medico;
        else if (tipoN == 3)
            tipo = Admin;
        else if (tipoN ==4)
            tipo = SocioMedico;
        else if (tipoN ==5)
            tipo = SocioAdmin;

        InfoUsuarioDT* infoDt = new InfoUsuarioDT(nombre,apellido,sexo,fecha,tipo);
        controllerSesion->altaUsuario(infoDt,cedula);    

        cout <<"\nUsuario dado de alta existosamente!\n";
        return;
    }
}

