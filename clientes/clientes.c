#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"

Cliente* cadastrarNovoCliente(const char* nome, bool ehPreferencial, int quantidadeItens){

    Cliente* novoCliente = (Cliente*) malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("ERRO: Nao foi possivel alocar memoria para o cliente!\n");
        return NULL;
    }

    strncpy(novoCliente->nome, nome, sizeof(novoCliente->nome) - 1);
    novoCliente->nome[sizeof(novoCliente->nome) - 1] = '\0'; // Garante terminação nula

    novoCliente->quantidadeItens = quantidadeItens;

    novoCliente->ehPreferencial = ehPreferencial;

    printf("-------------------------------------------\n");
    printf(">>>Cliente '%s' cadastrado com sucesso! <<<\n", novoCliente->nome);

    return novoCliente;
}

void imprimirDadosCliente(Cliente* c){

    char preferencial[3] = c->ehPreferencial ? "sim" : "não";
    printf("Nome do cliente: %s", c->nome);
    printf("Quantidade de itens: %d", c->quantidadeItens);
    printf("Fila preferencial: %s", preferencial);
}
