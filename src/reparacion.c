/*
 * reparacion.c
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
#include "reparacion.h"
#include "electrodomestico.h"


void inicializarReparaciones(Reparacion aReparaciones[], int reparacionesLen) {
	if( aReparaciones != NULL && reparacionesLen > 0){
		for(int i = 0; i < reparacionesLen; i++){
			aReparaciones[i].isEmpty = 1;
		}
		printf("\n\t\tReparaciones inicializadas");
	} else {
		printf("\n\t\tERROR:\n\t\tNo se pudo inicializar la estructura de Empleados");
	}
}


int agregarReparacion(Reparacion aReparaciones[], int reparacionesLen, int id, int serie, int idServicio, int idCliente, Fecha fecha){
	int posicion;
	int toReturn = -1;
	if (aReparaciones != NULL && reparacionesLen > 0 && id >= 0 && serie > 0 && idServicio  > 0 && idCliente  > 0 && fecha.dia > 0 && fecha.mes > 0 && fecha.anio > 0) {
		int result = isEmptyReparacion(aReparaciones, reparacionesLen, &posicion);
		if(result == 0){
			printf("\n\t\tDando de alta la reparacion... ");
			aReparaciones[posicion].id = id;
			aReparaciones[posicion].serie = serie;
			aReparaciones[posicion].idServicio = idServicio;
			aReparaciones[posicion].idCliente = idCliente;
			aReparaciones[posicion].fecha = fecha;
			aReparaciones[posicion].isEmpty = 0;
			printf("\n\t\tReparacion generada satisfactoriamente...");
			/*printf("\n\t\t-> ID Reparacion: %d", aReparaciones[posicion].id);
			printf("\n\t\t-> N° de Serie: %d", aReparaciones[posicion].serie);
			printf("\n\t\t-> ID de Servicio: %d", aReparaciones[posicion].idServicio);
			printf("\n\t\t-> ID de Cliente: %d", aReparaciones[posicion].idCliente);
			printf("\n\t\t-> Fecha: %d/%d/%d", aReparaciones[posicion].fecha.dia, aReparaciones[posicion].fecha.mes, aReparaciones[posicion].fecha.anio);
			printf("\n\t\t-> Estado: %d", aReparaciones[posicion].isEmpty);*/
			toReturn = 0;
		}
	}
	return toReturn;
}

int isEmptyReparacion(Reparacion aReparacion[], int reparacionesLen, int *posicion){
	int toReturn = -1;
	if(aReparacion != NULL && posicion != NULL &&  reparacionesLen > 0){
		printf("\n\t\tBuscando lugar para guardar el electrodomestico... ");
		for(int i = 0; i < reparacionesLen; i++){
			if(aReparacion[i].isEmpty == 1){
				*posicion = i;
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}


void listarReparaciones(Reparacion aReparacion[], int reparacionesLen){
	//int opcion = 1;
	if( aReparacion != NULL && reparacionesLen > 0) {
		for(int i = 0; i < reparacionesLen; i++){
			 if(aReparacion[i].isEmpty == 0) {
				 imprimirReparacion(i, aReparacion[i].id, aReparacion[i].serie, aReparacion[i].idServicio, aReparacion[i].fecha);
			 }
		}
	}
}

void imprimirReparacion(int index, int id, int serie, int idServicio, Fecha fecha) {
	printf("\n\t\tElectrodomestico : id %d -> serie %d -> idServicio %d -> fecha %d/%d/%d",id, serie, idServicio, fecha.dia, fecha.mes, fecha.anio);
}
