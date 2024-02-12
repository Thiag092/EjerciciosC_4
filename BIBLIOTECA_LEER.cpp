#include <stdio.h>
#include <string.h>

typedef char tc_string[30];
typedef struct{
	int isbn;
	tc_string titulo;
	tc_string autor;
	int anio;
	tc_string editorial;
}tr_registro;

void iniciarRegistro();
void leerRegistro();
void calcularRecientes();
void calcularAntiguos();
void calcularMedioReciente();
void procesarRegistro();
void imprimirRegistro();
void finalizarRegistro();

int totalLibros,libroReciente, libroMedioReciente, librosAntiguos;

tr_registro vr_biblioteca;
FILE*vf_biblioteca;

int main (){
	iniciarRegistro();
	procesarRegistro();
	finalizarRegistro();
	return 0;
}

void iniciarRegistro(){
	vf_biblioteca=fopen("Registro biblioteca.dat", "rb");
	if(vf_biblioteca!=NULL){
		printf("EL REGISTRO SE HA ENCONTRADO! \n");
	}else{
		printf("HA OCURRIDO UN ERROR!\n");
		finalizarRegistro();
	}
	printf("\tISBN\t TITULO\t AUTOR \t\t ANIO\t \tEDITORIAL\n");
	printf("\t---------------------------------------------------------------\n");

}
void procesarRegistro(){
	leerRegistro();
	while(!feof(vf_biblioteca)){
		 imprimirRegistro();
		calcularAntiguos();
		calcularMedioReciente();
		calcularRecientes();
		totalLibros++;
		leerRegistro();
	}
	
}
void imprimirRegistro(){
	printf("\t%d\t %s\t %s\t\t %d\t \t%s\n", vr_biblioteca.isbn, vr_biblioteca.titulo, vr_biblioteca.autor, 2022-vr_biblioteca.anio, vr_biblioteca.editorial);
}
void leerRegistro(){
	fread(&vr_biblioteca, sizeof(tr_registro), 1, vf_biblioteca);
}
void calcularRecientes(){
	if(vr_biblioteca.anio<=2){
		libroReciente++;
	}
}
void calcularMedioReciente(){
	if(vr_biblioteca.anio<=2&&vr_biblioteca.anio<5){
		libroMedioReciente++;
	}
}
void calcularAntiguos(){
if(vr_biblioteca.anio>5){
		librosAntiguos++;
	}
}
void finalizarRegistro(){
	printf("\nEl total de libros ingresados es de: %d\n", totalLibros);
	printf("\n");
	printf("Los libros de dos o menor año de antiguedad son: %d\n", libroReciente);
	printf("\n");
	printf("Los libros de entre 2 y 5 años de antiguedad son: %d\n", libroMedioReciente);
	printf("\n");
	printf("Los libros de mas de 5 años de antiguedad son: %d\n", librosAntiguos);
	printf("\n");
	printf("LA LECTURA DL REGISTRO HA FINALIZADO!\n");
	fclose(vf_biblioteca);
}
