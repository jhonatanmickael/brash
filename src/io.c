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