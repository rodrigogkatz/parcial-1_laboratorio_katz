/*
 * marca.c
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
#include "marca.h"


void hardcodearMarcas(Marca aMarcas[], int marcaLen){
	//Marca: id -> descripcion -> isEmpty
	Marca hardcode[] = {
			{1000, "Wirpool", 0},
			{1001, "Sony", 0},
			{1002, "Liliana", 0},
			{1003, "Gafa", 0},
			{1004, "Philips", 0}
	};
	for(int i = 0; i < marcaLen; i++){
		aMarcas[i].id = hardcode[i].id;
		strncpy(aMarcas[i].descripcion, hardcode[i].descripcion,sizeof(aMarcas[i].descripcion));
		aMarcas[i].isEmpty = hardcode[i].isEmpty;
	}
}

void imprimirMarcas(Marca aMarcas[], int marcaLen){
	if(aMarcas != NULL && marcaLen > 0){
		for (int i = 0; i < marcaLen; i++) {
			imprimirMarca(aMarcas[i]);
		}
	}
}

void imprimirMarca(Marca marca){
	if(marca.isEmpty == 0){
		__fpurge(stdin);
		printf("\n\t\tID: %d -> Descripcion: %s", marca.id, marca.descripcion);
	}
}

int validarMarcaID(Marca aMarcas[], int marcaLen, int electrodomesticoMarcaID){
	int toReturn = -1;
	if(aMarcas != NULL && marcaLen > 0 && electrodomesticoMarcaID > 0){
		for(int i = 0; i < marcaLen; i++){
			if(aMarcas[i].id == electrodomesticoMarcaID){
				toReturn = 0;
				break;
			}
		}
	}
	return toReturn;
}

int obtenerDescripcionDeMarca(int idMarca, Marca aMarca[], int marcaLen, char *descripcionDeMarca){
	int toReturn = -1;
		if(aMarca != NULL && marcaLen > 0 && idMarca > 0){
			printf("\n\t\tObteniendo la descripcion de la reparacion...");
			for(int i = 0; i < marcaLen; i++){
				if(aMarca[i].id == idMarca){
					strcpy(descripcionDeMarca, aMarca[i].descripcion);
					toReturn = 0;
					break;
				}
			}
		} else {
			printf("\n\t\tERROR\n\t\tNo se pudo obtener la descripcion");
		}
		return toReturn;
}
