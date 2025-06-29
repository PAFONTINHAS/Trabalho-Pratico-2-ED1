#include "mocks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "estruturas.h"
#include "filas/filas.h"
#include "clientes/clientes.h"
#include "../controller/controller.h"
#include "atendimentos/atendimentos.h"


int main(){
    Fila* filaComum = criarFila();
    Fila* filaPreferencial = criarFila();
    ListaAtendidos* clientesAtendidos = criarListaAtendidos();


    // Variáveis para controlar a lógica de atendimento alternado:
    // Conta quantos clientes comuns foram atendidos desde o último preferencial.
    int contadorComum = 0;

    // Define o limite de clientes comuns a serem atendidos antes de um preferencial (2 comuns).
    const int LIMITE_COMUM = 2;

    // Flag booleana que indica se o próximo atendimento *deve* ser de um cliente preferencial.
    bool proximoEhPreferencial = false;

    int opcao;
    preencherListaParticipantes(filaComum, filaPreferencial);

    system("cls");

    menuEscolhas();
    opcao = lerInteiroValidado("\nOpção: ");
    while(opcao != 0){
        switch(opcao){
            case 1:
                // Chama a função para cadastrar um cliente interativamente (pedindo dados ao usuário).
                inserirClienteNaFila(filaComum, filaPreferencial);
                break;
            case 2:
                // Chama a função 'handleOpcaoDois' que contém a lógica de atendimento alternado.
                // Passa as filas, a lista de atendidos e as variáveis de controle por referência.
                atenderFilaCliente(filaComum, filaPreferencial, clientesAtendidos, &contadorComum, LIMITE_COMUM, &proximoEhPreferencial);
                break;
            case 3:
                // Chama a função para imprimir o estado atual de ambas as filas.
                imprimirFilaCliente(filaComum, filaPreferencial);
                break;
            case 4:
                // Chama a função para gerar e exibir as estatísticas de atendimento.
                exibirEstatisticas(clientesAtendidos);
                break;
        }

        system("cls");

        menuEscolhas();
        opcao = lerInteiroValidado("\nOpção: ");

    }

    sairPrograma(filaComum, filaPreferencial, clientesAtendidos);

    return 0;
}
