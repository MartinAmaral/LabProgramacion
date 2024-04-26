// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 1
// main.cpp
#include <string.h>
#include <iostream>
#include "empresa.h"
#include "empleado.h"
#include "empleadojornalero.h"
#include "empleadofijo.h"
using namespace std;

void CrearEmpresa(Empresa*& empresa){
	if(empresa == NULL){
		string nombre;
		string nombreLegal;
		int rut= -1;

		cout << "Ingrese el nombre\n";
		cin >> nombre;

			cout << "Ingrese el nombre Legal\n";
			cin >> nombreLegal;

		do{
			cout << "Ingrese el rut\n";
			cin >> rut;
			if(std::cin.fail() || rut<0)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					rut = -1;
				}
		}while(rut <0);
		empresa= new Empresa(nombre,nombreLegal,rut,NULL);
		cout<< "\nEmpresa Creada\n\n";
	}
	else {
		cout<< "\nEmpresa ya creada\n\n";
	}
}

void CrearEmpleado(Empresa*& empresa){
	if(empresa == NULL){
		cout << "Empresa no creada\n";
		return;
	}
	string nombre;
    string id;
    int edad = -1;

	cout << "Ingrese el nombre del empleado\n";
	cin >> nombre;
	cout << "Ingrese el id del empleado\n";
	cin >> id;
	do{
			cout << "Ingrese la edad\n";
			cin >> edad;
			if(std::cin.fail() || edad<0)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					edad = -1;
				}
		}while(edad <0);

	float monto = -1;

	do{
			cout << "Ingrese el sueldo\n";
			cin >> monto;
			if(std::cin.fail() || monto<0)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					monto= -1;
				}
		}while(monto <0);

	int moneda = -1;
	do{
			cout << "Ingrese 0 para pesos o 1 para dolares\n";
			cin >> moneda;
			if(std::cin.fail() || moneda<0 || moneda >1)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					moneda= -1;
				}
		}while(moneda <0);

	int tipo = -1;
	do{
			cout << "Ingrese 0 para jornalero o 1 para fijo\n";
			cin >> tipo;
			if(std::cin.fail() || tipo<0 || tipo >1)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					tipo= -1;
				}
		}while(tipo <0);
	
	Paga* paga= NULL;

	if(moneda ==0){
		paga = new Paga(monto,Moneda::us);
	}
	else {
		paga = new Paga(monto,Moneda::usd);
	}
	
	Empleado* empleado = NULL;
	if(tipo == 1){
		empleado = new EmpleadoFijo(nombre,id,edad,paga,empresa);
	}
	else{
		int horasJ =-1;
		do{
			cout << "Ingrese las horas del jornalero\n";
			cin >> horasJ;
			if(std::cin.fail() || horasJ<0)
				{
					std::cin.clear();
					std::cin.ignore(100,'\n');
					std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
					horasJ= -1;
				}
		}while(horasJ <0);
		EmpleadoJornalero* temp  = new EmpleadoJornalero(nombre,id,edad,paga,empresa);
		temp->setHoras(horasJ);
		empleado = temp;
	}
	Empleado** empleados = empresa->getEmpleados();

	for (int i = 0; i < MAX_EMPLEADO; i++){
		if(empleados[i] == NULL){
			empleados[i] = empleado;
			break;
		}
	}
	cout << "Empleado agregado\n";
}

void BorrarEmpresa(Empresa*& empresa){

	if(empresa == NULL){
		cout << "No hay empresa\n";
	}
	else {
		delete(empresa);
		empresa = NULL;
	}
	cout << "Empresa eliminada\n";
}

void BorrarEmpleados(Empresa*& empresa){
	if(empresa == NULL){
		cout << "Empresa no creada\n";
		return;
	}
	Empleado** empleados = empresa->getEmpleados();

	for (int i = 0; i < MAX_EMPLEADO; i++){
		if(empleados[i] != NULL){
			delete(empleados[i]);
			empleados[i]= NULL;
		}
		else break;
	}
	cout << "Empleados eliminados\n";
}

void CalcularTotalSueldosUru(Empresa* empresa){
	if(empresa == NULL){
		cout << "Empresa no creada\n";
		return;
	}
	float total = empresa->total_sueldo_peso();
	cout << "El total de sueldos en la empresa en pesos es: " << total << "\n";
}

void CalcularTotalSueldosUsd(Empresa* empresa){
	if(empresa == NULL){
		cout << "Empresa no creada\n";
		return;
	}
	float total = empresa->total_sueldo_dolar();
	cout << "El total de sueldos en la empresa en dolares es: " << total << "\n";
}

int main (){
	int option=-1;

	Empresa * empresa = NULL;
	while(option !=6){
		option = -1;

		while(option <0)
		{
			std::cout << "0: Crear Empresa\n1: Crear Empleado \n2: Borrar Empresa y Empleados\n";
			std::cout << "3: Borrar Empleados \n4: Calcular sueldo de Empleado uru\n";
			std::cout << "5: Calcular sueldo de Empleado dolares\n6: Salir\nOpcion: ";
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
			CrearEmpresa(empresa);
			break;
		case 1:
			CrearEmpleado(empresa);
			break;
		case 2:
			BorrarEmpresa(empresa);
			break;
		case 3:
			BorrarEmpleados(empresa);
			break;
		case 4:
			CalcularTotalSueldosUru(empresa);
			break;
		case 5:	
			CalcularTotalSueldosUsd(empresa);
			break;
		default:
			break;
		}
	}
	std::cout << "Chau\n";
	return 0;
}
