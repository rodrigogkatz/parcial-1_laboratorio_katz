/*
 * reparacion.h
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */

#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct {
	int id;
	int serie;
	int idServicio;
	Fecha fecha;
	int isEmpty;
} Reparacion;

//int agregarReparacion(Reparacion aReparaciones[], int reparacionesLen, int id, int serie, int idServicio, Fecha fecha);
//int setReparacion(int *idGenerador, Reparacion *reparacion, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen);
//void listarReparaciones(Reparacion aReparacion[], int len);
//void imprimirReparacion(int index, int id, int serie, int idServicio, int fecha);

#endif /* REPARACION_H_ */
