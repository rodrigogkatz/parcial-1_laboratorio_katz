/*
 * menu.c
 *
 *  Created on: Oct 15, 2020
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

int menuPrimario() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t1. ALTA ELECTRODOMESTICO");
	printf("\n\t\t2. MODIFICAR ELECTRODOMESTICO");
	printf("\n\t\t3. BAJA ELECTRODOMESTICO");
	printf("\n\t\t4. LISTAR ELECTRODOMESTICOS");
	printf("\n\t\t5. LISTAR MARCAS");
	printf("\n\t\t6. LISTAR SERVICIOS");
	printf("\n\t\t7. LISTAR CLIENTES");
	printf("\n\t\t8. ALTA REPARACION");
	printf("\n\t\t9. LISTAR REPARACIONES");
	printf("\n\t\t0. SALIR");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}

int menuModificacionElectrodomesticos() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t1. Modificar Serie");
	printf("\n\t\t2. Modificar ID Marca");
	printf("\n\t\t3. Modificar Modelo");
	printf("\n\t\t4. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}

int menuModificacionReparacion(){
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t1. Modificar Serie");
	printf("\n\t\t2. Modificar ID Servicio");
	printf("\n\t\t4. Modificar Fecha");
	printf("\n\t\t5. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}
