#ifndef estruturas_h
#define estruturas_h
#include <stdbool.h>

typedef struct {
    char nome[50];
    bool prioridade;
    int itens;
    int tempo;
} Cliente;

typedef struct node{
    Cliente *cliente;
    struct node *proximo;
}Nodecliente;



#endif
