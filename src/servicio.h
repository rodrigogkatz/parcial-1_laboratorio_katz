#ifndef HEADERS_SERVICIO_H_
#define HEADERS_SERVICIO_H_

typedef struct {
	int id;
	char descripcion[26];
	float precio;
	int isEmpty;
} Servicio;

/**
 * brief hardcodeo Servicio
 * param Servicio aServicios array
 * param int serviciosLen
 * return no retorna
 **/
void hardcodearServicios(Servicio aServicios[], int serviciosLen);

/**
 * brief funcion para imprimir lo que haya en Servicio
 * param Servicio aServicios array
 * param int serviciosLen
 * return no retorna
 **/
void imprimirServicios(Servicio aServicios[], int serviciosLen);

/**
 * brief funcion para imprimir  Servicio
 * param Servicio servicio
 * return no retorna
 **/
void imprimirServicio(Servicio servicio);

/**
 * brief
 * param Servicio aServicios array
 * param int serviciosLen
 * param int reparacionServicioID
 * return 0 ok / -1 error
 **/
int validarServicioID(Servicio aServicios[], int serviciosLen, int reparacionServicioID);

/**
 * brief funcion para obtener la descripcion de la Servicio
 *  param int idServicio
 * param Servicio aServicios array
 * param int servicioLen
 * param char *descripcionDeServicio
 * return 0 ok / -1 error
 **/
int obtenerDescripcionDeServicio(int idServicio, Servicio aServicios[], int servicioLen, char *descripcionDeServicio);

#endif /* HEADERS_SERVICIO_H_ */
