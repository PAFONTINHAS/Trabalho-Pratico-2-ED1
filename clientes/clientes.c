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
Cliente* cadastrarCliente(Fila *filaComum, Fila *filaPreferencial){
    Cliente *cliente = malloc(sizeof(Cliente));
    char resp;

    if (cliente != NULL){
        printf("Digite o nome do cliente: ");
        getchar();
        fgets(cliente->nome, 50, stdin);
        cliente->nome[strcspn(cliente->nome, "\n")] = 0;

        printf("Quantidade de itens: ");
        scanf("%d", &cliente->itens);

        do {
            printf("O cliente é prioritário? (s/n): ");
            scanf(" %c", &resp);

            if (resp == 's' || resp == 'S') {
                cliente->prioridade = true; // Define o cliente como prioritário.
                break;
            }
            else if (resp == 'n' || resp == 'N') {
                cliente->prioridade = false; // Define o cliente como não prioritário.
                break;
            }
            else {
                printf("Resposta inválida!\n"); // Informa ao usuário.
            }
        } while (1);

        cliente->tempo = 0; // Inicializa o tempo de atendimento como 0; será calculado depois.

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
