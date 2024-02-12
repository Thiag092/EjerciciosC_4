#include <stdio.h>
#include <string.h>

char frase [20];
int i, espacios, longitud;

int main (){
	
	printf ("Ingrese frase: \n");
	scanf ("%[^\n]s", &frase);
	
	for (i=0;i<= strlen(frase);i++){
		
		if (frase[i]== ' '){
			espacios=espacios+1;
		}
	}
	printf ("\t1La cantidad de palabras que tiene la frase es de: %d", espacios+1);
	
	return 0;
}
