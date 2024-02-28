#include "shell.h"


/**
 * show_custom_prompt - Displays my custom prompt for the shell
 */
void show_custom_prompt(void)
{
write(STDOUT_FILENO, "enter$ ", 10);
}
