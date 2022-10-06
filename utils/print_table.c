#include "../minishell.h"

void	print_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		printf("%s\n", table[i++]);
}