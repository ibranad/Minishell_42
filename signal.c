#include "Header/minishell.h"
#include <signal.h>

void	handler()
{
	write(STDOUT_FILENO, "I won't die\n", 13);
}

int main(void)
{

	signal(SIGTERM, handler);
	signal(SIGINT, handler);
	while (1)
	{
		printf("keep running %d\n", getpid());
		sleep(1);
	}
}
