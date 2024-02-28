#include "shell.h"

/**
 * get_sigint - 
 * @sig: 
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "enter ", 5);
}
