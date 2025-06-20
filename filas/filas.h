#ifndef filas_h
#define filas_h

#include "../clientes/clientes.h"
#include <stdbool.h>

typedef struct{
    Nodecliente *primeiro;
    Nodecliente *ultimo;
    int tam;
}Fila;

Fila* criarFila();
void inserirClienteFila(Fila *fila, Cliente *cliente);
Nodecliente* atenderCliente(Fila *fila);
void imprimirFila(Fila *fila);

#endif
