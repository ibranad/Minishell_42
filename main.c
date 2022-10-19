/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/19 20:07:44 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/10/19 08:44:16 by obouizga         ###   ########.fr       */
>>>>>>> ec5cca735b50c203d3c4e99424277083a1467da8
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
	char		*cmd_line;
	t_cmdl		*ptr;
	t_toklist	*tokens;


	(void)ac;
	(void)av;
	(void)env;
	int i = 0;
	shell.env = set_env(env);
	while (1)
	{
        cmd_line = readline(CYAN "Minishell $> " WHITE);
		if (cmd_line[i])
		{
            add_history(cmd_line);
			if (check_unrequired_by_subject(cmd_line) == -1)
				printf("Syntax error: Unclosed quote\n");
			else
			{
				cmd_line = expand_var_in_str(shell.env, cmd_line);
				tokens = lexer(cmd_line);
				print_tokens(tokens->next);
<<<<<<< HEAD
				ptr = parse_list(tokens->next, shell.env);
				print_parsing_lst(ptr);
=======
				// parse_list(tokens->next, shell.env);
>>>>>>> ec5cca735b50c203d3c4e99424277083a1467da8
			}
		}
	}
	return (0);
}