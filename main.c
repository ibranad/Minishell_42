/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/18 13:16:34 by ibnada           ###   ########.fr       */
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
	shell.env = set_env(env);
	while (1)
	{
        cmd_line = readline(CYAN "Minishell $> " WHITE);
		if (cmd_line)
		{
            add_history(cmd_line);
			if (check_unrequired_by_subject(cmd_line) == -1)
				printf("Syntax error: Unclosed quote\n");
			else
			{
				cmd_line = expand_var_in_str(shell.env, cmd_line);
				tokens = lexer(cmd_line);
				print_tokens(tokens->next);
				parse_list(tokens->next, shell.env);
			}
		}
	}
	return (0);
}