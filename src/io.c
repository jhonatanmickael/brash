#include "brash.h"

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

// A new directory for this function will be created soon
void parser_command(char *command, char **tokens) {
    int i=0;
    tokens[i] = strtok(command, " \n\t");
    while (tokens[i] != NULL && i < 63) {
        i++;
        tokens[i] = strtok(NULL, " \n\t");
    }

}

// A new directory for this function will be created soon
void execute_command(char *tokens[]) {
    pid_t pid = fork();
    if (pid<0) {
        perror("brash: falha ao criar processo");
        return;
    } 
    else if (pid==0) {
        execvp(tokens[0], tokens);
        fprintf(stderr, "brash: %s: comando não encontrado\n", tokens[0]);
        exit(EXIT_FAILURE);
    } 
    else {
        wait(NULL);
    }
}