/**
 * @file        executor.c
 * @author      Jhonatan Mickael
 * @brief       Brash - External command execution logic
 * @date        2026-07-08
 */

#include "brash.h"

/* 
 * The executor.c file manages the execution of external commands and 
 * system processes. Its core responsibilities include:
 * 
 * 1. Forking the current process to create a child process.
 * 2. Using execvp to replace the child process image with the target command.
 * 3. Handling process lifecycle (waiting for children, error reporting).
 * 
 * This module interacts directly with the kernel, keeping the shell's 
 * internal logic separate from system-level process management.
 */

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