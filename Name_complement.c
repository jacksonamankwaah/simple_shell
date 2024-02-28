#include <stdio.h>

/**
	* main - this describes the main function of the code
	* This project deploys the Betty Style
	* We are doing this for our first project
	* This programe receive input from user and then comment
	* Return: 0
*/

int main(void)
{
	char name[31];

	printf("Please put your name here: ");
	scanf("%s", name);

	printf("Hello %s\nYou are beautiful!", name);
	return (0);
}
