#include "controller.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "../estruturas.h"
#include "../filas/filas.h"
#include "../clientes/clientes.h"
#include "../atendimentos/atendimentos.h"

void menuEscolhas() {
    printf("\n===================MENU===================\n");
    printf("\nEscolha uma opção: \n");
    printf("1 - Inserir cliente na fila\n");
    printf("2 - Atender cliente \n");
    printf("3 - Imprimir as filas\n");
    printf("4 - Gerar estatísticas de atendimento\n");
    printf("0 - Sair\n");
}

bool validarInputNumerico(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return false; // Retorna falso se a string for nula ou vazia
    }

    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return false; // Encontrou um caractere que não é dígito
        }
        i++;
    }

    return true; // Todos os caracteres são dígitos
}

int lerInteiroValidado(const char* prompt) {
    char buffer[20]; // Um buffer para ler a entrada como string, 20 é suficiente para um int
    bool entradaValida = false;

    do {
        printf("%s", prompt); // Mostra a mensagem para o usuário

        // Lê a entrada do usuário de forma segura
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro ao ler a entrada. Saindo.\n");
            return -1; // Retorna um valor de erro
        }

        // Se a entrada foi muito longa, o '\n' não estará no buffer.
        // Neste caso, precisamos limpar o resto da linha do buffer de entrada.
        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Remove o caractere de nova linha '\n' do buffer, se ele existir
        buffer[strcspn(buffer, "\n")] = 0;

        // Usa a nossa função auxiliar para validar se o conteúdo é numérico e não vazio
        entradaValida = validarInputNumerico(buffer);

        if (!entradaValida) {
            printf("Entrada inválida. Por favor, digite apenas números.\n");
        }

    } while (!entradaValida);

    // Converte a string validada para inteiro e a retorna
    return atoi(buffer);
}

void retornarMenu() {
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar(); // Espera pelo Enter do usuário
    printf("\nVoltando para a página inicial");
}

void inserirClienteNaFila(Fila *filaComum, Fila *filaPreferencial){
    char nome[50];
    bool prioridade = false;
    int itens = 0;
    char resp;

    printf("Digite o nome do cliente: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;
    itens = lerInteiroValidado("Digite a quantidade de itens do cliente: ");
        do {
            printf("O cliente é prioritário? (s/n): ");
            scanf(" %c", &resp); 
            getchar(); // Limpa o buffer de entrada

            if (resp == 's' || resp == 'S') {
                prioridade = true; // Define o cliente como prioritário.
                break;
            }
            else if (resp == 'n' || resp == 'N') {
                prioridade = false; // Define o cliente como não prioritário.
                break;
            }
            else {
                printf("Resposta inválida!\n"); // Informa ao usuário.
            }
        } while (1);
    // Chama a função para cadastrar o cliente, passando as filas e os dados do cliente.
    cadastrarCliente(filaComum, filaPreferencial, nome, prioridade, itens);
    retornarMenu(); // Chama a função para retornar ao menu principal.
}

void atenderFilaCliente(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos, int *contadorComum, const int LIMITE_COMUM, bool *proximoEhPreferencial) {
    handleOpcaoDois(filaComum, filaPreferencial, clientesAtendidos, contadorComum, LIMITE_COMUM, proximoEhPreferencial);
    retornarMenu(); // Chama a função para retornar ao menu principal.
};

void imprimirFilaCliente(Fila *filaComum, Fila *filaPreferencial) {
    imprimirAmbasFilas(filaComum, filaPreferencial);
    // getchar(); // Espera pelo Enter do usuário para continuar.
    retornarMenu(); // Chama a função para retornar ao menu principal.
}

void exibirEstatisticas(ListaAtendidos *listaAtendidos) {
    gerarEstatisticas(listaAtendidos);
    retornarMenu(); // Chama a função para retornar ao menu principal.
}

void sairPrograma(Fila *filaComum, Fila *filaPreferencial, ListaAtendidos *clientesAtendidos) {
    printf("\nSaindo do programa...\n");
    Sleep(500); // Pausa de 500 milissegundos para o usuário ler a mensagem.
    handleOpcaoZero(filaComum, filaPreferencial, clientesAtendidos);
    exit(0); // Encerra o programa.
}