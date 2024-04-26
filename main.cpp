// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 2
// main.cpp
#include <string.h>
#include <iostream>
using namespace std;

int main (){
	int option=-1;

	while(option !=6){
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
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	std::cout << "Chau\n";
	return 0;
}
