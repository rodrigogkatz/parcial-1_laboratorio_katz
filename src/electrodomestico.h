/*
 * electrodomestico.h
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include "menu.h"
#include "validaciones.h"
#include "marca.h"
#include "servicio.h"
#include "cliente.h"
#include "reparacion.h"

typedef struct {
	int id;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;
} Electrodomestico;

void inicializarElectrodomesticos(Electrodomestico aElectrodomesticos[], int electroLen);
int setElectrodomestico(int *idGenerador, Electrodomestico *electrodomestico, Marca aMarcas[], int marcasLen, Servicio aServicios[], int serviciosLen);
int agregarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int id, int serie, int idMarca, int modelo);
int isEmptyElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int *posicion);
int validarElectrodomesticoID(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionServicioID);
int encontrarElectrodomesticoPorId(Electrodomestico aElectrodomesticos[], int electroLen, int id);
int modificarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcaLen);
int listarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int len);
void imprimirElectrodomestico(int indice, int id, int serie, int idMarca, int modelo);
int ordenarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int len, int order);

#endif /* ELECTRODOMESTICO_H_ */
