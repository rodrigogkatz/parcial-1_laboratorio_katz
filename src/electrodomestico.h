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

/**
 * brief esta funcion inicializa Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param tamaño del array
 * return no retorna
 **/
void inicializarElectrodomesticos(Electrodomestico aElectrodomesticos[], int electroLen);

/**
 * brief esta funcion establece Electrodomestico
 * param int idGenerador
 * param Electrodomestico electrodomestico
 * param Marca aMarcas array
 * param tamaño del array de marcas
 * param Servicio aServicios array
 * param tamaño del array
 * return 0 ok / -1 error
 **/
int setElectrodomestico(int *idGenerador, Electrodomestico *electrodomestico, Marca aMarcas[], int marcasLen, Servicio aServicios[], int serviciosLen);

/**
 * brief esta funcion agrega Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param int id
 * param  int serie
 * param int idMarca
 * param int modelo
 * return 0 ok / -1 error
 **/
int agregarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int id, int serie, int idMarca, int modelo);

/**
 * brief esta funcion busca lugar para guardar Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * param int *posicion
 * return 0 ok / -1 error
 **/
int isEmptyElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, int *posicion);

/**
 * brief esta funcion valida reparacion en Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * param int reparacionSerieID
 * return 0 ok / -1 error
 **/
int validarElectrodomesticoSerieID(Electrodomestico aElectrodomesticos[], int electroLen, int reparacionSerieID);

/**
 * brief esta funcion busca por id en Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * param int id
 * return 0 ok / -1 error
 **/
int encontrarElectrodomesticoPorId(Electrodomestico aElectrodomesticos[], int electroLen, int id);

/**
 * brief esta funcion modifica Electrodomestico
 * param  Electrodomestico aElectrodomesticos array
 * param int electroLen
 * param Marca aMarcas array
 * param int marcaLen
 * return 0 ok / -1 error
 **/
int modificarElectrodomestico(Electrodomestico aElectrodomesticos[], int electroLen, Marca aMarcas[], int marcaLen);

/**
 * brief esta funcion busca lugar para guardar Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * return 0 ok / -1 error
 **/
int listarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int electroLen);

/**
 * brief esta funcion busca lugar para guardar Electrodomestico
 * param int indice
 * param int id
 * param int serie
 * param int idMarca
 * param int modelo
 * return 0 ok / -1 error
 **/
void imprimirElectrodomestico(int indice, int id, int serie, int idMarca, int modelo);

/**
 * brief esta funcion ordena Electrodomestico
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * param int order
 * return 0 ok / -1 error
 **/
int ordenarElectrodomesticos(Electrodomestico  aElectrodomesticos[], int electroLen, int order);

/**
 * brief esta funcion muestra los numeros de IDs disponibles
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * return 0 ok / -1 error
 **/
void mostrarIDsDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen);

/**
 * brief esta funcion muestra los numeros de serie disponibles
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * return 0 ok / -1 error
 **/
void mostrarNumerosDeSerieDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen);

/**
 * brief esta funcion muestra los modelos disponibles
 * param Electrodomestico aElectrodomesticos array
 * param int electroLen tamaño del array
 * return no retorna
 **/
void mostrarModelosDisponibles(Electrodomestico  aElectrodomesticos[], int electroLen);

#endif /* ELECTRODOMESTICO_H_ */
