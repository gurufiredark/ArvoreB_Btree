#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

void in_ordem(int byte_atual, FILE * binary)
{
    char fragmento[4];
    int filhos[ORDEM];
    int chaves[ORDEM-1];
    char pagina[TAM_PAGE_STR];

    fseek(binary, byte_atual, SEEK_SET);
    fread(pagina, 1, TAM_PAGE_STR, binary);

    Ler_pagina(chaves, filhos, fragmento, pagina);

    for (int i = 0; i < ORDEM; i++)
    {
        if (filhos[i] != -1)
        {
             in_ordem(filhos[i], binary);
        }

        if(chaves[i] != -1 && i != 4)
        {
            printf(" %i |", chaves[i]);
        }
    }
}

void Imprime_Percurso(void)
{
    FILE * binary;

    if ((binary = fopen("btree.dat", "r")) == NULL)
    {
        printf("Falha ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    char byte_raiz[4];

    rewind(binary);
    fread(byte_raiz, 1, sizeof(int), binary);

    in_ordem(atoi(byte_raiz), binary);

    printf("\b ");
    printf("\n");

    fclose(binary);

}
