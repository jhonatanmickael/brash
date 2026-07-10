/**
 * @file        main.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Main loop and entry point of the shell
 * @date        2026-07-10
 */

#include "brash.h"

/* 
 * The main.c file acts as the primary orchestrator of the shell. 
 * Its only responsibilities are:
 * 1. Initializing the shell environment (e.g., clearing the screen).
 * 2. Running the main loop to read user input.
 * 3. Delegating the processing and execution to the dispatcher.
 */

char  *tokens[64];

int main(){  
    char  command[CMD_SIZE];
    int   status_command;
    int   flag=1;
    char  *copy_command;
    
    printf(CLEAR);
    fflush(stdout);

    while(flag){
        print_prompt();
        status_command = read_input(command, CMD_SIZE);
        
        switch (status_command){    
            case 0:
                if (strlen(command) > 0) {
                    copy_command = strdup(command);
                    
                    if (copy_command != NULL) {
                        parser_command(copy_command, tokens);

                        if (dispatch_builtin(tokens)) {
                            execute_command(tokens);
                        }

                        free(copy_command);
                        copy_command = NULL;
                    }
                    else {
                        fprintf(stderr, "brash: erro fatal: não foi possível alocar memória para o comando.\n");
                    }
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