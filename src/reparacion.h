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

/**
 * brief esta funcion inicializa Reparacion
 * param Reparacion aReparaciones array
 * param int reparacionesLen tamaño del array
 * return no retorna
 **/
void inicializarReparaciones(Reparacion aReparaciones[], int reparacionesLen);

/**
 * brief esta funcion busca lugar para guardar Reparacion
 * param Reparacion aReparaciones array
 * param int reparacionesLen tamaño del array
 * param int *posicion
 * return 0 ok / -1 error
 **/
int isEmptyReparacion(Reparacion aReparacion[], int reparacionesLen, int *posicion);

/**
 * brief esta funcion para agregar Reparacion
 * param Reparacion aReparaciones array
 * param int reparacionesLen tamaño del array
 * param int id
 * param int serie
 * param int idServicio
 * param int idCliente
 * param Fecha fecha
 * return 0 ok / -1 error
 **/
int agregarReparacion(Reparacion aReparaciones[], int reparacionesLen, int id, int serie, int idServicio, int idCliente, Fecha fecha);

/**
 * brief esta funcion para listar Reparacion
 * param Reparacion aReparaciones array
 * param int reparacionesLen tamaño del array
 * return no retorna
 **/
void listarReparaciones(Reparacion aReparacion[], int reparacionesLen);

/**
 * brief esta funcion para imprimir Reparacion
 * param Reparacion aReparaciones array
 * param int reparacionesLen tamaño del array
 * param int *posicion
 * return no retorna
 **/
void imprimirReparacion(int index, int id, int serie, int idServicio, int idCliente, Fecha fecha);

#endif /* REPARACION_H_ */
