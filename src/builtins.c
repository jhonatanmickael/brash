/**
 * @file        builtins.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Implementation of internal commands (built-ins)
 * @date        2026-07-12
 */

#include "brash.h"

/* 
 * The builtins.c file contains the implementation of internal shell commands 
 * (e.g., cd, exit, pwd). These commands are executed directly within the 
 * shell's process memory space, without the need for fork() or execvp().
 * 
 * Its core responsibilities include:
 * 1. Defining and implementing logic for built-in command behavior.
 * 2. Managing internal shell state (like current working directory or environment).
 * 3. Providing a clear interface for the dispatcher to execute these commands.
 */

void brash_cd(char **tokens) {
    char    *target = NULL;
    char    full_path[PATH_MAX];

    if(tokens[1] == NULL || (strcmp(tokens[1], "~") == 0)) {
        target = home;
    }
    else if(tokens[1][0] == '~' && tokens[1][1] == '/' ) {
        strcpy(full_path, home);
        strcat(full_path, tokens[1]+1);
        target = full_path;
    }
    else if((strcmp(tokens[1], "-")) == 0) {
        if (oldcwd[0] != '\0') {
          target = oldcwd;
        }
    }
    else {
        target = tokens[1];
    }

    if(target == NULL) {
        fprintf(stderr, "brash: erro: destino inválido\n");
        return;
    }
    else if(chdir(target) != 0)  {
        perror("brash");
    }
    else {
        strcpy(oldcwd, cwd);
        getcwd(cwd, sizeof(cwd));
    }

    return;
}

void brash_exit(char **tokens){
    (void)tokens;
    exit(0);
}

builtin_command builtin_table[] = {
    {"cd", brash_cd},
    {"exit", brash_exit},
    {NULL, NULL},
};