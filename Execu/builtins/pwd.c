#include "../minishell.h"

void	pwd(void)
{
	char	*s;

	s = malloc(250);
	printf("%s\n", getcwd(s, 250));
	free(s);
}
