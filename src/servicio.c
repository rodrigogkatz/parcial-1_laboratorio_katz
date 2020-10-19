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


void hardcodearServicios(Servicio aServicios[], int serviciosLen){
	Servicio hardcode[] = {
			{20000, "Garantia", 250, 0},
			{20001, "Mantenimiento", 500, 0},
			{20002, "Repuestos", 400, 0},
			{20003, "Refaccion", 600, 0}
	};
	for(int i = 0; i < serviciosLen; i++){
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
	if(aServicios != NULL && serviciosLen > 0 && reparacionServicioID > 0){
		for(int i = 0; i < serviciosLen; i++){
			if(aServicios[i].id == reparacionServicioID){
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerDescripcionDeServicio(int idServicio, Servicio aServicios[], int servicioLen, char *descripcionDeServicio){
	int toReturn = -1;
		if(aServicios != NULL && servicioLen > 0 && idServicio > 0){
			printf("\n\t\tObteniendo la descripcion de la reparacion...");
			for(int i = 0; i < servicioLen; i++){
				if(aServicios[i].id == idServicio){
					strcpy(descripcionDeServicio, aServicios[i].descripcion);
					toReturn = 0;
					break;
				}
			}
		} else {
			printf("\n\t\tERROR\n\t\tNo se pudo obtener la descripcion");
		}
		return toReturn;
}
