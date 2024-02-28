#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show_custom_prompt(void);
char *get_user_input(void);
void run_command(char *command);
void run_command_with_args(char *command, char **args);
void execute_command_2(char **args);
char *read_command(void);
void display_prompt(void);

#endif
