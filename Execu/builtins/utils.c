/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:05:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	int					sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		num = num * 10 + str[i] - '0';
		if (num > 9223372036854775807 && sign == -1)
			return (0);
		else if (num > 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return (num * sign);
}

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
		if (!write_to(cmd->out_fd))
			return ;
	if (cmd->builtin == _echo_)
		_echo(vector_len(cmd->args + 1), cmd->args + 1);
	else if (cmd->builtin == _cd_)
		change_dir(*(cmd->args + 1), &g_shell.env);
	else if (cmd->builtin == _pwd_)
		_pwd();
	else if (cmd->builtin == _export_)
		_export(cmd->args + 1, &g_shell.env);
	else if (cmd->builtin == _unset_)
		_unset(cmd->args + 1, &g_shell.env);
	else if (cmd->builtin == _env_)
		_env(cmd->args, g_shell.env);
	else if (cmd->builtin == _exit_)
		__exit(cmd->args);
	if (cmdline_type == PIPELINE)
		exit(0);
}
