/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:01:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 07:18:41 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"


int _min(int a, int b)
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

void	display_arr(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]\n", pids[i]);
}

void	wait_all(void)
{
	while (wait(&shell.status) != -1)
		continue ;	
}

int	look_for(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	ft_execve(t_cmdl *cmd, char **env)
{
	if (execve(cmd->path, cmd->args, env) == -1)
			execve_fail();
}