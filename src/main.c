/**
 * @file        main.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Main loop and command execution logic
 * @date        2026-06-30
 * @note        Architecture Note: For now, all logic resides in main.c for simplicity 
 * during the initial development phase. As the project evolves, this 
 * code will be refactored into a modular structure, with specific 
 * functions separated into their own header and source files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_SIZE 1024
#define CLEAR "\033[H\033[J"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"

void clear_buffer(){
    int i;
    while((i = getchar()) != '\n' && i != EOF);
}

int read_input(char *var, int size){
    fflush(stdout);
    if(fgets(var, size, stdin)){
        if(strchr(var, '\n') != NULL){
            var[strcspn(var, "\n")] = '\0';
            return 0;
        }
        else {
            clear_buffer();
            return 1;
        }
    }
    else{
        if(feof(stdin)) return 2;
        else if(ferror(stdin)) return 3;
        return 4;
    }
}

int main(){
    printf(CLEAR);
    fflush(stdout);

    char command[CMD_SIZE];
    int status_command, flag=1;

    while(flag){
        printf(BOLD GREEN "brash" RESET "@user >> ");     
        status_command=read_input(command, CMD_SIZE);
        switch (status_command){
            case 0:
                if (strlen(command) > 0) {
                    fprintf(stderr, "brash: %s: comando não encontrado\n", command);
                }
                break;
            case 1:
                fprintf(stderr, "brash: erro: Limite de caracteres estourado\n");
                break;
            case 2:
                printf(CLEAR);
                flag--;
                break;
            case 3:
                fprintf(stderr, "brash: erro: Falha na leitura\n");
                break;
            default:
                fprintf(stderr, "brash: erro: estado de entrada inesperado (%d)\n", status_command);
                break;
        } 
    }

    return 0;
}