#include <stdio.h>


typedef struct {
    int nroInscripcion;
    char apellido [15];
    char nombre[15];
    int categoria;
    float importe;
}tr_congreso;

void iniciarArchivo();
void procesarDatos();
void leerDatos();
void totalxCategoria();
void imprimirLista();
void porcentaje();
void calcularCategoria();
void finalizarRegistro();

int nroDocenteU, nroEstudiantes, nroDocenteSec,i, totalParticipantes;
float porcentajeEstudiantes,totalEstudiantes;
char respuesta;

typedef int tv_vector[3];
tv_vector vv_categoria;


tr_congreso vr_asistenciaCongreso;
FILE*vf_registroCongreso;

int main(){
	iniciarArchivo();
	procesarDatos();
	finalizarRegistro();
    return 0;
}
void iniciarArchivo(){
    vf_registroCongreso=fopen("AsistnesCongreso.dat", "rb");
    if(vf_registroCongreso!=NULL){
        printf("El registro ha sido encontrado!\n");
    }else{
        printf("OCURRIO UN ERROR!\n");
        finalizarRegistro();
    }
}
void procesarDatos(){
	leerDatos();
	
	printf("\nLos datos de los inscriptos son: \n");

    while(!feof(vf_registroCongreso)){
    	totalParticipantes++;
    	porcentaje();
		totalxCategoria();
        imprimirLista();
        leerDatos();
        
    }
}
void leerDatos(){
    fread(&vr_asistenciaCongreso,sizeof(tr_congreso),1,vf_registroCongreso);
}
void imprimirLista(){
	
    printf("\n\t%s\t %s\t\t %d\t\n", strupr(vr_asistenciaCongreso.apellido), vr_asistenciaCongreso.nombre, vr_asistenciaCongreso.categoria);

}
void finalizarRegistro(){
	printf("\nEl total de participantes por categoria es de:  \n");
	for(i=0;i<3;i++){
		printf("%d\t  ", vv_categoria[i]);}
	printf("\nEl total de participantes es de %d\n", totalParticipantes);
	printf("El porcentaje de estudiantes rspecto del total es de: %.2f", ((totalEstudiantes*totalParticipantes)/100));
    fclose(vf_registroCongreso);
}
void totalxCategoria(){
	vv_categoria[vr_asistenciaCongreso.categoria]=vv_categoria[vr_asistenciaCongreso.categoria]+1;
}
void porcentaje(){
	if(vr_asistenciaCongreso.categoria== 3){
		totalEstudiantes++;
	}
}
