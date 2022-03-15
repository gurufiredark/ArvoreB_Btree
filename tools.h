#ifndef TOOLS_H
#define TOOLS_H
#include <stdio.h>
#include "tools.h"

#define DELIM_CH '|'
#define DELIM_STR "|"
#define ORDEM 5
#define TAM_PAGE 9
#define TAM_PAGE_STR 45

struct pagina{
    int qtdchaves;
    int chaves[ORDEM-1];
    int filhos[ORDEM];
};

int input(char *, int);
int ordenaVetor(int *, int);

int input(char * str, int size) {
    int i = 0;    
    char c = getchar();    
    while (c != '\n') {        
        if (i < size - 1) {            
            str[i] = c;            
            i++;                 
        }        
        c = getchar();   
    }    
    str[i] = '\0';    
    return i;
}

int ordenaVetor(int *vetor, int tamanho) {
    int aux;
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if(vetor[i] < vetor[j] && vetor[j] != -1 && vetor[i] != -1) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    return 0;
}

void Ler_pagina(int * chaves, int * filhos, char * fragmento, char * buffer)
{
    fragmento = strtok(buffer, DELIM_STR);
    int marcachave = 0;
    int marcafilho = 0;

    for (int i = 0; i < TAM_PAGE; i++)
    {
       if (i%2 == 0)
       {
            filhos[marcafilho] = atoi(fragmento);
            marcafilho++;
       }
       else
       {
           chaves[marcachave] = atoi(fragmento);
           marcachave++;
       }

       fragmento = strtok(NULL, DELIM_STR);
    }
}

#endif