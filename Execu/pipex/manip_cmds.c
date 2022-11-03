/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/03 08:56:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	run(t_cmdl *cmd, int cmdline_type, char **env)
{
	if (isbuiltin(cmd))
		run_builtin(cmd, cmdline_type);
	else
		ft_execve(cmd, env);
}

void	first_cmd(int *fildes, t_cmdl *cmd, int validity, char **env)
{
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ ||\
			 validity == _command_not_found_)
		exit(127);
	read_from(cmd->in_fd);
	write_to_pipe(fildes);
	run(cmd, PIPELINE, env);
}

void	mid_cmd(int *fildes, t_cmdl *cmd, int validity, char **env)
{
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ ||\
			 validity == _command_not_found_)
		exit(127);
	write_to_pipe(fildes);
	run(cmd, PIPELINE, env);
}

void	last_cmd(t_cmdl *cmd, int validity, char **env)
{
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ ||\
			 validity == _command_not_found_)
		exit(127);
	write_to(cmd->out_fd);
	run(cmd, PIPELINE, env);
}
	
void	run_sole_cmd(t_cmdl *cmd, char **env, int validity)
{
	if (validity == _builtin_)
		run_builtin(cmd, SOLE);
	else if (!ft_fork())
	{
		 if (validity == _unset_path_ ||\
			 validity == _command_not_found_)
		exit(127);
		read_from(cmd->in_fd);
		write_to(cmd->out_fd);
		run(cmd, SOLE, env);
	}
	wait_all();
}