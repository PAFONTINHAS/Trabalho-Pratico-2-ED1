#ifndef filas_h
#define filas_h
#include "../estruturas.h"


// FUNÇÃO FEITA POR GIOVANNA
// Função que cria e inicializa uma nova fila vazia.
Fila* criarFila();

// FUNÇÃO FEITA POR GIOVANNA
// Função que insere um novo cliente no final da fila (FIFO).
void inserirClienteFila(Fila *fila, Cliente *cliente);

// FUNÇÃO FEITA POR CLARISSA
// Função que remove o primeiro cliente da fila e o adiciona à lista de clientes atendidos.
NodeCliente* atenderCliente(Fila *fila, ListaAtendidos *listaAtendidos);

// FUNÇÃO FEITA POR CLARISSA
// Função que imprime o conteúdo de uma única fila.
void imprimirFila(Fila *fila);

// FUNÇÃO FEITA POR CLARISSA
// Função que imprime o conteúdo de ambas as filas (preferencial e comum) separadamente.
void imprimirAmbasFilas(Fila *filaComum, Fila *filaPreferencial);

// FUNÇÃO FEITA POR JOÃO VICTOR
// Funçao que cria e inicializa uma nova lista de clientes atendidos vazia.
ListaAtendidos* criarListaAtendidos();

// FUNÇÃO FEITA POR JOÃO VICTOR
// Funçãodiciona um cliente à lista de clientes atendidos.
void adicionarClienteAtendido(ListaAtendidos *lista, Cliente *cliente);

// FUNÇÃO FEITA POR JOÃO VICTOR
// Função que converte um tempo total em segundos para o formato de minutos e segundos e o exibe.
void exibirTempoFormatado(int totalSegundos);

#endif
