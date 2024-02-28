#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>


/**
 * run_command - Executes a command in a child process
 * @command: The command to be executed
 */
void run_command(char *command)
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
/* Executing the command in the child process */
if (execlp(command, command, (char *)NULL) == -1)
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
