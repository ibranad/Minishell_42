/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/20 09:48:51 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	first_cmd(int *fildes, t_cmdl *cmd, t_envl *envl)
{
	(void)envl;
	read_from(cmd->in_fd);
	write_to_pipe(fildes);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		execve_fail();
}

void	mid_cmd(int *fildes, t_cmdl *cmd, t_envl *envl)
{
	(void)envl;
	write_to_pipe(fildes);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		execve_fail();
}

void	last_cmd(t_cmdl *cmd, t_envl *envl)
{
	(void)envl;
	write_to(cmd->out_fd);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		execve_fail();
}

void	run_sole_cmd(t_cmdl *cmd, t_envl *envl)
{
	(void)envl;
	read_from(cmd->in_fd);
	write_to(cmd->out_fd);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		execve_fail();
}