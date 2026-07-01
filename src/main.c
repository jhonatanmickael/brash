/**
 * @file        main.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Main loop and command execution logic
 * @date        2026-06-30
 */

#include "brash.h"

int main(){  
    char  command[CMD_SIZE];
    int   status_command;
    int   flag=1;
    int   i;        
    char  *copy_command;
    char  *tokens[64];
    
    printf(CLEAR);
    fflush(stdout);

    while(flag){
        printf(BOLD GREEN "brash" RESET "@user >> ");    

        status_command = read_input(command, CMD_SIZE);
        copy_command = strdup(command);
        
        switch (status_command){    
            case 0:
                if (strlen(command) > 0) {
                    i=0;
                    tokens[i] = strtok(copy_command, " \n\t");
                    while (tokens[i] != NULL && i < 63) {
                        i++;
                        tokens[i] = strtok(NULL, " \n\t");
                    }

                    fprintf(stderr, "brash: %s: comando não encontrado\n", command);

                    free(copy_command);
                    copy_command=NULL;
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