/*
 * cliente.h
 *
 *  Created on: Oct 17, 2020
 *      Author: root
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int id;
	char nombre[21];
	char apellido[21];
	int isEmpty;
} Cliente;

void hardcodearClientes(Cliente aClientes[], int len);
void imprimirClientes(Cliente aClientes[], int ClientesLen);
void imprimirCliente(Cliente cliente);
int validarClienteID(Cliente aClientes[], int ClientesLen, int reparacionClienteID);

#endif /* CLIENTE_H_ */
