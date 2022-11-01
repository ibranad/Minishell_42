/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 08:38:39 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
// void	close_pipe(int *fildes)
// {
// 	close(fildes[WRITE_END])
// 	close(fildes[READ_END])
// }

void	pipex(t_cmdl *cmdl, char **env)
{
	int		fildes[2];
	t_cmdl	*curr;
	int		flag;

	if (!cmdl)
		return ;
	curr = cmdl;
	while (curr->next)
	{
		flag = 0;
		pipe(fildes);
		if (notbuiltin(curr) && !curr->path)
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
		close(fildes[READ_END]);
		curr = curr->next;
	}
	if (!ft_fork())
		last_cmd(curr, env, 1);
	wait_all();
}