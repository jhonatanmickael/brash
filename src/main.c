/**
 * @file        main.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Main loop and command execution logic
 * @date        2026-06-28
 * @note        Architecture Note: For now, all logic resides in main.c for simplicity 
 * during the initial development phase. As the project evolves, this 
 * code will be refactored into a modular structure, with specific 
 * functions separated into their own header and source files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_SIZE 80
#define CLEAR "\033[H\033[J"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"

int read_input(char *var, int size){
    fflush(stdout);
    if(fgets(var, size, stdin)){
        if(strchr(var, '\n') != NULL){
            var[strcspn(var, "\n")] = '\0';
            return 0;
        }
        else {
            int i;
            while((i = getchar()) != '\n' && i != EOF);
            fprintf(stderr, "brash: erro: Limite de caracteres estourado\n");
            return 1;
        }
    }
    else{
        fprintf(stderr, "brash: erro: Falha na leitura\n");
        return 1;
    }
}

int main(){
    printf(CLEAR);
    fflush(stdout);

    char command[CMD_SIZE];

    while(1){
        printf(BOLD GREEN "brash" RESET "@user >> ");     
     
        if(read_input(command, CMD_SIZE) == 0){
            if (strlen(command) > 0) {
             fprintf(stderr, "brash: %s: comando não encontrado\n", command);
            }
        }
    }

    return 0;
}