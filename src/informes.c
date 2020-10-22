/*
 * informes.c
 *
 *  Created on: Oct 19, 2020
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "validaciones.h"
#include "informes.h"

int setInformes(Reparacion aReparaciones[], int reparacionesLen, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen, Marca aMarcas[], int marcasLen, Cliente aClientes[], int clientesLen){
	int exit = -1;
	int toReturn = -1;
	if(aReparaciones != NULL && reparacionesLen > 0 &&
		aElectrodomesticos != NULL && electroLen > 0 &&
		aServicios != NULL && serviciosLen > 0 &&
		aMarcas != NULL && marcasLen > 0 &&
		aClientes != NULL && clientesLen > 0){

		do{
			switch (menuInformes()) {
				case 1:
					informeGeneral(aReparaciones,reparacionesLen,aElectrodomesticos,electroLen,aServicios,serviciosLen,aMarcas,marcasLen,aClientes,clientesLen);
					break;
				case 2:
					//cuantos electrodomesticos hay para determinada marca
					//informeGeneralPorReparacionID();
					obtenerElectrodomesticosPorMarca(aElectrodomesticos,electroLen,aMarcas,marcasLen);
					break;

				case 0:
					exit = 0;
					break;
				default:
					printf("\n\t\tERROR\nPor favor, ingrese una de las opciones numericas del menu.");
					break;
			}

		} while (exit != 0);
	}
	return toReturn;
}

void informeGeneral(Reparacion aReparaciones[], int reparacionesLen, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen, Marca aMarcas[], int marcasLen, Cliente aClientes[], int clientesLen){
	int auxIdElectro;
	int auxModeloElectro;
	int auxServicioPrecio;
	char auxServicioDesc[20];
	char auxMarcaDesc[20];
	char auxNombreCliente[20];
	char auxApellidoCliente[20];
	if(aReparaciones != NULL && reparacionesLen > 0 &&
		aElectrodomesticos != NULL && electroLen > 0 &&
		aServicios != NULL && serviciosLen > 0 &&
		aMarcas != NULL && marcasLen > 0 &&
		aClientes != NULL && clientesLen > 0){

		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\nID Rep. | Fecha de Rep. | ID Ele. | N° Serie | Mod. |   Marca   | Desc. del Servicio |   Precio   | Nombre completo del cliente");
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		for(int i = 0; i < reparacionesLen; i++){
			obtenerIdElectrodomestico(aElectrodomesticos, electroLen, aReparaciones[i].serie, &auxIdElectro);
			obtenerModeloElectrodomestico(aElectrodomesticos, electroLen, aReparaciones[i].serie, &auxModeloElectro);
			obtenerMarcaElectrodomestico(aElectrodomesticos, electroLen, aMarcas, marcasLen, aReparaciones[i].serie, auxMarcaDesc);
			obtenerDescripcionServicio(aServicios, serviciosLen, aReparaciones[i].idServicio, auxServicioDesc);
			obtenerPrecioServicio(aServicios, serviciosLen, aReparaciones[i].idServicio, &auxServicioPrecio);
			obtenerNombresCliente(aClientes, clientesLen, aReparaciones[i].idCliente, auxNombreCliente);
			obtenerApellidoCliente(aClientes, clientesLen, aReparaciones[i].idCliente, auxApellidoCliente);
			if(aReparaciones[i].isEmpty == 0){
				printf("\n\t%d\t\t%d/ %d/ %d  \t %d \t%d  %d \t%s\t\t%s\t\t$ARG%d,-\t%s %s",
						aReparaciones[i].id,
						aReparaciones[i].fecha.dia, aReparaciones[i].fecha.mes, aReparaciones[i].fecha.anio,
						auxIdElectro,
						aReparaciones[i].serie,
						auxModeloElectro,
						auxMarcaDesc,
						auxServicioDesc,
						auxServicioPrecio,
						auxNombreCliente,
						auxApellidoCliente
						);
				printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

			}
		}
	}
}

int obtenerIdElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionesSerieID, int *auxIdElectro){
	int toReturn = -1;
	if(aElectrodomesticos != NULL && electroLen > 0 && reparacionesSerieID > 0 && auxIdElectro != NULL){
		for (int i = 0; i < electroLen; i++) {
			if (aElectrodomesticos[i].isEmpty == 0 && aElectrodomesticos[i].serie == reparacionesSerieID) {
				*auxIdElectro = aElectrodomesticos[i].id;
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerModeloElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionesSerieID, int *auxModeloElectro){
	int toReturn = -1;
	if(aElectrodomesticos != NULL && electroLen > 0 && reparacionesSerieID > 0 && auxModeloElectro != NULL){
		for (int i = 0; i < electroLen; i++) {
			if (aElectrodomesticos[i].isEmpty == 0 && aElectrodomesticos[i].serie == reparacionesSerieID) {
				*auxModeloElectro = aElectrodomesticos[i].modelo;
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerMarcaElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcasLen, int reparacionSerieID, char *auxMarca){
	int toReturn = -1;
	if(aElectrodomesticos != NULL && electroLen > 0 && aMarcas != NULL && marcasLen > 0 && reparacionSerieID > 0 && auxMarca != NULL){
		for (int i = 0; i < electroLen; i++) {
			if (aElectrodomesticos[i].serie == reparacionSerieID) {
				//printf("\n iteracion sobre electrodomesticos con n° serie %d", reparacionSerieID);
				for (int j = 0; j < marcasLen; j++) {
					if (aElectrodomesticos[i].idMarca == aMarcas[j].id) {
						strcpy(auxMarca, aMarcas[i].descripcion);
						toReturn = 0;
						break;
					}
				}
			}
		}
	}
	return toReturn;
}
//TODO
int  obtenerElectrodomesticosPorMarca(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcasLen){
	int toReturn = -1;
	char name[51];
	int matches = 0;
	//int isMarcaOk = -1;
	if(aElectrodomesticos != NULL && electroLen > 0 && aMarcas != NULL && marcasLen > 0){
		imprimirMarcas(aMarcas, marcasLen);
		printf ("\n\t\tIngrese la descripcion de alguna marca sugerida: ");
		scanf ("%50s",name);
		//utn_getString(name, "\n\t\tIngrese una marca: ", "\n\t\tLa marca debe tener entre 2 y 50 caracteres.\n\t\tIntente nuevamente: ", 2, 50);
		for (int i = 0; i < marcasLen; i++) {
			//printf("\n aMarcas[i].descripcion %s VS name %s", aMarcas[i].descripcion, name);
			if (strcmp(aMarcas[i].descripcion, name) == 0) {
				//printf("\n iteracion sobre electrodomesticos con n° serie %d", reparacionSerieID);
				for (int j = 0; j < electroLen; j++) {
					if (aElectrodomesticos[j].idMarca == aMarcas[i].id) {
						matches++;
						imprimirElectrodomestico(j, aElectrodomesticos[j].id , aElectrodomesticos[j].serie, aElectrodomesticos[j].idMarca, aElectrodomesticos[j].modelo);
						toReturn = 0;
						break;
					}
				}
			}

		}

		if(matches > 0){
			printf ("\n\t\tSe encontraron %d electrodomesticos por marca", matches);
		} else {
			printf ("\n\t\tNo se encontro electrodomestico/s por la marca ingresada\n\t\tRespete mayusculas y minusculas!");
		}
	}
	return toReturn;
}

int obtenerDescripcionServicio(Servicio aServicios[], int serviciosLen, int reparacionesServicioID, char *auxServicioDesc){
	int toReturn = -1;
	if(aServicios != NULL && serviciosLen > 0 && reparacionesServicioID> 0 && auxServicioDesc != NULL){
		for (int i = 0; i < serviciosLen; i++) {
			if (aServicios[i].isEmpty == 0 && aServicios[i].id == reparacionesServicioID) {
				strcpy(auxServicioDesc, aServicios[i].descripcion);
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerPrecioServicio(Servicio aServicios[], int serviciosLen, int reparacionesServicioID, int *auxServicioPrecio){
	int toReturn = -1;
	if(aServicios != NULL && serviciosLen > 0 && reparacionesServicioID> 0 && auxServicioPrecio != NULL){
		for (int i = 0; i < serviciosLen; i++) {
			if (aServicios[i].isEmpty == 0 && aServicios[i].id == reparacionesServicioID) {
				*auxServicioPrecio = aServicios[i].precio;
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerNombresCliente(Cliente aClientes[], int clientesLen, int reparacionesClienteID, char *auxNombreCliente){
	int toReturn = -1;
	if(aClientes != NULL && clientesLen > 0 && reparacionesClienteID > 0 && auxNombreCliente != NULL){
		for (int i = 0; i < clientesLen; i++) {
			if (aClientes[i].isEmpty == 0 && aClientes[i].id == reparacionesClienteID) {
				strcpy(auxNombreCliente, aClientes[i].nombre);
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerApellidoCliente(Cliente aClientes[], int clientesLen, int reparacionesClienteID, char *auxApellidoCliente){
	int toReturn = -1;
	if(aClientes != NULL && clientesLen > 0 && reparacionesClienteID > 0 && auxApellidoCliente != NULL){
		for (int i = 0; i < clientesLen; i++) {
			if (aClientes[i].isEmpty == 0 && aClientes[i].id == reparacionesClienteID) {
				strcpy(auxApellidoCliente, aClientes[i].apellido);
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}
