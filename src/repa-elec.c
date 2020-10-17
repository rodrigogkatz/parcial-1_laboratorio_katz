/*
 * repa-elec.c
 *
 *  Created on: Oct 17, 2020
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "validaciones.h"
#include "marca.h"
#include "servicio.h"
#include "reparacion.h"
#include "electrodomestico.h"

int removeElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Reparacion aReparaciones[], int reparacionLen, Servicio aServicios[], int servicioLen, Marca aMarcas[], int marcaLen){
	int toReturn = -1;
	int isElectroIDOkToDelete = -1;
	int idElectroFound = -1;
	if (aElectrodomesticos != NULL && aReparaciones != NULL && aServicios != NULL && aReparaciones != NULL && electroLen > 0 && reparacionLen > 0 && servicioLen > 0) {
		isElectroIDOkToDelete = utn_getNumber(&isElectroIDOkToDelete, "\n\t\tIngrese el ID que desea eliminar: ", "\n\t\tERROR:\n\t\tEl ID ingresado es invalido", 1, electroLen);
		isElectroIDOkToDelete > 0 ? idElectroFound = encontrarElectrodomesticoPorId(aElectrodomesticos, electroLen, isElectroIDOkToDelete) : printf("\n\t\tERROR\n\t\tEl electrodomestico seleccionado debe existir para poder ser eliminado");
		if(idElectroFound > 0){
			//printf("\n1) aElectrodomesticos[%d].isEmpty %d", idElectroFound, aElectrodomesticos[idElectroFound-1].isEmpty);
			aElectrodomesticos[idElectroFound - 1].isEmpty = 1;
			printf("\n\t\tElectrodomestico borrado: id %d -> serie %d -> marca %d",aElectrodomesticos[idElectroFound - 1].id, aElectrodomesticos[idElectroFound - 1].serie, aElectrodomesticos[idElectroFound - 1].idMarca);
			//printf("\n2) aElectrodomesticos[%d].isEmpty %d", idElectroFound, aElectrodomesticos[idElectroFound-1].isEmpty);
			/*for(int i = 0; i < reparacionLen; i++){
				//printf(" aReparaciones[i].serie %d",  aReparaciones[i].serie);
				if(aElectrodomesticos[idElectroFound - 1].serie == aReparaciones[i].serie){
					//printf("\n1) aReparaciones[%d].isEmpty %d", i, aReparaciones[i].isEmpty);
					aReparaciones[i].isEmpty = 1;
					//printf("\n2) aReparaciones[%d].isEmpty %d", i, aReparaciones[i].isEmpty);
					//imprimirElectrodomesticoConReparacionYServicio(aElectrodomesticos[idElectroFound - 1], aReparaciones[i], aServicios, servicioLen, aMarcas, marcaLen);
					break;
				}
			}*/
		}
	}
	return toReturn;
}


int setReparacion(int *idGenerador, Reparacion *reparacion, Electrodomestico *aElectrodomesticos, int electroLen, Servicio aServicios[], int serviciosLen, Cliente aClientes[], int clientesLen){
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
						utn_getNumber(&reparacion->idServicio, "\n\t\tIngrese ID de la servicio: ", "\n\t\tError\n\t\tID invalido", 1, serviciosLen);
					} while(validarServicioID(aServicios, serviciosLen, reparacion->idServicio) == -1);
					do {
						imprimirClientes(aClientes, clientesLen);
						utn_getNumber(&reparacion->idCliente, "\n\t\tIngrese ID del cliente para asignar la reparacion: ", "\n\t\tError\n\t\tN° de cliente invalido", 1, clientesLen);
					} while(validarClienteID(aClientes, clientesLen, reparacion->idCliente) == -1);
					utn_getNumber(&reparacion->fecha.dia, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tDia invalido", 1, 31);
					utn_getNumber(&reparacion->fecha.mes, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tMes invalido", 1, 12);
					utn_getNumber(&reparacion->fecha.anio, "\n\t\tIngrese el dia: ", "\n\t\tError\n\t\tAño invalido", 2020, 3020);
					reparacion->isEmpty = 0;
					printf("\n\t\tReparacion a ingresar... ");
					printf("\n\t\t-> ID de Reparacion: %d", reparacion->id);
					printf("\n\t\t-> N° Serie del Electrodomestico: %d", reparacion->serie);
					printf("\n\t\t-> ID del Servicio a aplicar: %d", reparacion->idServicio);
					printf("\n\t\t-> Fecha: %d/%d/%d", reparacion->fecha.dia,reparacion->fecha.mes,reparacion->fecha.anio );
					printf("\n\t\t-> ID del cliente: %d", reparacion->idCliente);
					printf("\n\t\t-> Estado: %d", reparacion->isEmpty);
					toReturn = 0;
		}
	return toReturn;
}
