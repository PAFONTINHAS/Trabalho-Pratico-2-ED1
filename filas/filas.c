#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../filas/filas.h"
#include "../clientes/clientes.h"
#include "../atendimentos/atendimentos.h"

// FUNÇÃO FEITA POR GIOVANNA
// Função que cria e inicializa uma nova fila vazia.
Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if (fila != NULL) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
        fila->tam = 0;
    } else {
        printf("\nErro ao alocar memória para a fila!\n");
    }
    return fila;
}

// FUNÇÃO FEITA POR GIOVANNA
// Função que insere um novo cliente no final da fila
void inserirClienteFila(Fila *fila, Cliente *cliente){
    NodeCliente *novo = malloc(sizeof(NodeCliente));

    if (novo != NULL){
        novo->cliente = cliente;
        novo->proximo = NULL;

        // Verifica se a fila está vazia.
        if(fila->primeiro == NULL){
            // Se estiver vazia, o novo nó se torna tanto o primeiro quanto o último.
            fila->primeiro = novo;
            fila->ultimo = novo;
        }
        // Se a fila NÃO estiver vazia.
        else{
            // O próximo do nó que era o último agora aponta para o novo nó.
            fila->ultimo->proximo = novo;
            // O novo nó se torna o novo último da fila.
            fila->ultimo = novo;
        }
        // Incrementa o tamanho da fila.
        fila->tam++;
    }
    else {
        printf("\nErro ao alocar memória para o nó do cliente!\n");
    }
}

// FUNÇÃO FEITA POR CLARISSA
// Função que remove o primeiro cliente da fila e o adiciona a lista de clientes atendidos.
NodeCliente* atenderCliente(Fila *fila, ListaAtendidos *listaAtendidos){
    NodeCliente *atendido = NULL;

    // Verifica se a fila não está vazia.
    if(fila->primeiro != NULL){
        // O cliente a ser atendido é o primeiro da fila.
        atendido = fila->primeiro;
        // O "novo" primeiro da fila é o próximo do cliente que está sendo atendido.
        fila->primeiro = atendido->proximo;
        // Decrementa o tamanho da fila.
        fila->tam--;
        // Calcula o tempo de atendimento do cliente com base no número de itens.
        atendido->cliente->tempo = calcularTempo(atendido->cliente->itens);

        printf("\nCliente %s atendido.\nTempo de atendimento: ", atendido->cliente->nome);
        exibirTempoFormatado(atendido->cliente->tempo);
        printf(".\n");

        // Adiciona o cliente (a estrutura Cliente*) à lista de clientes já atendidos.
        adicionarClienteAtendido(listaAtendidos, atendido->cliente);

        free(atendido);
        return NULL;
    }
    // Se a fila estiver vazia.
    else {
        printf("\nFila vazia!\n");
    }
    return atendido;
}

// FUNÇÃO FEITA POR CLARISSA
// Função que imprime o conteúdo de uma única fila.
void imprimirFila(Fila *fila){
    NodeCliente *aux = fila->primeiro;

    // Verifica se a fila não está vazia.
    if(fila->primeiro != NULL){
        // Loop que continua enquanto houver clientes na fila.
        while(aux != NULL){
            // Imprime o nome do cliente e a quantidade de itens.
            printf("\t\t%s,\t%d itens\n", aux->cliente->nome, aux->cliente->itens);
            // Move para o próximo cliente na fila.
            aux = aux->proximo;
        }
        printf("\n============== FIM DA FILA ===============\n");
    }
    // Se a fila estiver vazia.
    else {
        printf("\n\t\tFila vazia!\n");
    }
}

// FUNÇÃO FEITA POR CLARISSA
// Função que imprime o conteúdo de ambas as filas (preferencial e comum) separadamente.
void imprimirAmbasFilas(Fila *filaComum, Fila *filaPreferencial){
    printf("\n============ FILA PREFERENCIAL ===========\n");
    imprimirFila(filaPreferencial);

    printf("\n============== FILA COMUM ================\n");
    imprimirFila(filaComum);
}

// FUNÇÃO FEITA POR JOAO
// Função que cria e inicializa uma nova lista de clientes atendidos vazia.
ListaAtendidos* criarListaAtendidos() {
    ListaAtendidos* novaLista = malloc(sizeof(ListaAtendidos));

    if (novaLista != NULL) {
        // Inicializa o primeiro e o último ponteiro da lista como NULL (lista vazia).
        novaLista->primeiro = NULL;
        novaLista->ultimo = NULL;
        // Inicializa o contador total de clientes atendidos como 0.
        novaLista->total_clientes_atendidos = 0;
    }
    // Retorna o ponteiro para a lista criada.
    return novaLista;
}

// FUNÇÃO FEITA POR JOÃO VICTOR
// Função que adiciona um cliente à lista de clientes atendidos.
void adicionarClienteAtendido(ListaAtendidos *lista, Cliente *cliente) {
    // Aloca dinamicamente memória para um novo nó de cliente atendido.
    NodeAtendido* novoNo = malloc(sizeof(NodeAtendido));
    // Verifica se a alocação de memória foi bem-sucedida.
    if (novoNo != NULL) {
        // Associa o cliente ao novo nó.
        novoNo->cliente = cliente;
        // O próximo ponteiro do novo nó é NULL.
        novoNo->proximo = NULL;

        // Verifica se a lista de atendidos está vazia.
        if (lista->primeiro == NULL) {
            // Se estiver vazia, o novo nó se torna o primeiro e o último.
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
        } else {
            // Se não estiver vazia, adiciona o novo nó ao final da lista.
            lista->ultimo->proximo = novoNo;
            lista->ultimo = novoNo;
        }
        // Incrementa o contador total de clientes atendidos.
        lista->total_clientes_atendidos++;
    } else {
        // Imprime uma mensagem de erro se a alocação falhar.
        printf("\nErro ao alocar memória para o nó de cliente atendido!\n");
    }
}

// FUNÇÃO FEITA POR JOÃO VICTOR
// Função que converte um tempo total em segundos para o formato de minutos e segundos e o exibe.
void exibirTempoFormatado(int totalSegundos) {
    // Calcula o número de minutos dividindo o total de segundos por 60.
    int minutos = totalSegundos / 60;
    // Calcula os segundos restantes usando o operador módulo (%).
    int segundos = totalSegundos % 60;

    // Verifica se há minutos.
    if (minutos > 0) {
        // Exibe o tempo no formato "X minuto(s) e Y segundo(s)".
        printf("%d minuto(s) e %d segundo(s)", minutos, segundos);
    } else {
        // Se não houver minutos, exibe apenas os segundos.
        printf("%d segundo(s)", segundos);
    }
}
