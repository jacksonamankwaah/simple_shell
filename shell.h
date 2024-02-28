#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* Function Declarations */
void show_custom_prompt(void);
char *get_user_input(void);
void run_command(char *command);


#endif
