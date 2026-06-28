/**
 * @file main.c
 * @author Jhonatan Mickael
 * @brief Loop principal e lógica de entrada de comandos do Brash.
 * @date 2026-06-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leitura(char *var, int tam){
    fflush(stdout);
    if(fgets(var, tam+2, stdin)){
        if(strchr(var, '\n') != NULL){
            var[strcspn(var, "\n")] = '\0';
            return 0;
        }
        else {
            int buffer;
            while((buffer = getchar()) != '\n' && buffer != EOF);
            fprintf(stderr, "MiniShell: erro: Limite de caracteres estourado\n");
            return 1;
        }
    }
    else{
        fprintf(stderr, "MiniShell: error: Falha na leitura\n");
        return 1;
    }
}

int main(){
    fflush(stdout);
    system("clear");

    int tam=80;
    char comando[tam];

    while(1){
        printf("MiniShell >> ");
        if(leitura(comando, tam)==0 ){
            printf("MiniShell: %s: comando não encontrado\n", comando);
        }
    }

    return 0;
}