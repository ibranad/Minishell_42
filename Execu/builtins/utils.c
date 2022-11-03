/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:05:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/02 15:57:09 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	isbuiltin(t_cmdl *cmd)
{
	if (cmd->builtin)
		return (1);
	return (0);
}

int	notbuiltin(t_cmdl *cmd)
{
	if (!isbuiltin(cmd))
		return (1);
	return (0);
}

void	run_builtin(t_cmdl *cmd, int cmdline_type)
{
	if (cmdline_type == SOLE)
		write_to(cmd->out_fd);
	if (cmd->builtin == _echo_)
		_echo(vector_len(cmd->args + 1), cmd->args + 1);
	else if (cmd->builtin == _cd_)
		change_dir(*(cmd->args + 1), &shell.env);
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
	if (cmdline_type == PIPELINE)
		__exit();
}