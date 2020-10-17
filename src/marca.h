#ifndef HEADERS_MARCA_H_
#define HEADERS_MARCA_H_

typedef struct {
	int id;
	char descripcion[21];
	int isEmpty;
} Marca;

void hardcodearMarcas(Marca aMarcas[], int len);
void imprimirMarcas(Marca aMarcas[], int marcasLen);
void imprimirMarca(Marca marca);
int validarMarcaID(Marca aMarcas[], int marcasLen, int electrodomesticoMarcaID);
int obtenerDescripcionDeMarca(int idMarca, Marca aMarca[], int marcaLen, char *descripcionDeMarca);

#endif /* HEADERS_MARCA_H_ */
