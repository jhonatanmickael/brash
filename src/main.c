/**
 * @file        main.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Main loop and command execution logic
 * @date        2026-07-05
 */

#include "brash.h"

int main(){  
    char  command[CMD_SIZE];
    int   status_command;
    int   flag=1;
    char  *copy_command;
    char  *tokens[64];
    
    printf(CLEAR);
    fflush(stdout);

    while(flag){
        printf(BOLD GREEN "brash" RESET "@user >> ");    
        status_command = read_input(command, CMD_SIZE);
        
        switch (status_command){    
            case 0:
                if (strlen(command) > 0) {
                    copy_command = strdup(command);
                    parser_command(copy_command, tokens);
                    execute_command(tokens);
                }
                free(copy_command);
                copy_command=NULL;
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