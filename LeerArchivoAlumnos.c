#include <stdio.h>
#include <string.h>

/* 	1.leer un registro
	2. recorrer mientras no sea el fin **  ! feof(vf_alumnos) **
		2.1 mostrar alumno
		2.1 contar alumno 
		2.2 leer otro registro 
*/

/*typedef char tc_cadCar[30]; */
	
typedef struct {
	int dni;
	short cod_carrera;
	char cod_genero;
	short edad;
}tr_alumno;	

void iniciarProceso();
void leerMostrarAlumnos();
void finalizarProceso();

tr_alumno vr_alumno;
FILE * vf_alumnos;
int contAlumnos;

int main() {
	iniciarProceso();	
	leerMostrarAlumnos();		
	finalizarProceso();	
	return 0;
}

void iniciarProceso() {
	/* Abrir un archivo (fopen) binario en modo lectura (rb) */
	vf_alumnos = fopen("Alumnos.dat", "rb");
	printf("*** Listado de alumnos*** \n");
	contAlumnos = 0;
}

void leerMostrarAlumnos() {
	fread( &vr_alumno, sizeof(tr_alumno), 1, vf_alumnos );
	while ( ! feof(vf_alumnos) ) {
		
		printf("\n%d\t%d\t%c\t%d", vr_alumno.dni, vr_alumno.cod_carrera, vr_alumno.cod_genero, vr_alumno.edad);
		contAlumnos ++;
		fread( &vr_alumno, sizeof(tr_alumno), 1, vf_alumnos );
	}
}

void finalizarProceso() {
	/* Se cierra el archivo */
	fclose( vf_alumnos );
	printf("\n\nCantidad de alumnos registrados: %d\n", contAlumnos);
}
