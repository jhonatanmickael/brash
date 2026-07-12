/**
 * @file        brash.h
 * @author      Jhonatan Mickael
 * @brief       Brash - Header file containing function prototypes
 * @date        2026-07-12
 */

#ifndef BRASH_H
#define BRASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef  PATH_MAX
#define  PATH_MAX   4096
#endif

#define  CMD_SIZE   PATH_MAX
#define  CLEAR      "\033[H\033[J"
#define  RESET      "\033[0m"
#define  BOLD       "\033[1m"
#define  GREEN      "\033[32m"
#define  YELLOW     "\033[33m"
#define  BLUE       "\033[34m"

typedef struct {
    char *name_command;
    void (*func)(char **);
} builtin_command;

// file: io.c
void     clear_buffer(void);
void     parser_command(char *command, char **tokens);
int      read_input(char *var, int size);
void     print_prompt(void);

// file: dispatcher.c 
int      dispatch_builtin(char **tokens);

// file: executor.c
void     execute_command(char *tokens[]);

// file: builtins.c 
void     brash_cd(char **tokens);
void     brash_exit(char **tokens);
extern   builtin_command builtin_table[];

// global variables
extern char  *tokens[64];
extern char  *home;
extern char  cwd[PATH_MAX];
extern char  oldcwd[PATH_MAX];

#endif