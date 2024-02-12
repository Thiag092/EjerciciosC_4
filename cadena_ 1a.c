#include <stdio.h>
#include <string.h>

void ingresarDatos();
void procesarDatos();
void imprimirDatos();

char nombre [20];
char apellido[20];
char nombreCompleto[20];


int main (){
	ingresarDatos();
	procesarDatos();
	imprimirDatos();
	return 0;
}

void ingresarDatos(){
	char opcion;
	
	printf ("Desea ingresar un nuevo dato? S/N \n");
	scanf ("%s", &opcion);
	while (opcion == 's' || opcion == 'S'){
		
	printf ("Ingrese nombre: \n");
	scanf ("%s", &nombre);
	
	printf ("Ingrese apellido: \n");
	scanf ("%s", &apellido);
	printf ("Desea ingresar un nuevo dato? S/N \n");
	scanf ("%s", &opcion);
	}
}

void procesarDatos(){
	strcat(nombre, " ");
	strcat(nombre, apellido);
	
}
void imprimirDatos(){
	printf ("El nombre Ingreasdo es: %s\n", nombre);
	printf ("La longitud de la cadena es de: %d", strlen(nombre));
}
