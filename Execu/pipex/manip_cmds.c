/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 15:09:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	run(t_cmdl *cmd,g_shell shell)
{
	if (cmd->builtin == _echo_)
		_echo(vector_len(cmd->args + 1), cmd->args + 1);
	else if (cmd->builtin == _cd_)
		change_dir(*(cmd->args + 1));
	else if (cmd->builtin == _pwd_)
		_pwd();
	else if (cmd->builtin == _export_)
		_export(cmd->args + 1, &shell.env);
	else if (cmd->builtin == _unset_)
		_unset(cmd->args + 1, &shell.env);
	else if (cmd->builtin == _env_)
		_env(shell.env);
	else if (cmd->builtin == _exit_)
		_exit(shell.status);
	else if (cmd->path)
	{
		if (execve(cmd->path, cmd->args, NULL) == -1)
			execve_fail();
	}
	// add syntax error checking	
}

void	first_cmd(int *fildes, t_cmdl *cmd, g_shell shell)
{
	read_from(cmd->in_fd);
	write_to_pipe(fildes);
	run(cmd, shell);
}

void	mid_cmd(int *fildes, t_cmdl *cmd, g_shell shell)
{
	write_to_pipe(fildes);
	run(cmd, shell);
}

void	last_cmd(t_cmdl *cmd, g_shell shell)
{
	write_to(cmd->out_fd);
	run(cmd, shell);
}

void	run_sole_cmd(t_cmdl *cmd, g_shell shell)
{
	if (!ft_fork())
	{
		read_from(cmd->in_fd);
		write_to(cmd->out_fd);
		run(cmd, shell);
	}
	wait_all(&shell.status);
}