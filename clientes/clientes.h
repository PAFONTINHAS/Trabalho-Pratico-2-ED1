#ifndef estruturas_h
#define estruturas_h
#include <stdbool.h>

typedef struct {
    char nome[50];
    bool ehPreferencial;
    int quantidadeItens;
} Cliente;


Cliente* cadastrarNovoCliente(const char* nome, bool ehPreferencial, int quantidadeItens);
void imprimirDadosCliente(Cliente* c);
#endif
