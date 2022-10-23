/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 15:10:09 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	pipex(t_cmdl *cmdl, g_shell shell)
{
	int		fildes[2];
	t_cmdl	*curr;

	if (!cmdl)
		return ;
	curr = cmdl;
	while (curr->next)
	{
		pipe(fildes);
		if (!ft_fork())
		{
			if (!curr->idx)
				first_cmd(fildes, curr, shell);
			else
				mid_cmd(fildes, curr, shell);
		}
		else
			read_from_pipe(fildes);
		curr = curr->next;
	}
	if (!ft_fork())
		last_cmd(curr, shell);
	wait_all(&shell.status);
}