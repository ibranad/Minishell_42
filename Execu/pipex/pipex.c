/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		close_fail();
}

void	exec_convenient_command(t_cmdl *curr, int *fildes, char **env)
{
	if (!curr->idx)
		first_cmd(fildes, curr, command_validity(curr), env);
	else if (!curr->next)
		last_cmd(curr, command_validity(curr), env);
	else
		mid_cmd(fildes, curr, command_validity(curr), env);
}

void	pipex(t_cmdl *cmdl, char **env)
{
	int		fildes[2];
	t_cmdl	*curr;
	pid_t	*pids;
	int		i;

	curr = cmdl;
	i = 0;
	pids = malloc(sizeof(int) * cmdline_size(cmdl));
	if (!pids)
		malloc_fail();
	while (curr)
	{
		pipe(fildes);
		pids[i] = ft_fork();
		if (!pids[i])
			exec_convenient_command(curr, fildes, env);
		read_from_pipe(fildes);
		ft_close(fildes[READ_END]);
		curr = curr->next;
		i++;
	}
	ft_close(0);
	wait_all_pipeline(pids);
}
