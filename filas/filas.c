#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"

Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tam = 0;

    return fila;
}

void inserirClienteFila(Fila *fila, Cliente *cliente){

    Nodecliente *aux, *novo = malloc(sizeof(Nodecliente));

    if (novo != NULL){
        novo->cliente = cliente;
        novo->proximo = NULL;

        // se a fila estiver vazia
        if(fila->primeiro == NULL){
            fila->primeiro = novo;
            fila->ultimo = novo;
        }
        //se a fila NÃO estiver vazia
        else{
            //se for prioritário
            if(novo->cliente->prioridade == true){

                // se o primeiro da fila for não prioritário
                if(fila->primeiro->cliente->prioridade == false){
                    novo->proximo = fila->primeiro;
                    fila->primeiro = novo;
                }

                //se JÁ tiver prioritário na fila
                else{
                    aux = fila->primeiro;

                    // anda enquanto o próximo for prioritário
                    while(aux->proximo && aux->proximo->cliente->prioridade == true){
                        aux = aux->proximo;
                    }

                    //agora que o aux está no último prioritário
                    novo->proximo = aux->proximo;
                    aux->proximo = novo;

                    //se o novo nó foi pro final da fila
                    if(novo->proximo == NULL)
                        fila->ultimo = novo;
                }
            }
            //se NÃO for prioritário, inserção normal (no fim)
            else{
                fila->ultimo->proximo = novo;
                fila->ultimo = novo;
            }
        }
        fila->tam++;
    }
    else {
        printf("\nErro ao alocar memória!\n");
    }
}

//função para remover da fila
Nodecliente* atenderCliente(Fila *fila){
    Nodecliente *atendido = NULL;

    //se estiver vazia
    if(fila->primeiro != NULL){
        atendido = fila->primeiro;
        fila->primeiro = atendido->proximo;
        fila->tam--;
    }
    //se não estiver vazia
    else
        printf("\nFila vazia!\n");
    return atendido;
}

//FUNCAO PARA IMPRIMIR FILA
void imprimirFila(Fila *fila){
    Nodecliente *aux = fila->primeiro;

    printf("\n-------FILA--------\n");
    //enquanto tiver cliente
    while(aux != NULL){
        printf("\t%s, %d itens, prioridade: %s\n", aux->cliente->nome, aux->cliente->itens, aux->cliente->prioridade ? "true" : "false");
        aux = aux->proximo;
    }
    printf("----FIM DA FILA----\n");
}
