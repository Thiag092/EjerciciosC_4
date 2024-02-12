#include <stdio.h>
#include <string.h>

typedef char tc_cadena[20];
typedef struct{
	long DNI;
	tc_cadena nombre;
	tc_cadena apellido;
	int tipoBeca;
	float promedio;
}tr_registro;

void iniciarArchivo();
void pregunta();
void procesarArchivo();
void ingresarDato();
void grabarDato();
void finalizarArchivo();

tr_registro vr_registro;
FILE*vf_registroBecas;
char respuesta;

int main (){
	iniciarArchivo();
	procesarArchivo();
	finalizarArchivo();
	return 0;
}
void iniciarArchivo(){
	vf_registroBecas=fopen("Lista Becarios.dat", "wb");
	if(vf_registroBecas!=NULL){
		printf("El registro fue creado con exito!\n");
	}else{
		printf("HA OCURRIDO UN ERROR!\n");
		finalizarArchivo();
	}
}

void procesarArchivo(){
	 pregunta();
	 
	 while(respuesta=='s' || respuesta =='S'){
	 	ingresarDato();
	 	grabarDato();
		pregunta();
	 }
}
void ingresarDato(){
	printf("Ingrese DNI\n");
		fflush(stdin);

	scanf("%l", &vr_registro.DNI);
	
	printf("Ingrese nombre\n");
		fflush(stdin);

	scanf("%s", &vr_registro.nombre);
	
	printf("Ingrese apellido\n");
		fflush(stdin);

	scanf("%s", &vr_registro.apellido);
	
/*	printf("Ingrese tipo de beca (1-comedir/2. transporte/3.estimulo/4.finalizacion)\n");
	fflush(stdin);
	scanf("%d", vr_registro.tipoBeca);*/
	
	printf("Ingrese promedio\n");
		fflush(stdin);

	scanf("%f", &vr_registro.promedio);
}
void pregunta(){
	printf("Desea ingresar un nuevo registro?S/N)\n" );
	fflush(stdin);
	scanf("%c", &respuesta);
}
void grabarDato(){
	fwrite(&vr_registro, sizeof(tr_registro), 1, vf_registroBecas);
}
void finalizarArchivo(){
	printf("Final del Registro");
	fclose(vf_registroBecas);
}


