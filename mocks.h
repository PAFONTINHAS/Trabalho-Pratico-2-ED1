#ifndef MOCKS_H
#define MOCKS_H

#include "filas/filas.h"
#include "clientes/clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    // FUNÇÃO FEITA POR ISABELLA
    //cadastra um novo cliente com dados pré-definidos (para demonstração, não interativo).
    Cliente* cadastrarClienteDemo(Fila *filaComum, Fila *filaPreferencial, const char *nome, int itens, bool prioridade) {
        Cliente *cliente = (Cliente *) malloc(sizeof(Cliente));

        if (cliente != NULL) {
            strncpy(cliente->nome, nome, 49);
            cliente->nome[49] = '\0';
            cliente->itens = itens;
            cliente->prioridade = prioridade;
            cliente->tempo = 0;

            // Lógica para inserir o cliente na fila correta.
            if (cliente->prioridade) {
                // Insere o cliente na fila preferencial.
                inserirClienteFila(filaPreferencial, cliente);
                // printf("\nCliente (auto) '%s' cadastrado na fila preferencial.", cliente->nome); // Comentado para evitar poluir a saída inicial.
            } else {
                // Insere o cliente na fila comum.
                inserirClienteFila(filaComum, cliente);
                // printf("\nCliente (auto) '%s' cadastrado na fila comum.", cliente->nome); // Comentado para evitar poluir a saída inicial.
            }
        } else {
            printf("\nErro ao alocar memória para o cliente (automatico)!\n"); // Mensagem de erro se malloc falhar.
        }
        return cliente;
    }
    
    void preencherListaParticipantes(Fila* filaComum, Fila* filaPreferencial){
        cadastrarClienteDemo(filaComum, filaPreferencial, "Larissa", 17, false);
        cadastrarClienteDemo(filaComum, filaPreferencial, "Sebastião", 15, true);
        cadastrarClienteDemo(filaComum, filaPreferencial, "Gertrudes", 10, true);
        cadastrarClienteDemo(filaComum, filaPreferencial, "Leticia", 25, false);
        cadastrarClienteDemo(filaComum, filaPreferencial, "Serenita", 30, true);
        cadastrarClienteDemo(filaComum, filaPreferencial, "Gustavo", 8, false);
    }
#endif
