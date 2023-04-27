#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    int id;
    char name[10];
    struct LinkedList *previous;
}; typedef struct LinkedList node;


void Option(int *sair, node *Head) {
    printf("\n\n----------\nEscolha uma das opcoes:\n0. Sair\n----------\n\n");
    scanf("%d", sair);

    switch (*sair)
    {
    case 0:
        printf("\n\n---------\nSaindo...\n----------\n\n");
        exit(1);
        break;
    case 1:
        //DataInsertion(Head);
        break;
    default:
        printf("\n\n----------\nOpcao Invalida!\n----------\n\n");
    }
}

int main() {
    node *Head = (node *) malloc(sizeof(node));
    Head -> previous = NULL;
    printf("\n----------\nBem Vindo(a)\n----------\n");

    int sair;
    do
    {
        Option(&sair, Head);
    } while (sair != 0);
    
    free(Head);
    return 0;
}