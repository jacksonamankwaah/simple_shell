#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/**
 * run_command_with_args - Executes a command with arguments in a child process
 * @command: The command to be executed
 * @args: An array of arguments (including the command itself)
 */
void run_command_with_args(char *command, char **args)
{
pid_t pid;
int status;


pid = fork();


if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}


if (pid == 0)
{
/* Executing the command in the child process with arguments */
if (execvp(command, args) == -1)
{
perror("exec");
exit(EXIT_FAILURE);
}


perror("exec");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);


/* Handling exit status and signals */
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
fprintf(stderr, "./myshell: Command not found\n");
}
else if (WIFSIGNALED(status))
{
fprintf(stderr, "./myshell: Terminated by signal %d\n", WTERMSIG(status));
}
}
}
