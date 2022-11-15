/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/15 21:02:27 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	run(t_cmdl *cmd, int cmdline_type, char **env)
{
	signal(SIGQUIT, sigquit_child_handle);
	if (isbuiltin(cmd))
		run_builtin(cmd, cmdline_type);
	else
		ft_execve(cmd, env);
}

void	first_cmd(int *fildes, t_cmdl *cmd, int validity, char **env)
{
	if (cmd->in_fd < 0)
		exit(1);
	read_from(cmd->in_fd);
	if (cmd->out_fd < 0 && cmd->out_fd != -42)
		exit(1);
	if (cmd->out_fd == -42)
		write_to_pipe(fildes);
	else
		write_to(cmd->out_fd);
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ || \
			validity == _command_not_found_)
		exit(127);
	run(cmd, PIPELINE, env);
}

void	mid_cmd(int *fildes, t_cmdl *cmd, int validity, char **env)
{
	if (cmd->in_fd < 0 && cmd->in_fd != -42)
		exit(1);
	if (cmd->in_fd != -42)
		read_from(cmd->in_fd);
	if (cmd->out_fd < 0 && cmd->out_fd != -42)
		exit(1);
	if (cmd->out_fd == -42)
		write_to_pipe(fildes);
	else
		write_to(cmd->out_fd);
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ || \
			validity == _command_not_found_)
		exit(127);
	run(cmd, PIPELINE, env);
}

void	last_cmd(t_cmdl *cmd, int validity, char **env)
{
	if (cmd->in_fd < 0 && cmd->in_fd != -42)
		exit(1);
	if (cmd->in_fd != -42)
		read_from(cmd->in_fd);
	if (cmd->out_fd < 0)
		exit(1);
	write_to(cmd->out_fd);
	if (validity == _builtin_)
		run_builtin(cmd, PIPELINE);
	else if (validity == _unset_path_ || \
			validity == _command_not_found_)
		exit(127);
	run(cmd, PIPELINE, env);
}

void	run_sole_cmd(t_cmdl *cmd, char **env, int validity)
{
	if (validity == _builtin_)
		run_builtin(cmd, SOLE);
	else if (!ft_fork())
	{
		if (validity == _unset_path_ || \
			validity == _command_not_found_)
			exit(127);
<<<<<<< HEAD
		if (cmd->in_fd < 0 || cmd->out_fd < 0)
			exit(1);
=======
>>>>>>> c3ce27e5a2aec428b8e7a5ec5c2ec6a35287c575
		read_from(cmd->in_fd);
		write_to(cmd->out_fd);
		run(cmd, SOLE, env);
	}
	if (validity != _builtin_)
		wait_all();
	if (cmd->in_fd)
		close(cmd->in_fd);
}
