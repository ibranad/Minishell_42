/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/20 13:52:23 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/10/20 15:40:05 by obouizga         ###   ########.fr       */
>>>>>>> 160157cc95a9243112d2a63aabe7240f477780f8
/*                                                                            */
/* ************************************************************************** */


#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
<<<<<<< HEAD
	(void)env;
	shell.env = set_env(env);
	while (1)
	{
        cmd_line = readline(CYAN "Minishell $> " WHITE);
		printf("\033[0m");
		if (cmd_line[0])
		{
            add_history(cmd_line);
			if (check_unrequired_by_subject(cmd_line) == -1)
				printf("Syntax error: Unclosed quote\n");
			else
			{
				cmd_line = expand_var_in_str(shell.env, cmd_line);
				tokens = lexer(cmd_line);
				print_tokens(tokens->next);
				ptr = parse_list(tokens->next, shell.env);
				print_parsing_lst(ptr);
			}
		}
=======
	t_cmdl	*cmd_line;

	shell.env = set_env(env);
	while (1)
	{
		cmd_line = parser(shell.env);
		print_parsing_lst(cmd_line);
		execute(cmd_line, shell);
		handle_signals();
>>>>>>> 160157cc95a9243112d2a63aabe7240f477780f8
	}
	return (0);
}