/*
 * informes.h
 *
 *  Created on: Oct 19, 2020
 *      Author: root
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "marca.h"
#include "servicio.h"
#include "menu.h"
#include "cliente.h"
#include "electrodomestico.h"
#include "reparacion.h"
#include "informes.h"


/**
 * brief funcion para mostrar el menu de informes
 * param Reparacion aReparaciones array
 * param int reparacionesLen
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Servicio aServicios array
 * param  int serviciosLen
 * param Marca aMarcas array
 * param int marcasLen
 * param Cliente aClientes array
 * param int clientesLen
 * return 0 ok / -1 error
 **/
int setInformes(Reparacion aReparaciones[], int reparacionesLen, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen, Marca aMarcas[], int marcasLen, Cliente aClientes[], int clientesLen);

/**
 * brief funcion para imprimir una tabla de todos los registros
 * param param Reparacion aReparaciones array
 * param int reparacionesLen
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Servicio aServicios array
 * param  int serviciosLen
 * param Marca aMarcas array
 * param int marcasLen
 * param Cliente aClientes array
 * param int clientesLen
 * return no retorna
 **/
void informeGeneral(Reparacion aReparaciones[], int reparacionesLen, Electrodomestico aElectrodomesticos[], int electroLen, Servicio aServicios[], int serviciosLen, Marca aMarcas[], int marcasLen, Cliente aClientes[], int clientesLen);

/**
 * brief
 * param
 * return 0 ok / -1 error
 **/
//void informeGeneralPorReparacionID();

/**
 * brief funcion para obtener el identificador del electrodomestico en una reparacion
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param int reparacionesSerieID
 * param int *auxIdElectro
 * return 0 ok / -1 error
 **/
int obtenerIdElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionesSerieID, int *auxIdElectro);

/**
 * brief funcion para obtener el modelo del electrodomestico en una reparacion
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param int reparacionesSerieID
 * param int *auxModeloElectro
 * return 0 ok / -1 error
 **/
int obtenerModeloElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionesSerieID, int *auxModeloElectro);

/**
 * brief funcion para obtener la marca del electrodomestico en una reparacion
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Marca aMarcas array
 * param int marcasLen
 * param int reparacionesSerieID
 * param int *auxMarca
 * return 0 ok / -1 error
 **/
int obtenerMarcaElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcasLen, int reparacionSerieID, char *auxMarca);

/**
 * brief funcion para obtener la descripcion del servicio prestado en una reparacion
 * param param Servicio aServicios array
 * param  int serviciosLen
 * param int reparacionesServicioID
 * param int *auxServicioDesc
 * return 0 ok / -1 error
 **/
int obtenerDescripcionServicio(Servicio aServicios[], int serviciosLen, int reparacionesServicioID, char *auxServicioDesc);

/**
 * brief funcion para obtener el precio por el servicio prestado en una reparacion
 * param param Servicio aServicios array
 * param  int serviciosLen
 * param int reparacionesServicioID
 * param int *auxServicioPrecio
 * return 0 ok / -1 error
 **/
int obtenerPrecioServicio(Servicio aServicios[], int serviciosLen, int reparacionesServicioID, int *auxServicioPrecio);

/**
 * brief obtener nombre del cliente que haya registrado una reparacion
 * param Cliente aClientes array
 * param int clientesLen
 * param  int reparacionesClienteID
 * param char *auxNombreCliente
*  return 0 ok / -1 error
 **/
int obtenerNombresCliente(Cliente aClientes[], int clientesLen, int reparacionesClienteID, char *auxNombreCliente);

/**
 * brief obtener apellido del cliente que haya registrado en una reparacion
 * param Cliente aClientes array
 * param int clientesLen
 * param  int reparacionesClienteID
 * param char *auxApellidoCliente
*  return 0 ok / -1 error
 **/
int obtenerApellidoCliente(Cliente aClientes[], int clientesLen, int reparacionesClienteID, char *auxApellidoCliente);

/**
 * brief funcion para obtener cuantos electrodomesticos hay para determinada marca
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Marca aMarcas array
 * param int marcasLen
 * return no retorna
 **/
int  obtenerElectrodomesticosPorMarca(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcasLen);




#endif /* INFORMES_H_ */
