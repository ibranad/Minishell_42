/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 18:44:18 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac; 
	(void)av;
	t_cmdl	*cmd_line;
	int fd,fd1;

	fd = dup(0);
	fd1 = dup(1);
	shell.env = set_env(env);
	while (1) 
	{
		handle_signals();
		cmd_line = parser();
		// print_parsing_lst(cmd_line);
		// exit(EXIT_SUCCESS);
		// continue;	 
		execute(cmd_line, env);
		dup2(fd, STDIN_FILENO);
		dup2(fd1, STDOUT_FILENO);
	}
	return (0);
}
/*
	when runnign the sole command i check in the parent
	process that it wasn't about standard streams before 
	closing those fildes
*/