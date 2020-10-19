/*
 * electrodomestico.c
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "menu.h"
#include "validaciones.h"
#include "electrodomestico.h"


void inicializarElectrodomesticos(Electrodomestico* aElectrodomesticos, int electroLen) {
	if( aElectrodomesticos != NULL && electroLen > 0){
		for(int i = 0; i < electroLen; i++){
			aElectrodomesticos[i].id = -1;
			aElectrodomesticos[i].isEmpty = 1;
		}
		printf("\n\t\tElectodomesticos inicializados");
	} else {
		printf("\n\t\tERROR:\n\t\tNo se pudo inicializar la estructura de Electodomesticos");
	}
}

int setElectrodomestico(int *idGenerador, Electrodomestico *electrodomestico, Marca aMarcas[], int marcasLen, Servicio aServicios[], int serviciosLen){
	int toReturn = -1;
	if(electrodomestico != NULL && idGenerador != NULL){
		printf("\n\t\tAlta Electrodomestico");
		(*idGenerador)++;
		electrodomestico->id = *idGenerador;
		utn_getNumber(&electrodomestico->serie,"\n\t\tIngrese N° de Serie del electrodomestico: ", "\n\t\tError\n\t\tNumero de serie invalido", 1, 5000000);
		do {
			imprimirMarcas(aMarcas, marcasLen);
			utn_getNumber(&electrodomestico->idMarca, "\n\t\tIngrese ID de la marca: ", "\n\t\tError\n\t\tID invalido", 1000, 1004);
		} while(validarMarcaID(aMarcas, marcasLen, electrodomestico->idMarca) == -1);
		utn_getNumber(&electrodomestico->modelo, "\n\t\tIngrese el modelo (entre 1980 y 2020): ", "\n\t\tError\n\t\tModelo invalido", 1980, 2020);
		electrodomestico->isEmpty = 0;
		printf("\n\t\tElectrodomestico a ingresar... ");
		printf("\n\t\t-> ID: %d", electrodomestico->id);
		printf("\n\t\t-> N° Serie: %d", electrodomestico->serie);
		printf("\n\t\t-> ID Marca: %d", electrodomestico->idMarca);
		printf("\n\t\t-> Modelo: %d", electrodomestico->modelo);
		printf("\n\t\t-> Estado: %d", electrodomestico->isEmpty);
		toReturn = 0;
	}
	return toReturn;
}

int agregarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int id, int serie, int idMarca, int modelo){
	int posicion;
	int toReturn = -1;
	if (aElectrodomesticos != NULL && electroLen > 0 && id >= 0 && serie > 0 && idMarca  > 0 && modelo > 0) {
		int result = isEmptyElectrodomestico(aElectrodomesticos, electroLen, &posicion);
		if(result == 0){
			printf("\n\t\tDando de alta al Electrodomestico... ");
			aElectrodomesticos[posicion].id = id;
			aElectrodomesticos[posicion].serie = serie;
			aElectrodomesticos[posicion].idMarca = idMarca;
			aElectrodomesticos[posicion].modelo = modelo;
			aElectrodomesticos[posicion].isEmpty = 0;
			printf("\n\t\tElectrodomestico generado satisfactoriamente...");
			/*printf("\n\t\t-> ID Electrodomestico: %d", aElectrodomesticos[posicion].id);
			printf("\n\t\t-> N° de Serie: %d", aElectrodomesticos[posicion].serie);
			printf("\n\t\t-> ID de Marca: %d", aElectrodomesticos[posicion].idMarca);
			printf("\n\t\t-> N° de Modelo: %d", aElectrodomesticos[posicion].modelo);
			printf("\n\t\t-> Estado: %d", aElectrodomesticos[posicion].isEmpty);*/
			toReturn = 0;
		}
	}
	return toReturn;
}

int isEmptyElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int *posicion){
	int toReturn = -1;
	if(aElectrodomesticos != NULL && posicion != NULL &&  electroLen > 0){
		printf("\n\t\tBuscando lugar para guardar el electrodomestico... ");
		for(int i = 0; i < electroLen; i++){
			if(aElectrodomesticos[i].isEmpty == 1){
				*posicion = i;
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int modificarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcaLen){
	int toReturn = -1;
	int isIDOkToModify = -1;
	int idElectroFound = -1;
	int cancelModification = -1;
	int auxSerie = 0;
	int auxModelo = 0;
	int isSerieOk = -1;
	int isModeloOK = -1;

	if (aElectrodomesticos != NULL && aMarcas != NULL && electroLen > 0 && marcaLen > 0) {
		mostrarIDsDisponibles(aElectrodomesticos,electroLen);
		isIDOkToModify = utn_getNumber(&isIDOkToModify, "\n\t\tIngrese el ID del electrodomestico que desea modificar: ", "\n\t\tERROR:\n\t\tEl id ingresado es invalido", 1, electroLen);
		isIDOkToModify > 0 ? idElectroFound = encontrarElectrodomesticoPorId(aElectrodomesticos, electroLen, isIDOkToModify) : printf("\n\t\tERROR\n\t\tEl electrodomestico seleccionado debe existir para poder ser modificado");
		if(idElectroFound > 0){

			do {
				switch (menuModificacionElectrodomesticos()) {
				case 1:
					mostrarNumerosDeSerieDisponibles(aElectrodomesticos,electroLen);
					isSerieOk =  utn_getNumber(&auxSerie,"\n\t\tIngrese n° de serie: ", "\n\t\tError\n\t\tNumero de serie invalido", 1, 5000000);
					if(isSerieOk > 0){
						printf("\n\t\tElectrodomestico ID %d", aElectrodomesticos[idElectroFound - 1].id);
						printf("\n\t\tModificando Nro Serie %d", aElectrodomesticos[idElectroFound - 1].serie);
						aElectrodomesticos[idElectroFound - 1].serie = auxSerie;
						printf("\n\t\tNro Serie actualizado a %d", aElectrodomesticos[idElectroFound - 1].serie);
					}
					break;
				case 2:
					mostrarModelosDisponibles(aElectrodomesticos,electroLen);
					isModeloOK = utn_getNumber(&auxModelo, "\n\t\tIngrese el nuevo modelo ", "\n\t\tERROR:\n\t\tEl modelo ingresado es invalido", 1980, 2020);
					if(isModeloOK > 0){
						printf("\n\t\tElectrodomestico ID %d", aElectrodomesticos[idElectroFound - 1].id);
						printf("\n\t\tModificando modelo %d", aElectrodomesticos[idElectroFound - 1].modelo);
						aElectrodomesticos[idElectroFound - 1].modelo = auxModelo;
						printf("\n\t\tID Marca actualizado a %d", aElectrodomesticos[idElectroFound - 1].modelo);
					}
					break;
				case 3:
					cancelModification = 0;
					break;
				default:
					printf("\n\t\tERROR\n\t\tIngrese una de las opciones numericas que proporciona el menu\n\n");
					break;
				}
			} while (cancelModification == -1);
		}
	}
	return toReturn;
}

int validarElectrodomesticoSerieID(Electrodomestico aElectrodomesticos[], int electroLen, int  reparacionSerieID){
	int toReturn = -1;
	if(aElectrodomesticos != NULL && electroLen > 0 && reparacionSerieID > 0){
		for(int i = 0; i < electroLen; i++){
			if(aElectrodomesticos[i].serie == reparacionSerieID){
				printf("aElectrodomesticos[i].serie %d - reparacionServicioID %d", aElectrodomesticos[i].serie, reparacionSerieID);
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int encontrarElectrodomesticoPorId(Electrodomestico aElectrodomesticos[], int electroLen, int id){
	int matches = 0;
	int loops = 0;
	if( aElectrodomesticos != NULL && electroLen > 0) {
		printf("\n\t\tBuscando electrodomestico número: %d ...", id);
			for(int i = 0; i < electroLen; i++){
				loops++;
				if(aElectrodomesticos[i].id == id && aElectrodomesticos[i].isEmpty == 0){
					matches++;
					break;
				}
			}
		}
	if(matches == 1){
		printf("\n\t\tElectrodomestico Existente");
		return loops;
	} else {
		printf("\n\t\tElectrodomestico Inexistente");
		return -1;
	}
}

int listarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int electroLen){
	int toReturn = -1;
	int opcion = 1;
	if( aElectrodomesticos != NULL && electroLen > 0) {
		utn_getNumber(&opcion, "\n\t\tListar Electrodomesticos\n\t\t1) Ordenados por serie\n\t\t2) Ordenados por modelo\n\t\tOpcion: ", "\n\t\tERROR:\n\t\tEl ID ingresado es invalido", 1, 2);
		int isSortOk = ordenarElectrodomesticos(aElectrodomesticos, electroLen, 1);
		if(isSortOk == 0){
			for(int i = 0; i < electroLen; i++){
				 if(aElectrodomesticos[i].isEmpty == 0) {
					 imprimirElectrodomestico(i, aElectrodomesticos[i].id, aElectrodomesticos[i].serie, aElectrodomesticos[i].idMarca, aElectrodomesticos[i].modelo);
				 }
			}
			toReturn = 0;
		}
	}
	return toReturn;
}

int ordenarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int electroLen, int order){
	int toReturn = -1;
	int auxId;
	int auxModelo;
	int auxSerie;
	int auxMarca;
	int auxIsEmpty;
	int electrodomesticoParaOrdenar = 0;
	if( aElectrodomesticos != NULL && electroLen > 0) {
		for(int i = 0; i < electroLen; i++){
			 if(aElectrodomesticos[i].isEmpty == 0) {
				 electrodomesticoParaOrdenar++;
			 }
		}

		switch (order) {
			case 1:
				for(int i = 0; i < electrodomesticoParaOrdenar -1; i++){
					for(int j = i +1; j < electrodomesticoParaOrdenar; j++){
						if(aElectrodomesticos[i].modelo > aElectrodomesticos[j].modelo){
							auxId = aElectrodomesticos[i].id;
							aElectrodomesticos[i].id = aElectrodomesticos[j].id;
							aElectrodomesticos[j].id = auxId;
							auxModelo = aElectrodomesticos[i].modelo;
							aElectrodomesticos[i].modelo = aElectrodomesticos[j].modelo;
							aElectrodomesticos[j].modelo = auxModelo;
							auxSerie = aElectrodomesticos[i].serie;
							aElectrodomesticos[i].serie = aElectrodomesticos[j].serie;
							aElectrodomesticos[j].serie = auxSerie;
							auxMarca = aElectrodomesticos[i].idMarca;
							aElectrodomesticos[i].idMarca = aElectrodomesticos[j].idMarca;
							aElectrodomesticos[j].idMarca = auxMarca;
							auxIsEmpty = aElectrodomesticos[i].isEmpty;
							aElectrodomesticos[i].isEmpty = aElectrodomesticos[j].isEmpty;
							aElectrodomesticos[j].isEmpty = auxIsEmpty;
						} else if(aElectrodomesticos[i].modelo <= aElectrodomesticos[j].modelo){
							if(aElectrodomesticos[i].serie > aElectrodomesticos[j].serie){
								auxId = aElectrodomesticos[i].id;
								aElectrodomesticos[i].id = aElectrodomesticos[j].id;
								aElectrodomesticos[j].id = auxId;
								auxModelo = aElectrodomesticos[i].modelo;
								aElectrodomesticos[i].modelo = aElectrodomesticos[j].modelo;
								aElectrodomesticos[j].modelo = auxModelo;
								auxSerie = aElectrodomesticos[i].serie;
								aElectrodomesticos[i].serie = aElectrodomesticos[j].serie;
								aElectrodomesticos[j].serie = auxSerie;
								auxMarca = aElectrodomesticos[i].idMarca;
								aElectrodomesticos[i].idMarca = aElectrodomesticos[j].idMarca;
								aElectrodomesticos[j].idMarca = auxMarca;
								auxIsEmpty = aElectrodomesticos[i].isEmpty;
								aElectrodomesticos[i].isEmpty = aElectrodomesticos[j].isEmpty;
								aElectrodomesticos[j].isEmpty = auxIsEmpty;
							}
						}
					}
				}
				toReturn = 0;
				break;
			default:
				printf("\n\t\tERROR:\n\t\tPor ahora no entendi que deba ordenar de otra forma");
				toReturn = -1;
				break;
		}
	}
	return toReturn;
}

void imprimirElectrodomestico(int indice, int id, int serie, int idMarca, int modelo){
	printf("\n\t\tElectrodomestico ID %d -> serie %d -> marca %d -> modelo %d",id, serie, idMarca, modelo);
}

void mostrarIDsDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen){
	if( aElectrodomesticos != NULL && electroLen > 0) {
		for(int i = 0; i < electroLen; i++){
			if(aElectrodomesticos[i].id > 0){
				printf("\n\t\tElectrodomestico ID %d esta disponible para ser modificado", aElectrodomesticos[i].id);
			}
		}
	}
}

void mostrarNumerosDeSerieDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen){
	if( aElectrodomesticos != NULL && electroLen > 0) {
		for(int i = 0; i < electroLen; i++){
			if(aElectrodomesticos[i].id > 0){
				printf("\n\t\tElectrodomestico ID %d -> Serie %d disponible para ser modificado", aElectrodomesticos[i].id, aElectrodomesticos[i].serie);
			}
		}
	}
}

void mostrarModelosDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen){
	if( aElectrodomesticos != NULL && electroLen > 0) {
		for(int i = 0; i < electroLen; i++){
			if(aElectrodomesticos[i].id > 0){
				printf("\n\t\tElectrodomestico ID %d -> Modelo %d disponible para ser modificado",aElectrodomesticos[i].id, aElectrodomesticos[i].modelo);
			}
		}
	}
}
