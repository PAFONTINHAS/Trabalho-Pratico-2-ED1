#include "controller.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Cliente* cadastrarCliente(Fila *fila){

    Cliente *cliente = malloc(sizeof(Cliente));
    char resp;

    if (cliente != NULL){
        printf("Digite o nome do cliente: ");
        getchar();
        fgets(cliente->nome, 50, stdin);

        printf("Quantos itens?: ");
        scanf("%d", &cliente->itens);

        do {
            printf("O cliente é prioritário? (s/n): ");
            scanf(" %c", &resp);

            if (resp == 's' || resp == 'S') {
                cliente->prioridade = true;
                break;
            } else if (resp == 'n' || resp == 'N') {
                cliente->prioridade = false;
                break;
            } else {
                printf("Resposta inválida!\n");
            }
        } while (1);

        cliente->tempo = 0;
        inserirClienteFila(fila, cliente);
    }
    return cliente;
}
