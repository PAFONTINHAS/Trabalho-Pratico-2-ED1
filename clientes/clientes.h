#ifndef CLIENTES_h
#define CLIENTES_h
#include <stdbool.h>
#include "../estruturas.h"


// FUNÇÃO FEITA POR PETERSON
// Calcula o tempo de atendimento estimado com base no número de itens.
int calcularTempo(int itens);

// FUNÇÃO FEITA POR ISABELLA
//Cadastra um novo cliente com base na entrada do usuário (interativo).
Cliente* cadastrarCliente(Fila *filaComum, Fila *filaPreferencial, const char *nome, bool prioridade, int itens);


#endif
