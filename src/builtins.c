/**
 * @file        builtins.c
 * @author      Jhonatan Mickael
 * @brief       Brash - Implementation of internal commands (built-ins)
 * @date        2026-07-08
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