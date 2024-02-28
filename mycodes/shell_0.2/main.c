#include "shell.h"
#include <stdlib.h>
#include <string.h>


/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
char *command;
char **args;
int arg_count;
char *token;


while (1)
{
show_custom_prompt();
command = get_user_input();


if (command == NULL)
break;


args = (char **)malloc(sizeof(char *));
if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}


arg_count = 0;
token = strtok(command, " ");


while (token != NULL)
{
args[arg_count] = token;
arg_count++;


args = (char **)realloc(args, (arg_count + 1) * sizeof(char *));
if (args == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}


token = strtok(NULL, " ");
}


args[arg_count] = NULL;


run_command_with_args(args[0], args);


free(args);
free(command);
}


return 0;
}
