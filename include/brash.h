#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string.h>
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

void   clear_buffer(void);
void   parser_command(char *command, char **tokens);
void   execute_command(char *tokens[]);
int    read_input(char *var, int size);