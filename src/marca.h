#ifndef HEADERS_MARCA_H_
#define HEADERS_MARCA_H_

typedef struct {
	int id;
	char descripcion[21];
	int isEmpty;
} Marca;

/**
 * brief hardcodeo Marca
 * param Marca aMarcas array
 * param int marcaLen
 * return no retorna
 **/
void hardcodearMarcas(Marca aMarcas[], int marcaLen);

/**
 * brief funcion para imprimir lo que haya en Marca
 * param Marca aMarcas array
 * param int marcaLen
 * return no retorna
 **/
void imprimirMarcas(Marca aMarcas[], int marcaLen);

/**
 * brief funcion para imprimir  Marca
 * param Marca aMarcas
 * return no retorna
 **/
void imprimirMarca(Marca marca);

/**
 * brief
 * param Marca aMarcas array
 * param int marcaLen
 * param int electrodomesticoMarcaID
 * return 0 ok / -1 error
 **/
int validarMarcaID(Marca aMarcas[], int marcaLen, int electrodomesticoMarcaID);

/**
 * brief funcion para obtener la descripcion de la marca
 *  param int idMarca
 * param Marca aMarcas array
 * param int marcaLen
 * param char *descripcionDeMarca
 * return 0 ok / -1 error
 **/
int obtenerDescripcionDeMarca(int idMarca, Marca aMarca[], int marcaLen, char *descripcionDeMarca);

#endif /* HEADERS_MARCA_H_ */
