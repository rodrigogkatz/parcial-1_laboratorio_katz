/*
 * cliente.c
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
#include "cliente.h"

void hardcodearClientes(Cliente aClientes[], int len){
	Cliente hardcode[] = {
				{1, "Rodrigo", "Katz", 0},
				{2, "Arnold", "Schwarzenegger", 0},
				{3, "Maria", "Deluca", 0},
				{4, "Pedro", "Casavecchia", 0}
		};
		for(int i = 0; i < len; i++){
			aClientes[i].id = hardcode[i].id;
			strncpy(aClientes[i].nombre, hardcode[i].nombre,sizeof(aClientes[i].nombre));
			strncpy(aClientes[i].apellido, hardcode[i].apellido,sizeof(aClientes[i].apellido));
			aClientes[i].isEmpty = hardcode[i].isEmpty;
		}
}

void imprimirClientes(Cliente aClientes[], int clientesLen){
	if(aClientes != NULL && clientesLen > 0){
			for (int i = 0; i < clientesLen; i++) {
				imprimirCliente(aClientes[i]);
			}
		}
}

void imprimirCliente(Cliente cliente){
	if(cliente.isEmpty == 0){
			__fpurge(stdin);
			printf("\n\t\tID: %d -> Nombre: %s -> Apellido: %s", cliente.id, cliente.nombre, cliente.apellido);
		}
}

int validarClienteID(Cliente aClientes[], int clientesLen, int reparacionClienteID){
	int toReturn = -1;
		if(aClientes != NULL && clientesLen > 0 && reparacionClienteID > 0 && reparacionClienteID < clientesLen){
			for(int i = 0; i < clientesLen; i++){
				if(aClientes[i].id == reparacionClienteID){
					toReturn = 0;
					break;
				}
			}
		}
		return toReturn;
}
