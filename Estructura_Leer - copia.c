#include <stdio.h>

typedef struct {
	...
}tr_xxxx;	

*** Prototipos ***

tr_xxxx vr_xxxx;
FILE * vf_xxxx;

int main() {
	iniciarProceso();	
	procesarXXXX();		
	finalizarProceso();	
	return 0;
}

void iniciarProceso() {
	/* Abrir un archivo - Imprimir titulo - inicializar variables */
	vf_xxxxs = fopen("xxxxs.dat", "rb");
	printf("*** Listado de xxxxs*** \n");
	contxxxx = 0;
}

void procesarXXXX() {
    leerRegistro();
	while ( ! feof(vf_xxxxs) ) {
		if( condicion)  {
			printf("\n%d", vr_xxxx.dni, ....);
			contxxxxs ++;
		}
		leerRegistro();
	}
}

void leerRegistro(){
	fread( &vr_xxxx, sizeof(tr_xxxx), 1, vf_xxxxs );
}

void finalizarProceso() {
	/* Cerar archivo - mostrar totales - Porcentajes */
	fclose( vf_xxxxs );
	printf("\n\nCantidad de xxxxs registrados: %d\n", contxxxxs);
}
