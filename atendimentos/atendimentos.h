#ifndef ATENDIMENTOS_H
#define ATENDIMENTOS_H
#include "../filas/filas.h"
#include "../estruturas.h"

// FUNÇÃO FEITA POR PETERSON
// Função que gerencia a lógica de atendimento de clientes, alternando entre filas comum e preferencial.
void handleOpcaoDois(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos, int *contadorComum, const int LIMITE_COMUM, bool *proximoEhPreferencial);

// FUNÇÃO FEITA POR PETERSON
// Função que gerencia a saída do programa, liberando toda a memória alocada dinamicamente.
void handleOpcaoZero(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos);

// FUNÇÃO FEITA POR ISABELLA
// Gera e exibe estatísticas de atendimento, como tempo médio e número de clientes por categoria.
void gerarEstatisticas(ListaAtendidos *listaAtendidos);

#endif
