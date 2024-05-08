// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 2
// main.cpp
#include <string.h>
#include <iostream>
#include "usuario.h"
using namespace std;

bool inicioSesion = false;
int cedulaAdmin = 26;

void AltaUsuario(Usuario* usuario){

	if(usuario->getCI() != 26){
		cout << "Error: Se necesita ser un usuario Administrativo para poder realizar esta accion.\n";
		return;	
	}
}

void IniciarSesion(Usuario* usuario){
    if(inicioSesion)
    {
        cout << "Error: Ya se encuentra una sesion iniciada\n";
        return;
    }
    int ci = 0;
    while(ci <=0)
    {
        std::cout << "Ingrese su cedula: \n";
        std::cin >> ci; 
        if(std::cin.fail() || ci <=0)
        {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
        }
    }

    if (ci == cedulaAdmin) // es administativo por defecto
    {
        string temp = "";
        while(temp != "default")
        {
            std::cout << "Ingrese la contrasena del usuario administativo: \n";
            std::cin >> ci; 
            if(std::cin.fail() || ci <=0)
            {
                std::cin.clear();
                std::cin.ignore(100,'\n');
                std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                temp = "";
            }
        }

    }
}


void RegistroConsulta(Usuario* usuario){
    if(!inicioSesion)
    {
        cout << "Error: Debe iniciar Sesion\n";
        return;
    }

	int ciMedico = 0;
	while(ciMedico <=0)
	{
		std::cout << "Ingrese la cedula del medico: ";
		std::cin >> ciMedico;

		if(std::cin.fail() || ciMedico <=0)
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
		}
	}
	
	int ciPaciente = 0;
	while(ciPaciente <=0)
	{
		std::cout << "Ingrese la cedula del paciente: ";
		std::cin >> ciPaciente;

		if(std::cin.fail() || ciPaciente <=0)
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
		}
	}
	
	int option = -1;
	while(option <0)
	{
		std::cout << "0: Comun\n1: Emergencia \n";
		std::cin >> option;

		if(std::cin.fail() || option >1 || option<0)
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
		}
	}

	if (option ==0)
	{
		
	}
	else 
	{
	
	}		
}


int main (){
	int option=-1;

    Usuario* usuario = new Usuario(cedulaAdmin,"default");

	while(option !=3){
		option = -1;

		while(option <0)
		{
			std::cout << "0: Alta de usuario\n1: Iniciar Sesion \n";
			std::cout << "2: Registro de Consulta \n3: Salir\n";
			std::cin >> option;

			if(std::cin.fail() || option >6 || option<0)
			{
				std::cin.clear();
				std::cin.ignore(100,'\n');
				std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
			}
		}
		switch (option)
		{
		case 0:
			AltaUsuario(usuario);
			break;
		case 1:
			break;
			IniciarSesion(usuario);
		case 2:
            RegistroConsulta(usuario);
			break;
		default:
			break;
		}
	}
	std::cout << "Chau\n";
	return 0;
}
