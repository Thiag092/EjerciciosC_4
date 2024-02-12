#include <stdio.h>
#include <string.h>

void ingresarDatos();
void procesarDatos();
void imprimirDatos();

char frase[20];
int i, contador, auxiliar;

int main (){
	ingresarDatos();
	procesarDatos();
	imprimirDatos();
	
	return 0;
}
void ingresarDatos(){
	printf ("Ingrese titulo de la obra a cargar: \n");
	scanf ("%[^\n]s", &frase);
}
void procesarDatos(){
	auxiliar=strlen(frase);
	for (i=0;i<=auxiliar;i++){
		if (frase[i]==' '){
			contador=contador+1;
		}
	}
	
}
void imprimirDatos(){
	printf ("El titulo de la obra ingresado es: %s\n", strupr(frase));
	printf ("La cantidad de palabras de dicho titulo es de: %d", contador+1);
}
