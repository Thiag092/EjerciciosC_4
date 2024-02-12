#include <stdio.h>
#include <string.h>

void ingresarDatos();
void procesarDatos();
void imprimirDatos();

char frase [30];
int i, contador, auxiliar;

int main (){
	ingresarDatos();
	procesarDatos();
	imprimirDatos();
	
	return 0;
}
void ingresarDatos(){
	printf ("Ingrese frase: \n");
	scanf ("%[^\n]s", &frase);
}
void procesarDatos(){
	auxiliar= strlen(frase);
	
	for(i=0;i<=auxiliar;i++){
		if(frase[i]== 'a' || frase[i]== 'A'){
			contador= contador +1;
		}
	}
}
void imprimirDatos(){
	printf ("La frase ingresada es: %s\n", frase);
	printf ("La cantidad de veces que se repite la letra 'A' es de %d veces", contador);
}
