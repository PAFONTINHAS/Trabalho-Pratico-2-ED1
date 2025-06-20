#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filas/filas.h"
#include "controller.h"

int main(){

    Fila* fila = criarFila();
    int opcao, valor;


    do{
        printf("\n-------MENU-------\n");
        printf("1 - Inserir cliente na fila\n");
        printf("2 - Atender cliente \n");
        printf("3 - Imprimir a fila\n");
        printf("0 - Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrarCliente(&fila);
                break;
            case 2:
                // atenderCliente(&fila);
                break;
            case 3:
                // imprimirFila(&fila);
                break;
            case 4:

                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("Opção inválida!");
                break;
        }

    }while(opcao != 0);

    return 0;
}
