#include "../../Header/minishell.h"

void	_pwd(void)
{
	char	*s;

	s = malloc(250);
	printf("%s\n", getcwd(s, 250));
	free(s);
}
