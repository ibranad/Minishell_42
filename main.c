/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_cmdl	*cmd_line;
	int		fd;
	int		fd1;

	(void)ac;
	(void)av;
	fd = dup(0);
	fd1 = dup(1);
	setup(env);
	while (1)
	{
		g_shell.in_heredoc = 0;
		g_shell.here_sigint = 0;
		g_shell.prs_error = 0;
		handle_signals(before_readline_handle);
		cmd_line = parser();
		handle_signals(after_readline_handle);
		execute(cmd_line, env);
		free_cmdl_lst(&cmd_line);
		dup2(fd, STDIN_FILENO);
		dup2(fd1, STDOUT_FILENO);
	}
	return (0);
}
