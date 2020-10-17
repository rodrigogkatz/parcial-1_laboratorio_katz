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

int removeElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Reparacion aReparaciones[], int reparacionLen, Servicio aServicios[], int servicioLen, Marca aMarcas[], int marcaLen);
int setReparacion(int *idGenerador, Reparacion *reparacion, Electrodomestico *aElectrodomesticos, int electroLen, Servicio aServicios[], int serviciosLen, Cliente aClientes[], int clientesLen);

#endif /* REPA_ELEC_H_ */
