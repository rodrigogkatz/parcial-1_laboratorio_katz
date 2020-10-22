/*
 ============================================================================
 Name        : parcial_electrodomestico.c
 Author      : Rodrigo Katz
 Version     : 1.0.3
 Copyright   : © Copyright RGK
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "marca.h"
#include "servicio.h"
#include "menu.h"
#include "cliente.h"
#include "electrodomestico.h"
#include "reparacion.h"
#include "repa-elec.h"
#include "informes.h"

#define QTY_ELECTRODOMESTICOS 100000
#define QTY_REPARACIONES 100000
#define QTY_MARCAS 5
#define QTY_SERVICIOS 4
#define QTY_CLIENTES 4

int main(void) {
	int exit = -1;
	int idGenerator = 0;
	int electrodomestico = -1;
	int electrodomesticoAgregado = -1;
	int reparacion = -1;
	int reparacionAgregadaOk = -1;

	Reparacion aReparaciones [QTY_REPARACIONES];
	Reparacion auxaReparacion;
	Electrodomestico aElectrodomesticos[QTY_ELECTRODOMESTICOS];
	Electrodomestico auxaElectrodomestico;
	Marca aMarcas[QTY_MARCAS];
	Servicio aServicios[QTY_SERVICIOS];
	Cliente aClientes[QTY_CLIENTES];

		inicializarElectrodomesticos(aElectrodomesticos, QTY_ELECTRODOMESTICOS);
		inicializarReparaciones(aReparaciones, QTY_REPARACIONES);

		hardcodearMarcas(aMarcas, QTY_MARCAS);
		hardcodearServicios(aServicios, QTY_SERVICIOS);
		hardcodearClientes(aClientes, QTY_CLIENTES);

		do {
			switch (menuPrimario()) {
			case 1:
				electrodomestico = setElectrodomestico(&idGenerator, &auxaElectrodomestico, aMarcas, QTY_MARCAS, aServicios, QTY_SERVICIOS);
				electrodomestico == 0 ? electrodomesticoAgregado = agregarElectrodomestico(aElectrodomesticos, QTY_ELECTRODOMESTICOS, auxaElectrodomestico.id, auxaElectrodomestico.serie, auxaElectrodomestico.idMarca, auxaElectrodomestico.modelo) : printf("\n\t\tERROR\n\t\tAlguno de los datos del Electrodomestico no se ingresaron correctamente");
				break;
			case 2:
				electrodomesticoAgregado == 0 ? modificarElectrodomestico(aElectrodomesticos, QTY_ELECTRODOMESTICOS, aMarcas, QTY_MARCAS)  : printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes de modificar uno");
				break;
			case 3:
				electrodomesticoAgregado == 0 ?	removeElectrodomestico(aElectrodomesticos, QTY_ELECTRODOMESTICOS, aReparaciones, QTY_REPARACIONES, aServicios, QTY_SERVICIOS, aMarcas, QTY_MARCAS) : printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes de borrar uno");
				break;
			case 4:
				electrodomesticoAgregado == 0 ? listarElectrodomesticos(aElectrodomesticos,QTY_ELECTRODOMESTICOS): printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes listar");
				break;
			case 5:
				imprimirMarcas(aMarcas,QTY_MARCAS);
				break;
			case 6:
				imprimirServicios(aServicios, QTY_SERVICIOS);
				break;
			case 7:
				imprimirClientes(aClientes, QTY_CLIENTES);
				break;
			case 8:
				electrodomesticoAgregado == 0 ? reparacion = setReparacion(&idGenerator, &auxaReparacion, aElectrodomesticos, QTY_ELECTRODOMESTICOS, aServicios, QTY_SERVICIOS, aClientes, QTY_CLIENTES) : printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes de agendar una reparacion");
				electrodomesticoAgregado == 0 && reparacion == 0 ? reparacionAgregadaOk = agregarReparacion(aReparaciones, QTY_REPARACIONES, auxaReparacion.id, auxaReparacion.serie, auxaReparacion.idServicio, auxaReparacion.idCliente, auxaReparacion.fecha) : printf("\n\t\tERROR\n\t\tNo se puede pactar una reparacion");
				break;
			case 9:
				electrodomesticoAgregado == 0 && reparacionAgregadaOk == 0 ? listarReparaciones(aReparaciones, QTY_REPARACIONES) : printf("\n\t\tERROR\n\t\tDebe agregar al menos una reparacion");;
				break;
			case 10:
				electrodomesticoAgregado == 0 && reparacionAgregadaOk == 0 ? setInformes(aReparaciones, QTY_REPARACIONES,aElectrodomesticos, QTY_ELECTRODOMESTICOS, aServicios, QTY_SERVICIOS, aMarcas, QTY_MARCAS, aClientes, QTY_CLIENTES) : printf("\n\t\tERROR\n\t\tDebe haber Electrodomesticos y Reparaciones registradas");;
				break;
			case 0:
				exit = 0;
				break;
			default:
				printf("\n\t\tERROR\nPor favor, ingrese una de las opciones numericas del menu.");
				break;
			}
		} while (exit != 0);

	return EXIT_SUCCESS;

}
