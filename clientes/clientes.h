#ifndef estruturas_h
#define estruturas_h
#include <stdbool.h>

typedef struct {
    char nome[50];
    bool ehPreferencial;
    int quantidadeItens;
    int tempo;
} Cliente;

typedef struct Node{
    Cliente* cliente;
    struct Node* proximo;
}Nodecliente;


#endif
