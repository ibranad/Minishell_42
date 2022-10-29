/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/29 16:09:54 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	ft_execve(t_cmdl *cmd, char **env)
{
	if (execve(cmd->path, cmd->args, env) == -1)
			execve_fail();
}

void	run(t_cmdl *cmd, char **env)
{
	// if (!cmd->is_exec)
	// 	return ;
		// exit(EXIT_FAILURE);
	if (cmd->builtin != -1)
		write_to(cmd->out_fd);
	if (cmd->builtin == _echo_)
		_echo(vector_len(cmd->args + 1), cmd->args + 1);
	else if (cmd->builtin == _cd_)
		change_dir(*(cmd->args + 1), shell.env);
	else if (cmd->builtin == _pwd_)
		_pwd();
	else if (cmd->builtin == _export_)
		_export(cmd->args + 1, &shell.env);
	else if (cmd->builtin == _unset_)
		_unset(cmd->args + 1, &shell.env);
	else if (cmd->builtin == _env_)
		_env(shell.env);
	else if (cmd->builtin == _exit_)
		__exit();
	else if (cmd->path)
		ft_execve(cmd, env);
	else
	{
		printf("foo foo\n");	
		_err_cmd_not_found(cmd->args[0]);
	}
}

void	first_cmd(int *fildes, t_cmdl *cmd, char **env)
{
	read_from(cmd->in_fd);
	write_to_pipe(fildes);
	run(cmd, env);
}

void	mid_cmd(int *fildes, t_cmdl *cmd, char **env)
{
	write_to_pipe(fildes);
	run(cmd, env);
}

void	last_cmd(t_cmdl *cmd, char **env)
{
	write_to(cmd->out_fd);
	run(cmd, env);
}

void	run_sole_cmd(t_cmdl *cmd, char **env)
{
	if (!ft_fork())
	{
		read_from(cmd->in_fd);
		write_to(cmd->out_fd);
		run(cmd, env);
	}
	if (cmd->in_fd)
		close(cmd->in_fd);
	if (cmd->out_fd != 1)
		close(cmd->out_fd);
	wait_all();
}