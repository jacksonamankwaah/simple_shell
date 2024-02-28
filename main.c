#include "shell.h"


/**
 * main - Entry point for my custom shell program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
char *command;


while (1)
{
/* Displaying my custom prompt */
show_custom_prompt();
command = get_user_input();


if (command == NULL)
break;


/* Executing the entered command */
run_command(command);


free(command);
}


return (0);
}
