#include <stdio.h>

int main (){
//	printf ("EJEMPLO CON **SCANF** \n");
	char nombre [20];
	char apellido [20];
/*
	printf ("Ingrese nombre\n");
	scanf("%s", &nombre);
	
	printf ("Ingrese apellido \n");
	scanf("%s", &apellido);
	
	printf ("\n\tEl nombre completo es: %s %s\n", nombre, apellido);*/
//---------------------------------------------------------------------------------------------------------------


	printf ("EJEMPLO CON **GETS** \n");
	printf ("Ingrese nombre completo\n");
	gets(nombre);
	
	printf ("\nEl nombre completo es: %s\n", nombre);
	
//---------------------------------------------------------------------------------------------------------------

	
	printf ("EJEMPLO CON **FGETS** \n");
	printf ("Ingrese nombre completo\n");
	fgets(nombre, 20, stdin);
	
	printf ("\n\tEl nombre completo es: %s", nombre);
	return 0;
}
