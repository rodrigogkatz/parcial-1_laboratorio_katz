/*
 ============================================================================
 Name        : parcial_electrodomestico.c
 Author      : Rodrigo Katz
 Version     :
 Copyright   : © Copyright RGK
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "reparacion.h"
#include "electrodomestico.h"
#include "marca.h"
#include "servicio.h"
#include "menu.h"

#define QTY_ELECTRODOMESTICOS 5
#define QTY_REPARACIONES 5
#define QTY_MARCAS 5
#define QTY_SERVICIOS 4

int main(void) {
	int exit = -1;
	int idGenerator = 0;
	int electrodomestico = -1;
	int electrodomesticoAgregado = -1;
	//int reparacion = -1;
	//int reparacionAgregadaOk = -1;

	Reparacion aReparaciones[QTY_REPARACIONES];
	//Reparacion auxaReparacion;
	Electrodomestico aElectrodomesticos[QTY_ELECTRODOMESTICOS];
	Electrodomestico auxaElectrodomestico;
	Marca aMarcas[QTY_MARCAS];
	Servicio aServicios[QTY_SERVICIOS];

		inicializarElectrodomesticos(aElectrodomesticos, QTY_ELECTRODOMESTICOS);
		//inicializarReparaciones(aReparaciones, QTY_REPARACIONES);

		//Hardcodeo marcas
		aMarcas[0].id=1;
		strncpy(aMarcas[0].descripcion,"Wirpool",sizeof(aMarcas[0].descripcion));
		aMarcas[0].isEmpty=0;
		aMarcas[1].id=2;
		strncpy(aMarcas[1].descripcion,"Sony",sizeof(aMarcas[1].descripcion));
		aMarcas[1].isEmpty=0;
		aMarcas[2].id=3;
		strncpy(aMarcas[2].descripcion,"Liliana",sizeof(aMarcas[2].descripcion));
		aMarcas[2].isEmpty=0;
		aMarcas[3].id=4;
		strncpy(aMarcas[3].descripcion,"Gafa",sizeof(aMarcas[3].descripcion));
		aMarcas[3].isEmpty=0;
		aMarcas[4].id=5;
		strncpy(aMarcas[4].descripcion,"Philips",sizeof(aMarcas[4].descripcion));
		aMarcas[4].isEmpty=0;

		//Hardcodeo servicios
		aServicios[0].id=20000;
		strncpy(aServicios[0].descripcion,"Garantia",sizeof(aServicios[0].descripcion));
		aServicios[0].precio = 250;
		aServicios[0].isEmpty=0;
		aServicios[1].id=20001;
		strncpy(aServicios[1].descripcion,"Mantenimiento",sizeof(aServicios[1].descripcion));
		aServicios[1].precio = 500;
		aServicios[1].isEmpty=0;
		aServicios[2].id=20002;
		strncpy(aServicios[2].descripcion,"Repuestos",sizeof(aServicios[2].descripcion));
		aServicios[2].precio = 400;
		aServicios[2].isEmpty=0;
		aServicios[3].id=20003;
		strncpy(aServicios[3].descripcion,"Refaccion",sizeof(aServicios[3].descripcion));
		aServicios[3].precio = 600;
		aServicios[3].isEmpty=0;

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


				//electrodomesticoAgregado == 0 ? reparacion = setReparacion(&idGenerator, &auxaReparacion, aElectrodomesticos, QTY_ELECTRODOMESTICOS, aServicios, QTY_SERVICIOS) : printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes de agendar una reparacion");
				//reparacion == 0 ? reparacionAgregadaOk = agregarReparacion(aReparaciones, QTY_REPARACIONES, auxaReparacion.id, auxaReparacion.serie, auxaReparacion.idServicio, auxaReparacion.fecha) : printf("\n\t\tERROR\n\t\tDebe agregar al menos un electrodomestico antes de borrar uno");

				break;
			case 8:

				//reparacionAgregadaOk == 0 ? listarReparaciones(aReparaciones, QTY_REPARACIONES) : printf("\n\t\tERROR\n\t\tDebe agregar al menos una reparacion");;
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
