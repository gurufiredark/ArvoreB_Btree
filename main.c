//Author: Lucas Beluomini
//RA: 120111
//Data: 20/10/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "paginas.h"
#include "Ordem.h"
#include "imprimetree.h"

int main(int argc, char *argv[]) {

    if (argc == 3 && strcmp(argv[1], "-c") == 0) {

        printf("---> Modo de criacao de arvore ativado ... nome do arquivo = %s\n", argv[2]);
        int error_log = inicializacao(argv[2]);
        printf("\nImportacao concluida com sucesso !!!");

    }else if(argc == 2 && strcmp(argv[1], "-p") == 0) {

        printf("---> Modo de impressao das informacoes ativado ...");
        imprime_arvore();

    } else if (argc == 2 && strcmp(argv[1], "-k") == 0) {

        printf("---> Modo de impressao de chaves ativado ...\n");
        Imprime_Percurso();

    } else {

        fprintf(stderr, "Argumentos incorretos!\n");
        fprintf(stderr, "Modo de uso:\n");
        fprintf(stderr, "$ %s (-c|-p|-k) nome_arquivo\n", argv[0]);
        fprintf(stderr, "$ %s -p\n", argv[0]);
        exit(EXIT_FAILURE);

    }

    return 0;
}