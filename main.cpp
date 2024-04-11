// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 1
// main.cpp
#include <string.h>
#include <iostream>
#include "empresa.h"
#include "empleado.h"

using namespace std;

void CrearEmpresa(Empresa*& empresa){
	if(empresa == NULL){
		empresa = new Empresa();
		cout<< "\nEmpresa Creada\n\n";
	}
	else {
		cout<< "\nEmpresa ya creada\n\n";
	}
}
void CrearEmpleado(){

}

void BorrarEmpresa(){

}
 void BorrarEmpleados(){

}
void BorrarEmpleadoPorNombre(){

}

void CalcularSueldoUru(){


}

void CalcularSueldoUsa(){

}

void CalcularTotalSueldosUru(){

}

void CalcularTotalSueldosUsd(){

}

int main (){
	int option=-1;

	Empresa * empresa = NULL;

	while(option !=9){
		option = -1;

		while(option <0)
		{
			std::cout << "0: Crear Empresa\n1: Crear Empleado \n2: Borrar Empresa y Empleados \n3: Borrar Empleados \n4: Borrar Empleado por Nombre\n";
			std::cout << "5: Calcular sueldo de Empleado uru\n6: Calcular sueldo de Empleado usd\n";
			std::cout << "7: Calcular sueldo total de Empleados uru\n8: Calcular sueldo total de Empleados usd\n";
			std::cout << "9: Salir\nOpcion: ";
			std::cin >> option;
			if(std::cin.fail() || option >9 || option<0)
			{
				std::cin.clear();
				std::cin.ignore(100,'\n');
				std::cout << "Opcion invalida, intentelo de nuevo.\n";
			}
		}

		switch (option)
		{
		case 0:
			CrearEmpresa(empresa);
			break;
		case 1:
			CrearEmpleado();
			break;
		case 2:
			BorrarEmpresa();
			break;
		case 3:
			BorrarEmpleados();
			break;
		case 4:
			BorrarEmpleadoPorNombre();
			break;
		case 5:
			CalcularSueldoUru();
			break;
		case 6:
			CalcularSueldoUsa();
			break;
		case 7:
			CalcularTotalSueldosUru();
			break;
		case 8:
			CalcularTotalSueldosUsd();
			break;
		default:
			break;
		}
	}
	std::cout << "Chau\n";
	return 0;
}
