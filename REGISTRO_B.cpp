#include <stdio.h>
void inicarArchivo();
void preguntar();
void grabarAlumno();
void agregarAlumnos();
void finalizarProceso();

FILE * vf_alumnos;
char respuesta;
int main (){
	inicarArchivo();
	grabarAlumno();
	finalizarProceso();
	return 0;
}
void inicarArchivo(){
	vf_alumnos=fopen("Alumnos.txt", "a");
	if (vf_alumnos !=NULL){
	
	printf ("Archivo creado!\n");	}
}
void preguntar(){
	printf ("Desea ingresar registro? S/N\n");
	scanf("%c", &respuesta);
}
void grabarAlumno(){
	preguntar();
	while (respuesta == 's' || respuesta == 'S'){
		agregarAlumnos();
		preguntar();
		}	
}
void agregarAlumnos(){

	printf ("Ingrese nombre del alumno: \n");
	scanf("%c", &vf_alumnos);
	printf ("Ingrese DNI del alumno: \n");
	scanf("%c", &vf_alumnos);
}
void finalizarProceso(){
	fclose(vf_alumnos);
}
