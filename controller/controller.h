#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdio.h>
#include <stdbool.h>
#include "../estruturas.h"

void menuEscolhas();
bool validarInputNumerico(const char* input);
int lerInteiroValidado(const char* prompt);
void retornarMenu();

void inserirClienteNaFila(Fila *filaComum, Fila *filaPreferencial);
void atenderFilaCliente(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos, int *contadorComum, const int LIMITE_COMUM, bool *proximoEhPreferencial);
void imprimirFilaCliente(Fila *filaComum, Fila *filaPreferencial);
void exibirEstatisticas(ListaAtendidos *listaAtendidos);
void sairPrograma(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos);


#endif
