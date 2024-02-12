#include <stdio.h>
 typedef struct {
    int nroInscripcion;
    char apellido [15];
    char nombre[15];
    int categoria;
    float importe;
}tr_congreso;

void iniciarArchivo();
void pregunta();
void procesarDatos();
void ingresarDatos();
void grabarDatos();
void finalizarRegistro();

tr_congreso vr_registro;
FILE*vf_registro;
char respuesta;

int main (){
    iniciarArchivo();
    procesarDatos();
    finalizarRegistro();
    return 0;
}
void iniciarArchivo(){
    vf_registro=fopen("AsistnesCongreso.dat", "wb");
    if(vf_registro!=NULL){
        printf("El regisro ha sido encontrado!\n");
    }else{
        printf("OCURRIO UN ERROR!\n");
        finalizarRegistro();
    }
}
void procesarDatos(){
    pregunta();
    while (respuesta=='s' || respuesta=='S'){
        ingresarDatos();
        grabarDatos();
        pregunta();
    }
}
void ingresarDatos(){
    printf("INGRESO DE DATOS DEL ASISTENTE\n");
    printf("\nIngrese Numero de inscripcion: \n");
    scanf("%d", &vr_registro.nroInscripcion);
    
     printf("Ingrese apellido: \n");
    scanf("%s", &vr_registro.apellido);

     printf("Ingrese nombre: \n");
    scanf("%s", &vr_registro.nombre);
    
     printf("Ingrese numero de categoria (1-Docente universitario; 2-Estudiante; 3-Doente secundario): \n");
    scanf("%d", &vr_registro.categoria);
    
     printf("Ingrese importe de inscripcion: \n");
    scanf("%f", &vr_registro.importe);
}
void pregunta(){
    printf("Desea ingresar un nuevo Registro? S/N\n");
    fflush(stdin);
    scanf("%c", &respuesta);
}
void grabarDatos(){
    fwrite(&vr_registro, sizeof(tr_congreso), 1, vf_registro);
    printf("Registro ingresado con exito!\n");
}
void finalizarRegistro(){
    fclose(vf_registro);
}
