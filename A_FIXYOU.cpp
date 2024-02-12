#include <stdio.h>
void iniciarArchivo();
void procesarArchivo();
void leerArchivo();
void imprimirCancion();

char cancion [9999];
FILE * vf_FixYou;

int main (){
	iniciarArchivo();
	procesarArchivo();
	imprimirCancion();
	return 0;
}
void iniciarArchivo(){
	vf_FixYou=fopen("fix_you.txt", "r");
	
	if (vf_FixYou== NULL){
		printf("El archivo no existe!\n");
		}else {
			printf("Archivo encontrado!\n");
		}
		printf("------------------------------\n");
	}

void procesarArchivo(){
	leerArchivo();
	while(!feof(vf_FixYou)){
		imprimirCancion();
		leerArchivo();
	}
}
void leerArchivo(){
	fscanf(vf_FixYou, "%s", cancion);
}
void imprimirCancion(){
	
	printf("%s ", cancion);
}
void finalizarPrograma(){
	fclose (vf_FixYou);
}
