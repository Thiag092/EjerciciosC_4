#include <stdio.h>

typedef struct {
	int codSuc;
	int codProducto;
	char descripcion;
	int stock;
	int stockMin;
	
}tr_registro;

void iniciarRegistro();
void grabarRegistro();
void finalizarProceso();
void ingresarDatos();

tr_registro vr_bodega;
FILE * vf_bodega;


int main (){
	iniciarRegistro();
	grabarRegistro();
	finalizarProceso();
return 0;
}
void iniciarRegistro(){
	vf_bodega=fopen("RegistroBodega.dat", "wb");
	printf("El registro ha sido creado con exito!\n");
}
void grabarRegistro(){
	char opcion = 's';
	while (opcion != 'n'){
		ingresarDatos();
		fwrite( &vr_bodega, sizeof(tr_registro), 1, vf_bodega );
		printf( "\tRegistro de venta insertado! \n" );	
		
		printf("Desea cargar otro? S/N");
		fflush(stdin);
		scanf("%c", &opcion);
	}
}
void ingresarDatos(){

		printf("Ingresar datos al registro de la bodega: \n");
		printf("Ingrese codigo de la sucursal (1,2 o 3): \n");
		scanf("%d", &vr_bodega.codSuc);
		
		printf("Ingrese codigo de producto (4,5 o 6): \n");
		fflush(stdin);
		scanf("%d", &vr_bodega.codProducto);
		
		printf("Ingrese descripcion del producto: \n");
		fflush(stdin);
		scanf("%c", &vr_bodega.descripcion);
		
		printf("Ingrese stock del producto: ");
		fflush(stdin);
		scanf("%d", &vr_bodega.stock);
		
		printf("Ingrese stock minimo:\n");
		fflush(stdin);
		scanf("%d", &vr_bodega.stockMin);
	
}
void finalizarProceso(){
	fclose(vf_bodega);
}
