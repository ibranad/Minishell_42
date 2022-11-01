/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 17:31:13 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac; 
	(void)av;
	t_cmdl	*cmd_line;
	int 	fd;
	int		fd1;

	fd = dup(0);
	fd1 = dup(1);
	shell.env = set_env(env);
	while (1) 
	{
		handle_signals(before_readline_handle);
		cmd_line = parser();
		handle_signals(after_readline_handle);
		// print_parsing_lst(cmd_line);
		// exit(EXIT_SUCCESS);
		// continue;	 
		execute(cmd_line, env);
		dup2(fd, STDIN_FILENO);
		dup2(fd1, STDOUT_FILENO);
	}
	return (0);
}
