#include <stdio.h>
#include <string.h>
#define CARRERAS 5

typedef int tv_vector[CARRERAS] ;

typedef struct{
	int dni;
	int codCar;
	char codGen;
	int edad;
}tr_alumnos;

void iniciarArchivo();
void procesarDatos();
void leerRegistro();
void imprimirResultados();
void mayorCarrera();
void calcularLsi();
void cantidadVaronesLsi();
void promedioEdades();
void porcentajeLsi();
void finalizarPrograma();

int alumnosLsi, cantMujeres, i, carreraMayor, varonesLsi;
int mayor=-1;
int cantidadAlumnos=0;
float porcentaje;
tv_vector vv_carreraMayor;
tv_vector vv_edades;
tr_alumnos vr_alumnosLeer;
FILE*vf_alumnosLeer;

int main(){
	iniciarArchivo();
	procesarDatos();
	finalizarPrograma();
	return 0;
}
void iniciarArchivo(){
	vf_alumnosLeer=fopen("RegistroAlumnos22.dat", "rb");
	if(vf_alumnosLeer!=NULL){
		printf("El registro ha sido encontrado!\n");
	}
}
void procesarDatos(){
	leerRegistro();
	while(!feof(vf_alumnosLeer)){
		 calcularLsi();
		 promedioEdades();
		  cantidadVaronesLsi();
		 mayorCarrera();
		imprimirResultados();
		leerRegistro();
		cantidadAlumnos=cantidadAlumnos+1;
	}
	porcentajeLsi();
}
void leerRegistro(){
	fread(&vr_alumnosLeer, sizeof(tr_alumnos), 1, vf_alumnosLeer);
}
void imprimirResultados(){
	printf("\nDNI: %d| - CODIGO CARRERA: %d| -GENERO: %c| - EDAD: %d| \n", vr_alumnosLeer.dni,vr_alumnosLeer.codCar, vr_alumnosLeer.codGen, vr_alumnosLeer.edad);
	
}
void calcularLsi(){
	if(vr_alumnosLeer.codCar==18){
		alumnosLsi++;
	}
}
void porcentajeLsi(){
	porcentaje=(float)(alumnosLsi*cantidadAlumnos)/100;
}
void calcularMujeresMenores(){
	if(vr_alumnosLeer.codGen=='m'&&vr_alumnosLeer.codCar==29){
		cantMujeres++;
	}
}
void mayorCarrera(){
	vv_carreraMayor[vr_alumnosLeer.codCar]=vv_carreraMayor[vr_alumnosLeer.codCar]+1;
	
	for(i=0;i<CARRERAS;i++){
		if(vv_carreraMayor[i]>mayor){
			mayor=vv_carreraMayor[i];
			carreraMayor=i;
		}
	}
}
void cantidadVaronesLsi(){
	if(vr_alumnosLeer.codCar=='v'&&vr_alumnosLeer.codCar==18){
		varonesLsi++;
	}
}
void promedioEdades(){
	vv_edades[vr_alumnosLeer.edad]=	vv_edades[vr_alumnosLeer.edad]+	vv_edades[vr_alumnosLeer.edad];
}

void finalizarPrograma(){
		printf("\n**********************************************************************************************************");
		printf("\n");
		printf("\nLa cantidad de alumnos de LSI es de: %d\n", alumnosLsi);
		printf("\nLa cantidad de alumnos registrados es de: %d\n", cantidadAlumnos);
		printf("\nEl porcentaje de alumnos de LSI sobre el total es de: %% %.2f\n", porcentaje);
		printf("\nLa carrera con mayor cantidad de alumnos es de: %d\n", carreraMayor);
		printf("\nLa cantidad de alumnos varones en LSIs es de: %d\n", varonesLsi);
		for(i=0;i<)
		printf("El promedio de esades de los isncriptos es de : %d", vv_edades[i]);
		printf("\nLa cantidad de mujeres menores de 25 en Ing. Electronica es de: %d\n", cantMujeres);

		fclose(vf_alumnosLeer);
}
