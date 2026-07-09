/**
 * @file        dispatcher.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Command routing engine (Dispatcher)
 * @date        2026-07-08
 */

#include "brash.h"

/* 
 * TODO: This file serves as the core command routing engine. It acts as a 
 * "traffic controller" that intercepts user input tokens:
 * 
 * 1. It iterates through the list of internal commands (built-ins) defined in builtins.c.
 * 2. If a match is found, it executes the corresponding internal function.
 * 3. If no match is found, it forwards the command to executor.c to be handled 
 *    as an external process via fork/execvp.
 * 
 * This approach decouples the command decision logic from the actual execution 
 * mechanisms, allowing for easy expansion of shell features.
 */

int dispatch_builtin(char **tokens) {
    for(int i = 0; builtin_table[i].name_command != NULL; i++) {
        if(!strcmp(tokens[0], builtin_table[i].name_command)) {
            builtin_table[i].func(tokens); 
            return 0;
        }
    }
    return 1;
}