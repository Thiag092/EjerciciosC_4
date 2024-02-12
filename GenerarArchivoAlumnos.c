#include <stdio.h>
#include <string.h>
/* 	Crear un tipo de registro alumnos de FACENA que contenga los siguientes campos: 
		DNI, Cod de Carrera, Cod. Sexo, Edad. 
	Luego crear una variable de este tipo. 
	Utilizar el formato de struct y typedef  
*/	

/*typedef char tc_cadCar[30]; */
	
typedef struct {
	int dni;
	short cod_carrera;
	char cod_genero;
	short edad;
}tr_alumno;	

void iniciarProceso();
void ingresarGrabarAlumnos();
void finalizarProceso();
void ingresarDatos();

tr_alumno vr_alumno;
FILE * vf_alumnos;

int main() {
	iniciarProceso();
	ingresarGrabarAlumnos();
	finalizarProceso();
	return 0;
}

void iniciarProceso() {
	/* Se crea un archivo nuevo (fopen) y se abre en modo escritura (wb) */	
	vf_alumnos = fopen("Alumnos.dat", "wb");
	printf( "\tArchivo creado! \n" );
}

void ingresarGrabarAlumnos() {
	/* Se graba 1 registro en el archivo de Alumnos --> fwrite */
	char opcion = 's';
	while (opcion !='n') {
		ingresarDatos();
		
		fwrite( &vr_alumno, sizeof( tr_alumno ), 1, vf_alumnos );
			
		
		printf("Cargar otro? s-n");
		fflush(stdin);
		scanf("%c", &opcion);
	}	
}

void ingresarDatos() {
	printf("Ingresar alumno: \n");
	printf("\tDNI: ");
	scanf("%d", &vr_alumno.dni);
/*
	printf("\tNombre: ");
	fflush(stdin);
	scanf("%[^\n]s", &vr_alumno.nombre);
*/
	
	printf("\tCod Carrera (18-LSI 19-Lic. Bio 20-Agrimensura 28-Bioq. 29-Ing. Elect): ");
	scanf("%d", &vr_alumno.cod_carrera);
	
	printf("\tCod Genero (v-varon m-mujer x-otro): ");
	fflush(stdin);
	scanf("%c", &vr_alumno.cod_genero);
	
	printf("\tEdad: ");
	scanf("%d", &vr_alumno.edad);
}

void finalizarProceso() {
	/* Se cierra el archivo fclose	*/
	fclose(vf_alumnos);
}





