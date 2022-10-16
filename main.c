/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/16 16:10:47 by obouizga         ###   ########.fr       */
=======
/*   Updated: 2022/10/15 15:24:46 by ibnada           ###   ########.fr       */
>>>>>>> b43a22488e6035868522dcf611497b065a73bae1
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

/*
int main(int ac, char **av, char **env)
{
	t_cmdl		*command_line;
	t_toklist	*tokens;
	
	shell.env = set_env(env);
	while (1)
	{
		command_line = readline("minishell $");
		execute(command_line, shell);
	}
	return (0);
}
*/


int main(int ac, char **av, char **env)
{
	t_toklist	*tokens;
	char		*cmd_line;


	(void)ac;
	(void)av;
	(void)env;
	// shell.env = set_env(env);
	while (1)
	{
		cmd_line = readline("minibash $> ");
		printf("\n");
		str_tolower(cmd_line);
		tokens = lexer(cmd_line);
		print_tokens(tokens->next);
		printf("\n");
	}
	return (0);
}