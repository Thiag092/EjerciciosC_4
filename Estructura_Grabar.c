
#include <stdio.h>
#include <string.h>

typedef struct {
	...
}tr_xxxx;	

*** Prototipos ***

tr_xxxx vr_xxxx;
FILE * vf_xxxxs;

int main() {
	iniciarProceso();
	grabarDatos();
	finalizarProceso();
	return 0;
}

void iniciarProceso() {
	vf_xxxxs = fopen("xxxx.dat", "wb");
}

void grabarDatos() {
	while (desea grabar) {
		ingresarDatos();
		fwrite( &vr_xxxx, sizeof( tr_xxxx ), 1, vf_xxxxs );
	}	
}

void ingresarDatos() {
	printf("\tDNI: ");
	scanf("%d", &vr_xxxx.dni);
    ...
}

void finalizarProceso() {
	fclose(vf_xxxxs);
}

