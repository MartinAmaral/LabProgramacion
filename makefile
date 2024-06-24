# Variables
CC = g++
OPCIONES = -g -Wall -std=c++11

# Archivos de objeto
CONTROLLERS = controllers/CConsulta.o controllers/CUsuarioYSesion.o
DTS = dts/fecha.o dts/infoUsuarioDT.o dts/datosDiagnostico.o dts/consultaDia.o
ENTIDADES = entidades/administrativo.o entidades/categoria.o \
            entidades/consulta.o entidades/consultaComun.o \
            entidades/consultaEmergencia.o entidades/farmaco.o \
            entidades/medicamento.o entidades/medico.o \
            entidades/quirurgico.o entidades/representacionE.o \
            entidades/tratamiento.o entidades/usuario.o entidades/socio.o entidades/diagnostico.o 

FABRICAS = fabricas/fabricaCConsulta.o fabricas/fabricaCUsuario.o

MENU = menus/menuAgregarDatos.o menus/menuConsulta.o menus/menuSesion.o

# Todos los objetos
OBJETOS = $(CONTROLLERS) $(DTS) $(ENTIDADES) $(FABRICAS) $(INTERFACES) $(MENU)

# Target
all: main

main: $(OBJETOS) main.o
	$(CC) $(OPCIONES) $(OBJETOS) main.o -o main

# Reglas de compilación para cada archivo de objeto
controllers/%.o: controllers/%.cpp controllers/%.h
	$(CC) $(OPCIONES) -c $< -o $@

dts/%.o: dts/%.cpp dts/%.h
	$(CC) $(OPCIONES) -c $< -o $@

entidades/%.o: entidades/%.cpp entidades/%.h
	$(CC) $(OPCIONES) -c $< -o $@

fabricas/%.o: fabricas/%.cpp fabricas/%.h
	$(CC) $(OPCIONES) -c $< -o $@

interfaces/%.o: interfaces/%.cpp interfaces/%.h
	$(CC) $(OPCIONES) -c $< -o $@

menus/%.o: menus/%.cpp menus/%.h
	$(CC) $(OPCIONES) -c $< -o $@

main.o: main.cpp
	$(CC) $(OPCIONES) -c $< -o $@

# Clean
clean:
	rm -f $(OBJETOS) main main.o
