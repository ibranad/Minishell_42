/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:05:22 by ibnada           ###   ########.fr       */
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
		shell.in_heredoc = 0;
		shell.here_sigint = 0;
		shell.prs_error = 0;
		handle_signals(before_readline_handle);
		cmd_line = parser();
		handle_signals(after_readline_handle);
		print_parsing_lst(cmd_line);
		execute(cmd_line, env);
		free_cmdl_lst(&cmd_line);
		dup2(fd, STDIN_FILENO);
		dup2(fd1, STDOUT_FILENO);
	}
	return (0);
}//echo test1 > out test2 test3
