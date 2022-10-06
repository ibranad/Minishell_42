#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_cmdl	*command;

	
	shell.env = set_env(env);
	command = parse(ac, av, shell.env);
	execute(command, shell);
	return (0);
}