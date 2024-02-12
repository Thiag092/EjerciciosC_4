/* Nintendo necesita conocer las preferencias de sus clientes para crear nuevas ofertas. 
   Tiene registrados en un archivo los siguientes datos:  DNI, edad, cantidad de juegos comprados en la tienda y 
   código de género de juego más elegido (1-Acción, 2- Deporte, 3- juegos de Rol, … , 7-Automovilismo).  
   Se desea conocer la cantidad de clientes que compraron cada tipo de juego, 
   y la cantidad de juegos comprados para cada tipo de juego.
*/

typedef struct{
	int dni;
	int edad;
	int canComprados;
    int codGenero;   	 
} tr_juego;

tr_juego  vr_juego;
FILE * vf_juego;

/* ****  Solución 1:   ***/

int  contAccion, contDeporte, contRol, …      contAutomovilismo;
int  compAccion, compDeporte, compRol, …      compAutomovilismo;

switch (vr_juego.codGenero) {
	case 1: contAccion = contAccion + 1;
			compAccion = compAccion + vr_juego.canComprados;
			break;
	case 2: contDeporte = contDeporte + 1;
			compDeporte = compDeporte + vr_juego.canComprados;
			break;
	case 3: contRol = contRol + 1;
			compRol = compRol + vr_juego.canComprados;	
			break;
		
        ....
	case 7: contAutomovilismo = contAutomovilismo + 1;
			compAutomovilismo = compAutomovilismo + vr_juego.canComprados;
			break;
}

/* ****  Solución 2:   ***/
int  vv_cantClientes[7];
int  vv_cantJuegos[7];

vv_cantClientes[vr_juego.codGenero] = vv_cantClientes[vr_juego.codGenero] + 1;
vv_cantJuegos[vr_juego.codGenero]   = vv_cantJuegos[vr_juego.codGenero] + vr_juego.canComprados;


