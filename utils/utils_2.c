/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:01:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 17:02:33 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

pid_t	ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		fork_fail();
	return (id);
}

void	wait_all(void)
{
	while (wait(&g_shell.status) != -1)
		continue ;
	set_commands_exit_status();
}

void	wait_all_pipeline(pid_t *pids)
{
	int	i;

	i = 0;
	while (waitpid(pids[i], &g_shell.status, 0) != -1)
		i++;
	set_commands_exit_status();
	free(pids);
}

void	ft_execve(t_cmdl *cmd, char **env)
{
	if (execve(cmd->path, cmd->args, env) == -1)
		execve_fail();
}
