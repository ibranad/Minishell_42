/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 14:08:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"


void	pipex(t_cmdl *cmdl, char **env)
{
	int		fildes[2];
	t_cmdl	*curr;
	if (!cmdl)
		return ;
	curr = cmdl;
	while (curr->next)
	{
		int flag = 0;
		pipe(fildes);
		if (curr->builtin == -1 && !curr->path)
		{
			flag = 1;
			_err_cmd_not_found(curr->args[0]);
		}
		if (flag == 0 && !ft_fork())
		{
			if (!curr->idx)
				first_cmd(fildes, curr,  env, 1);
			else
				mid_cmd(fildes, curr, env, 1);
		}
		else
			read_from_pipe(fildes);
		curr = curr->next;
	}
	if (!ft_fork())
		last_cmd(curr, env, 1);
	wait_all();
}