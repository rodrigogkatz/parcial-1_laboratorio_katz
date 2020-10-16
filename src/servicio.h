#ifndef HEADERS_SERVICIO_H_
#define HEADERS_SERVICIO_H_

typedef struct {
	int id;
	char descripcion[26];
	float precio;
	int isEmpty;
} Servicio;

void imprimirServicios(Servicio aServicios[], int serviciosLen);
void imprimirServicio(Servicio servicio);
int validarServicioID(Servicio aServicios[], int serviciosLen, int reparacionServicioID);

#endif /* HEADERS_SERVICIO_H_ */
