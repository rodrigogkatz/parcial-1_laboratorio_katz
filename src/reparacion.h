/*
 * reparacion.h
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#include "validaciones.h"
#include "cliente.h"
#include "marca.h"
#include "servicio.h"
#include "electrodomestico.h"

typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct {
	int id;
	int serie;
	int idServicio;
	int idCliente;
	Fecha fecha;
	int isEmpty;
} Reparacion;

void inicializarReparaciones(Reparacion aReparaciones[], int reparacionesLen);
int isEmptyReparacion(Reparacion aReparacion[], int reparacionesLen, int *posicion);
int agregarReparacion(Reparacion aReparaciones[], int reparacionesLen, int id, int serie, int idServicio, int idCliente, Fecha fecha);
void listarReparaciones(Reparacion aReparacion[], int len);
void imprimirReparacion(int index, int id, int serie, int idServicio, Fecha fecha);

#endif /* REPARACION_H_ */
