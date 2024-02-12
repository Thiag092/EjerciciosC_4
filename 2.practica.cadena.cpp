#include <stdio.h>
#include <string.h>

char cadena1 [20] = "yAgO AlBeRtO aYaLa ";
char cadena2 [20] = "AYALA";
int main (){
	
	//COPIA DE DOS CADENAS*****
//	 strcpy( cadena1,  cadena2);
//	printf ("\t%s\t %s \n", cadena1, cadena2);
//------------------------------------------------------------------------------------------------------------------
	
	//CONCATENA CADENAS**************
//	strcat( cadena1,  cadena2);
//	printf ("\t%s\t %s \n", cadena1, cadena2);
//---------------------------------------------------------------------------------------------------------------------
	
	//LONGITUD DE CADENAS**************
//	printf ("El valor de la cadena es: %s\n", cadena1);
//	printf ("La longitud de la cadena es: %i\n", strlen (cadena1));
	//----------------------------------------------------------------------------------------------------------------
	
	// PASE A MAYUSCULAS*****--------------
	printf ("El valor de la cadena es: %s\n", cadena1);
	printf ("La MAYUSCULA de la cadena es: %s\n", strupr (cadena1));
	printf ("La MINUSCULA de la cadena es: %s\n", strlwr (cadena1));
	return 0;
}
