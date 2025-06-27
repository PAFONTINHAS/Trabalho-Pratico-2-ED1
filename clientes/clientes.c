#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clientes.h"
#include "../filas/filas.h"

// FUNÇÃO FEITA POR PETERSON
// Calcula o tempo de atendimento de um cliente com base na quantidade de itens.
int calcularTempo(int itens) {
    //multiplica o número de itens por 5 para obter o tempo total em segundos.
    return itens * 5;
}

// FUNÇÃO FEITA POR ISABELLA
// Função que cadastra um novo cliente com interação do usuário, solicitando nome, itens e prioridade.
Cliente* cadastrarCliente(Fila* filaComum, Fila* filaPreferencial, const char *nome, bool prioridade, int itens) {
    Cliente *cliente = malloc(sizeof(Cliente));

    if (cliente != NULL){
        strncpy(cliente->nome, nome, sizeof(cliente->nome) - 1); // Copia o nome do cliente, garantindo que não ultrapasse o tamanho máximo.
        cliente->nome[sizeof(cliente->nome) - 1] = '\0'; //
        cliente->tempo = 0; // Inicializa o tempo de atendimento como 0; será calculado depois.
        cliente->prioridade = prioridade; // Define se o cliente é prioritário ou não.
        cliente->itens = itens; // Define a quantidade de itens do cliente.

        // Lógica para inserir o cliente na fila correta (preferencial ou comum).
        if (cliente->prioridade) {
            // Insere o cliente na fila preferencial.
            inserirClienteFila(filaPreferencial, cliente);
            printf("\nCliente prioritário cadastrado com sucesso na fila preferencial!");
        } else {
            // Insere o cliente na fila comum.
            inserirClienteFila(filaComum, cliente);
            printf("\nCliente comum cadastrado com sucesso na fila comum!");
        }
    } else {
        printf("\nErro ao alocar memória para o cliente!\n");
    }
    return cliente;
}
