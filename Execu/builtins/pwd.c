#include "../../Header/minishell.h"

void	_pwd(void)
{
	char	*s;

	s = malloc(250);
	if (!getcwd(s, 250))
	{
		printf("%s\n", get_env_var(shell.env, "PWD"));
		free(s);
		return ;
	}
	printf("%s\n", getcwd(s, 250));
	free(s);
}
