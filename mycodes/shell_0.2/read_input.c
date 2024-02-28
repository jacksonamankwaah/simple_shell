#include "shell.h"


/**
 * get_user_input - Reads a command from the user
 *
 * Return: A pointer to the user-entered command string, or NULL on failure
 */
char *get_user_input(void)
{
char *command = NULL;
size_t bufsize = 0;


/* Getting the user input using getline */
if (getline(&command, &bufsize, stdin) == -1)
{
free(command);
return (NULL);
}

return (command);
}

