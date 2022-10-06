#include "../minishell.h"

int main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", getenv(av[1]));
	return (0);
}