#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../filas/filas.h"
#include "../atendimentos/atendimentos.h"

// FUNÇÃO FEITA POR PETERSON
// Função que gerencia a lógica de atendimento de clientes, alternando entre filas comum e preferencial.
void handleOpcaoDois(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos, int *contadorComum, const int LIMITE_COMUM, bool *proximoEhPreferencial) {
    // Lógica de atendimento alternado: 2 comuns, 1 preferencial

    // PRIMEIRO CENÁRIO: Tentar atender um cliente preferencial se for a vez dele E houver clientes na fila preferencial.
    if (filaPreferencial->tam > 0 && *proximoEhPreferencial) {
        printf("\nAtendendo cliente da Fila Preferencial...\n");

        // Chama a função para atender o cliente da fila preferencial.
        atenderCliente(filaPreferencial, clientesAtendidos);
        *contadorComum = 0; // Reseta o contador de clientes comuns, pois um preferencial foi atendido.
        *proximoEhPreferencial = false; // Define que o próximo atendimento NÃO será preferencial (voltará para comum).

    }

    // SEGUNDO CENÁRIO: Tentar atender um cliente comum se NÃO for a vez do preferencial E o limite de comuns não foi atingido E houver clientes na fila comum.
    else if (filaComum->tam > 0 && *contadorComum < LIMITE_COMUM) {
        printf("\nAtendendo cliente da Fila Comum...\n");

        // Chama a função para atender o cliente da fila comum.
        atenderCliente(filaComum, clientesAtendidos);
        (*contadorComum)++; // Incrementa o contador de clientes comuns atendidos no ciclo atual.

        // Verifica se o limite de clientes comuns para o ciclo foi atingido.
        if (*contadorComum == LIMITE_COMUM) {
            *proximoEhPreferencial = true; // Se atingiu o limite, o próximo atendimento DEVE ser preferencial.
        }

    }

    // TERCEIRO CENÁRIO: Se o limite de comuns foi atingido OU não há mais clientes comuns disponíveis,
    // mas há clientes preferenciais esperando. Força o atendimento de um preferencial.
    else if (filaPreferencial->tam > 0) {
        printf("\nAtendendo cliente da Fila Preferencial (prioridade ou limite de comuns atingido)...\n");
        // Chama a função para atender o cliente da fila preferencial.
        atenderCliente(filaPreferencial, clientesAtendidos);
        *contadorComum = 0; // Reseta o contador de comuns.
        *proximoEhPreferencial = false; // Volta a priorizar comuns no próximo ciclo.

    }

    // QUARTO CENÁRIO: Se não há clientes preferenciais (ou não é a vez deles), mas há clientes comuns esperando.
    // Continua atendendo clientes comuns.
    else if (filaComum->tam > 0) {
        printf("\nAtendendo cliente da Fila Comum (sem preferenciais disponíveis)...\n");
        // Chama a função para atender o cliente da fila comum.
        atenderCliente(filaComum, clientesAtendidos);
        (*contadorComum)++; // Incrementa o contador de comuns.
        // Verifica se o limite de clientes comuns foi atingido.
        if (*contadorComum == LIMITE_COMUM) {
            *proximoEhPreferencial = true; // Se atingiu o limite, o próximo DEVE ser preferencial (quando houver).
        }
    }

    // ÚLTIMO CENÁRIO: Ambas as filas estão vazias.
    else {
        printf("\nAmbas as filas estão vazias! Nenhum cliente para atender.\n");
        *contadorComum = 0; // Reseta o contador de comuns.
        *proximoEhPreferencial = false; // Reseta o flag preferencial.
    }
}

// FUNÇÃO FEITA POR PETERSON
// Função que gerencia a saída do programa, liberando toda a memória alocada dinamicamente.
void handleOpcaoZero(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos) {
    printf("Saindo...\n");

    // Libera a memória alocada para os clientes e nós da fila comum.
    while (filaComum->primeiro != NULL) {
        NodeCliente* temp_node = filaComum->primeiro; // Armazena o nó atual.
        filaComum->primeiro = temp_node->proximo; // Avança o primeiro para o próximo nó.
        free(temp_node->cliente); // Libera a memória da estrutura Cliente associada ao nó.
        free(temp_node); // Libera a memória do NodeCliente (o nó da fila).
    }
    free(filaComum); // Libera a memória da estrutura Fila em si.

    // Libera a memória alocada para os clientes e nós da fila preferencial.
    while (filaPreferencial->primeiro != NULL) {
        NodeCliente* temp_node = filaPreferencial->primeiro; // Armazena o nó atual.
        filaPreferencial->primeiro = temp_node->proximo; // Avança o primeiro para o próximo nó.
        free(temp_node->cliente); // Libera a memória da estrutura Cliente associada ao nó.
        free(temp_node); // Libera a memória do NodeCliente (o nó da fila).
    }
    free(filaPreferencial); // Libera a memória da estrutura Fila em si.

    // Libera a memória alocada para os clientes e nós da lista de clientes atendidos.
    while (clientesAtendidos->primeiro != NULL) {
        NodeAtendido* temp_node = clientesAtendidos->primeiro; // Armazena o nó atual.
        clientesAtendidos->primeiro = temp_node->proximo; // Avança o primeiro para o próximo nó.
        free(temp_node->cliente); // Libera a memória da estrutura Cliente associada ao nó (que foi movida da fila).
        free(temp_node); // Libera a memória do NodeAtendido (o nó da lista de atendidos).
    }
    free(clientesAtendidos); // Libera a memória da estrutura ListaAtendidos em si.
}



// FUNÇÃO FEITA POR ISABELLA
// gera e exibe estatísticas de atendimento, incluindo o número total de clientes atendidos,
void gerarEstatisticas(ListaAtendidos *listaAtendidos) {
    // Variáveis para contagem e soma de tempos.
    int total_clientes_comuns = 0;
    int total_clientes_preferenciais = 0;
    int total_tempo_comuns = 0; // Usa int para evitar overflow em tempos longos.
    int total_tempo_preferenciais = 0;
    int total_itens_processados = 0; // Variável para somar o total de itens de todos os clientes atendidos.

    // Ponteiro auxiliar para percorrer a lista de clientes atendidos, começando do primeiro.
    NodeAtendido* atual = listaAtendidos->primeiro;

    while (atual != NULL) {
        if (atual->cliente->prioridade) {
            total_clientes_preferenciais++; // Incrementa o contador de clientes preferenciais.
            total_tempo_preferenciais += atual->cliente->tempo; // Soma o tempo de atendimento do cliente preferencial.
        } else {
            total_clientes_comuns++; // Incrementa o contador de clientes comuns.
            total_tempo_comuns += atual->cliente->tempo; // Soma o tempo de atendimento do cliente comum.
        }
        // Soma os itens do cliente atual ao total geral de itens processados.
        total_itens_processados += atual->cliente->itens;
        atual = atual->proximo;
    }

    printf("\n==== ESTATÍSTICAS DE ATENDIMENTO ====\n");
    printf("Total de clientes atendidos: %d\n", listaAtendidos->total_clientes_atendidos);
    printf("Total de itens processados: %d\n", total_itens_processados);

    printf("\n=== Clientes Preferenciais ===\n");
    printf("Número de clientes atendidos: %d\n", total_clientes_preferenciais);

    if (total_clientes_preferenciais > 0) {
        double tempo_medio_preferencial = (double)total_tempo_preferenciais / total_clientes_preferenciais;
        printf("Tempo médio de atendimento:");

        int minutos_medios = (int)tempo_medio_preferencial / 60;
        int segundos_medios = (int)tempo_medio_preferencial % 60;

        // Exibe o tempo médio formatado.
        if (minutos_medios > 0) {
            printf("%d minuto(s) e %d segundos", minutos_medios, segundos_medios);
        } else {
            printf("%d segundo(s)", segundos_medios);
        }
        printf(")\n");
    } else {
        printf("Nenhum cliente preferencial atendido.\n"); // Mensagem se não houver preferenciais atendidos.
    }

    printf("\n--- Clientes Comuns ---\n");
    printf("Número de clientes atendidos: %d\n", total_clientes_comuns);

    if (total_clientes_comuns > 0) {
        double tempo_medio_comum = (double)total_tempo_comuns / total_clientes_comuns;
        printf("Tempo médio de atendimento: ");

        int minutos_medios = (int)tempo_medio_comum / 60;
        int segundos_medios = (int)tempo_medio_comum % 60;

        // Exibe o tempo médio formatado.
        if (minutos_medios > 0) {
            printf("%d minuto(s) e %d segundos", minutos_medios, segundos_medios);
        } else {
            printf("%d segundos", segundos_medios);
        }
        printf(")\n");
    } else {
        printf("Nenhum cliente comum atendido.\n");
    }

    printf("\n=====================================\n");
}
