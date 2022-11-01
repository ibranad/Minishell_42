/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 15:55:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	check_path(t_envl *envl)
{
	get_paths(envl);
}

int	stderr_path_unset(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": No such file or directory\n", 2);
	return (_unset_path_);
}

int	stderr_cmd_not_found(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": command not found\n", 2);
	return (_command_not_found_);
}

int	command_not_found(t_cmdl *command)
{
	if (command->path)
		return (0);
	else
		return (1);
}

int	command_validity(t_cmdl *command)
{
	if (isbuiltin(command))
		return (_builtin_);
	else if (shell.paths_existence == UNEXISTING)
		return (stderr_path_unset(command->args[0]));
	else if (command_not_found(command))
		return (stderr_cmd_not_found(command->args[0]));
	return (0);
}