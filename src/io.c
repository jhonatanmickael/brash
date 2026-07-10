/**
 * @file        io.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Input handling and command parsing utilities
 * @date        2026-07-10
 */

#include "brash.h"

/* 
 * The io.c file handles all interactions with the user's input stream.
 * Its core responsibilities include:
 * 1. Reading raw input from stdin safely.
 * 2. Clearing input buffers to prevent stream corruption.
 * 3. Parsing the input string into a structured array of tokens (arguments).
 * 
 * This module ensures that the rest of the shell receives clean, 
 * ready-to-process data.
 */

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

void parser_command(char *command, char **tokens) {
    int i=0;
    tokens[i] = strtok(command, " \n\t");
    while (tokens[i] != NULL && i < 63) {
        i++;
        tokens[i] = strtok(NULL, " \n\t");
    }

}

void print_prompt(void) {
    char *user = getenv("USER");
    char *home = getenv("HOME");
    char cwd[PATH_MAX];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        if (strncmp(home, cwd, strlen(home)) == 0) {
            printf(BOLD BLUE "┌─[" GREEN "brash@%s" BLUE "]──[" YELLOW "~%s" BLUE "]\n" 
                   BOLD BLUE "└─" GREEN "» " RESET, user, cwd+strlen(home));
        }
        else {
            printf(BOLD BLUE "┌─[" GREEN "brash@%s" BLUE "]──[" YELLOW "%s" BLUE "]\n" 
                   BOLD BLUE "└─" GREEN "» " RESET, user, cwd);
        }
    }
    else {
        perror("brash: erro de diretório");
        printf(BOLD GREEN "brash" YELLOW "@%s " BLUE "?? " GREEN ">> " RESET, user);
    }
}