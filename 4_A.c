#include <stdio.h>
typedef struct{
	int dni;
	int codCar;
	char codGen;
	int edad;
}tr_alumnos;

void iniciarArchivo();
void preguntaIngreso();
void ingresarDatos();
void grabarDatos();
void procesarDatos();
void imprimirResultados();
void finalizarPrograma();

tr_alumnos vr_alumnos;
FILE * vf_registroAlumnos;
char opcion;

int main (){
	iniciarArchivo();
	procesarDatos();
	finalizarPrograma();
	
	return 0;
}
void iniciarArchivo(){
	vf_registroAlumnos=fopen("RegistroAlumnos22.dat", "ab");
	
	if(vf_registroAlumnos!=NULL){
		printf("El archivo fue creado con exito!\n");}
		else{
			printf("OCURRIO UN ERROR\n");
		}
}
void procesarDatos(){
	preguntaIngreso();
	while(opcion=='s' || opcion=='S'){
		ingresarDatos();
		grabarDatos();
		preguntaIngreso();
	}
}
void ingresarDatos(){
	printf("Ingrese DNI del alumno: \n");
	scanf("%d", &vr_alumnos.dni);
	
	printf("Ingrese codigo de carrera del alumno (18-LSI, 19 CS. BIO, 20 AGRIMENSURA, 20 BIOQ., 29 ING. ELEC): \n");
	scanf("%d", &vr_alumnos.codCar);
	
	printf("Ingrese codigo de Genero del alumno (M-MUJER; V-VARON, X-OTRO):\n");
	scanf("%c", &vr_alumnos.codGen);
	
	printf("Ingrese edad del alumno: \n");
	scanf("%d", &vr_alumnos.edad);
	
}
void grabarDatos(){
	fwrite(&vr_alumnos, sizeof(tr_alumnos), 1, vf_registroAlumnos);
	printf ("Registro de alumno ha sido insertado!\n");
}
void preguntaIngreso(){
	printf("Desea ingresar algun dato? S/N\n");
	fflush(stdin);
	scanf("%s", &opcion);
}
void finalizarPrograma(){
	fclose(vf_registroAlumnos);
}
