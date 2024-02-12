#include <stdio.h>
#include <string.h>

#define REGION 7    /* filas */
#define CATEGORIA 3 /* columna */

/* declaraciones */
typedef char tc_cadCar[30];
 
typedef int tm_ventasCategoria[REGION][CATEGORIA];	/* matriz de todos los datos (categoria x region) */
typedef tc_cadCar tv_nombreRegion[REGION];			/* vector de nombres de las 7 regiones */
typedef int tv_totalCategoria[CATEGORIA];			/* vector de totales por cada categoria*/
typedef int tv_totalRegion[REGION];					/* vector de totales por cada region */

typedef struct {
	int nroCliente;
	tc_cadCar apeYNombre;
	int codRegion;		/* COD Región: 0-Noroeste, 1- Cuyo, 2-Patagonia, 3-Mesopotamia, 4-llanura Pampeana, 5-Sierras Pampeanas, 6-Centro */
	int categoriaProd;	/* Categoría de producto: 1-Calzado, 2-Indumentaria, 3-Accesorio. */
	int cantProdVendidos;
} tr_cliente;

/* prototipado */
void iniciarProceso();
void procesarDatosCliente();
	void leerRegistroCliente();
	void informarClientesPatagonia();		/* item a */
	void listarVentasXCategoria();			/* item b */
	void obtenerTotalXCategoria();
	void obtenerTotalXRegion();
	void determinarRegionMenorVenta();		/* item c */
void finalizarProceso();

/* variables */
tr_cliente vr_cliente;
FILE * vf_cliente;

tm_ventasCategoria vm_ventasCategoria;
tv_nombreRegion vv_nombreRegion = {"Noroeste", "Cuyo\t", "Patagonia","Mesopotamia", 
                                   "Llanura Pamp.", "Sierras Pamp.", "Centro\t" };
tv_totalCategoria vv_totalCategoria;
tv_totalRegion vv_totalRegion;
int i, j;

int main() {
	iniciarProceso();
	procesarDatosCliente();
	finalizarProceso();
	return 0;
}

void iniciarProceso() {
	/* inicializar matriz */

	for (i = 0; i < REGION; i++) {
		for (j = 0; j < CATEGORIA; j++) {
			vm_ventasCategoria[i][j] = 0;
		}
	}
	
	/* inicializar vectores */
	for (i = 0; i < CATEGORIA; i++) {
		vv_totalCategoria[i] = 0;
	}
	
	for (j = 0; j < REGION; j++) {
		vv_totalRegion[j] = 0;
	}
	
	/* abrir archivo en modo lectura */
	vf_cliente = fopen("Netshoes.dat", "rb");
	
	printf("\t---- NETSHOES ----\n");
	printf("\n* Clientes de Region Patagonica que compraron en Indumentaria *\n");
	printf("\nNro. Cliente \tApellido y Nombre\n");
}

void procesarDatosCliente() {
	leerRegistroCliente();
	
	while ( !feof (vf_cliente) ) {
		
		/* contar cada categoria por region */
		vm_ventasCategoria[vr_cliente.codRegion][vr_cliente.categoriaProd-1] = 
		vm_ventasCategoria[vr_cliente.codRegion][vr_cliente.categoriaProd-1] + vr_cliente.cantProdVendidos;
		printf("%s", vr_cliente.apeYNombre);
		informarClientesPatagonia();
			
		leerRegistroCliente();
	}
}

void leerRegistroCliente() {
	/* lectura de 1 registro del archivo de clientes */
	fread ( &vr_cliente, sizeof(tr_cliente), 1, vf_cliente );
}

void informarClientesPatagonia() {
	/* obtener un informe por pantalla datos de los clientes de la región Patagónica que hayan comprado productos de la categoría Indumentaria. */
		
	if ( (vr_cliente.codRegion == 2) && (vr_cliente.categoriaProd == 2) ) {
		printf("%d \t\t%s\t%d\n", vr_cliente.nroCliente, vr_cliente.apeYNombre, vr_cliente.cantProdVendidos);
	}
}

void listarVentasXCategoria() {
	printf("\n\n*** Ventas de categoria por region ***\n");
	printf("\n\t\t  Calzado	Indumentaria	Accesorio     Total Region");
	
	obtenerTotalXRegion();
	
	
	for(i = 0; i < REGION; i++) {
		printf("\n %s ", vv_nombreRegion[i] );
				
		for (j = 0; j < CATEGORIA; j++) {
			printf("\t\t%d", vm_ventasCategoria[i][j] );
		}	
			printf ("\t%d", vv_totalRegion[i] );
	}
		
	printf("\n\t\t ----------------------------------------------------\nTotal Categoria");
	obtenerTotalXCategoria();
}

void obtenerTotalXCategoria() {
	/* se realiza el recorrido por columna, ya que se quiere saber el total de cada categoria */
	for (i = 0; i < REGION; i++) {
		for (j = 0; j < CATEGORIA; j++) {
			vv_totalCategoria[j] = vv_totalCategoria[j] + vm_ventasCategoria[i][j] ;	
		}
	}
	
	/* el resultado se almacena en un vector de fila */
	for (i = 0; i < CATEGORIA; i++) {
		printf ("\t\t%d", vv_totalCategoria[i] );
	} 
}

void obtenerTotalXRegion() {
	/* se realiza el recorrido por fila, ya que se quiere saber el total de cada region */
	for (i = 0; i < CATEGORIA; i++) {
		for (j = 0; j < REGION; j++) {
			vv_totalRegion[j] = vv_totalRegion[j] + vm_ventasCategoria[j][i] ;	
		}
	}
}

void determinarRegionMenorVenta() {
	int menorVenta = vv_totalRegion[0];
	int menorRegion;
	
	for (j = 0; j < REGION; j++) {
		if (vv_totalRegion[j] < menorVenta ) {
			menorVenta = vv_totalRegion[j] ;
			menorRegion = j;
		}
	}
	printf("\n\n**************************************");
	printf("\nLa region de %s tiene la menor cantidad, con %d ventas\n", vv_nombreRegion[menorRegion], menorVenta ) ;
}

void finalizarProceso() {
	listarVentasXCategoria();
	determinarRegionMenorVenta();
	fclose(vf_cliente);
}
