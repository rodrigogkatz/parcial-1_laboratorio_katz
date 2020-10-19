/*
 * repa-elec.h
 *
 *  Created on: Oct 17, 2020
 *      Author: root
 */

#ifndef REPA_ELEC_H_
#define REPA_ELEC_H_

#include "electrodomestico.h"
#include "reparacion.h"

/**
 * brief
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Reparacion aReparaciones array
 * param int reparacionLen
 * param Servicio aServicios array
 * param int servicioLen
 * param Marca aMarcas array
 * param int marcaLen
 * return 0 ok / -1 error
 **/
int removeElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Reparacion aReparaciones[], int reparacionLen, Servicio aServicios[], int servicioLen, Marca aMarcas[], int marcaLen);

/**
 * brief
 * param int *idGenerador
 * param Reparacion *reparacion
 * param Electrodomestico *aElectrodomesticos
 * param int electroLen
 * param Servicio aServicios array
 * param int serviciosLen
 * param Cliente aClientes array
 * param int clientesLen
 * return 0 ok / -1 error
 **/
int setReparacion(int *idGenerador, Reparacion *reparacion, Electrodomestico *aElectrodomesticos, int electroLen, Servicio aServicios[], int serviciosLen, Cliente aClientes[], int clientesLen);

#endif /* REPA_ELEC_H_ */
