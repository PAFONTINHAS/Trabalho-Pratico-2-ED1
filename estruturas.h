#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <stdbool.h>

typedef struct Cliente{
    char nome[50];
    bool prioridade;
    int itens;
    int tempo;
} Cliente;

typedef struct NodeCliente{
    Cliente* cliente;
    struct NodeCliente* proximo;
}NodeCliente;

typedef struct Fila{
    NodeCliente *primeiro;
    NodeCliente *ultimo;
    int tam;
}Fila;

typedef struct NodeAtendido {
    Cliente* cliente;
    struct NodeAtendido* proximo;
} NodeAtendido;

typedef struct {
    NodeAtendido* primeiro;
    NodeAtendido* ultimo;
    int total_clientes_atendidos;
} ListaAtendidos;


#endif
