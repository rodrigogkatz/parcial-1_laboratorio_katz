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
#include "reparacion.h"
#include "validaciones.h"
#include "marca.h"
#include "servicio.h"
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
/*
int setReparacion(int *idGenerador, Reparacion *reparacion, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen){
	int toReturn = -1;
		if(reparacion != NULL && idGenerador != NULL){
			(*idGenerador)++;
					reparacion->id = *idGenerador;
					do {
						listarElectrodomesticos(aElectrodomesticos, electroLen);
						utn_getNumber(&reparacion->serie, "\n\t\tIngrese n° de serie: ", "\n\t\tError\n\t\tN° de serie invalido", 1, 5000000);
					} while(validarElectrodomesticoID(aElectrodomesticos, electroLen, reparacion->serie) == -1);
					do {
						imprimirServicios(aServicios, serviciosLen);
						utn_getNumber(&reparacion->idServicio, "\n\t\tIngrese ID de la servicio: ", "\n\t\tError\n\t\tID invalido", 1, marcasLen);
					} while(validarServicioID(aServicios, serviciosLen, reparacion->idServicio) == -1);
					utn_getNumber(&reparacion->fecha.dia, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tDia invalido", 1, 31);
					utn_getNumber(&reparacion->fecha.mes, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tMes invalido", 1, 12);
					utn_getNumber(&reparacion->fecha.anio, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tAño invalido", 2020, 3000);
					reparacion->isEmpty = 0;
					printf("\n\t\Reparacion a ingresar... ");
					printf("\n\t\t-> ID: %d", reparacion->id);
					printf("\n\t\t-> N° Serie: %d", reparacion->serie);
					printf("\n\t\t-> ID Servicio: %d", reparacion->idServicio);
					printf("\n\t\t-> Fecha: %d/%d/%d", reparacion->fecha.dia,reparacion->fecha.mes,reparacion->fecha.anio );
					printf("\n\t\t-> Estado: %d", reparacion->isEmpty);
					toReturn = 0;
		}
	return toReturn;
}

int agregarReparacion(Reparacion aReparaciones[], int reparacionesLen, int id, int serie, int idServicio, Fecha fecha){
	int posicion;
	int toReturn = -1;
	if (aReparaciones != NULL && reparacionesLen > 0 && id >= 0 && serie > 0 && idServicio  > 0 && fecha > 0) {
		int result = isEmptyReparacion(aReparaciones, reparacionesLen, &posicion);
		if(result == 0){
			printf("\n\t\tDando de alta la reparacion... ");
			aReparaciones[posicion].id = id;
			aReparaciones[posicion].serie = serie;
			aReparaciones[posicion].idServicio = idServicio;
			aReparaciones[posicion].fecha = fecha;
			aReparaciones[posicion].isEmpty = 0;
			printf("\n\t\tReparacion generada satisfactoriamente...");
			printf("\n\t\t-> Legajo: %d", aElectrodomesticos[posicion].id);
			printf("\n\t\t-> Nombre: %s", aElectrodomesticos[posicion].serie);
			printf("\t\t-> Apellido: %s", aElectrodomesticos[posicion].idMarca);
			printf("\t\t-> Sector: %d", aElectrodomesticos[posicion].modelo);
			printf("\n\t\t-> Estado: %d", aElectrodomesticos[posicion].isEmpty)
			toReturn = 0;
		}
	}
	return toReturn;
}

void listarReparaciones(Reparacion aReparacion[], int len){
	int toReturn = -1;
		int opcion = 1;
		if( aReparacion != NULL && len > 0) {
				for(int i = 0; i < len; i++){
					 if(aReparacion[i].isEmpty == 0) {
						 imprimirReparacion(i, aReparacion[i].id, aReparacion[i].serie, aReparacion[i].idServicio, aReparacion[i].fecha);
					 }
				}
			}
}

void imprimirReparacion(int index, int id, int serie, int idServicio, int fecha) {
	printf("\n\t\tElectrodomestico : id %d -> serie %d -> idServicio %d -> fecha %d",id, serie, idServicio, fecha);
}
*/
