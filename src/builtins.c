/**
 * @file        builtins.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Implementation of internal commands (built-ins)
 * @date        2026-07-10
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
    if (tokens[1] == NULL) {
        chdir(getenv("HOME"));
    } else {
        if (chdir(tokens[1]) != 0) {
            perror("brash");
        }
    }
}

builtin_command builtin_table[] = {
    {"cd", brash_cd},
    {NULL, NULL},
};