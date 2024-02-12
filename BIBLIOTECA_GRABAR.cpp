#include <stdio.h>
#include <string.h>

typedef char tc_string[30];
typedef struct{
	int isbn;
	tc_string titulo;
	tc_string autor;
	int anio;
	tc_string editorial;
}tr_registro;

void iniciarArchivo();
void pregunta();
void procesarRegistro();
void ingresarRegistro();
void grabarRegistro();
void finalizarRegistro();

tr_registro vr_biblioteca;
FILE*vf_biblioteca;
char respuesta;

int main(){
	iniciarArchivo();
	procesarRegistro();
	finalizarRegistro();
	return 0;
}

void iniciarArchivo(){
	vf_biblioteca=fopen("Registro biblioteca.dat", "wb");
	if (vf_biblioteca!=NULL){
		printf("EL REGISTRO HA SIDO ENCONTRADO!\n");
	}else{
		printf("HA OCURRIDO UN ERROR!");
		finalizarRegistro();
	}
}
void procesarRegistro(){
	pregunta();
	while(respuesta=='s' || respuesta=='S'){
		ingresarRegistro();
		grabarRegistro();
		pregunta();
	}
}
void pregunta(){
	printf("Desea ingresar un nuevo Registro? S/N: \n");
	fflush(stdin);
	scanf("%c", &respuesta);
}
void ingresarRegistro(){
	printf("Ingrese numero de identificacion del libro: \n");
	fflush(stdin);
	scanf("%d", &vr_biblioteca.isbn);
	
	printf("Ingrese titulo del libro: \n");
	fflush(stdin);
	scanf("%s", &vr_biblioteca.titulo);
	
	printf("Ingrese autor del libro: \n");
	fflush(stdin);
	scanf("%s", &vr_biblioteca.autor);
	
	printf("Ingrese anio del libro: \n");
	fflush(stdin);
	scanf("%d", &vr_biblioteca.anio);
	
	printf("Ingreseeditorial del libro: \n");
	fflush(stdin);
	scanf("%s", &vr_biblioteca.editorial);
	
}
void grabarRegistro(){
	fwrite(&vr_biblioteca, sizeof(tr_registro), 1, vf_biblioteca);
}
void finalizarRegistro(){
	printf("CARGA DE REGISTRO FINALIZADA\n");
	fclose(vf_biblioteca);
}
