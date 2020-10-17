/*
 * servicio.c
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "validaciones.h"
#include "servicio.h"


void hardcodearServicios(Servicio aServicios[], int len){
	Servicio hardcode[] = {
			{1, "Garantia", 250, 0},
			{2, "Mantenimiento", 500, 0},
			{3, "Repuestos", 400, 0},
			{4, "Refaccion", 600, 0}
	};
	for(int i = 0; i < len; i++){
		aServicios[i].id = hardcode[i].id;
		strncpy(aServicios[i].descripcion, hardcode[i].descripcion,sizeof(aServicios[i].descripcion));
		aServicios[i].precio = hardcode[i].precio;
		aServicios[i].isEmpty = hardcode[i].isEmpty;
	}
}

void imprimirServicios(Servicio aServicios[], int serviciosLen){
	if(aServicios != NULL && serviciosLen > 0){
		for (int i = 0; i < serviciosLen; i++) {
			imprimirServicio(aServicios[i]);
		}
	}
}

void imprimirServicio(Servicio servicio){
	if(servicio.isEmpty == 0){
		__fpurge(stdin);
		printf("\n\t\tID: %d -> Descripcion: %s -> Precio: $%.2f", servicio.id, servicio.descripcion, servicio.precio);
	}
}

int validarServicioID(Servicio aServicios[], int serviciosLen, int reparacionServicioID){
	int toReturn = -1;
	if(aServicios != NULL && serviciosLen > 0 && reparacionServicioID > 0 && reparacionServicioID < serviciosLen){
		for(int i = 0; i < serviciosLen; i++){
			if(aServicios[i].id == reparacionServicioID){
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}
