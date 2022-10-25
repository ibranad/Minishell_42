/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 09:27:44 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	run(t_cmdl *cmd, g_shell shell, char **env)
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
		__exit(shell);
	else if (cmd->path)
	{
		if (execve(cmd->path, cmd->args, env) == -1)
			execve_fail();
	}
	else
	{
		
		putstr_fd(cmd->args[0], 2);
		putstr_fd(": command not found\n", 2);
	}
}

void	first_cmd(int *fildes, t_cmdl *cmd, g_shell shell, char **env)
{
	read_from(cmd->in_fd);
	write_to_pipe(fildes);
	run(cmd, shell, env);
}

void	mid_cmd(int *fildes, t_cmdl *cmd, g_shell shell, char **env)
{
	write_to_pipe(fildes);
	run(cmd, shell, env);
}

void	last_cmd(t_cmdl *cmd, g_shell shell, char **env)
{
	write_to(cmd->out_fd);
	run(cmd, shell, env);
}

void	run_sole_cmd(t_cmdl *cmd, g_shell shell, char **env)
{
	if (!ft_fork())
	{
		read_from(cmd->in_fd);
		write_to(cmd->out_fd);
		run(cmd, shell, env);
	}
	wait_all(&shell.status);
}