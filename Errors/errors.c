/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 14:39:22 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	check_path(t_envl *envl)
{
	get_paths(envl);
}
void	stderr_path_unset(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": No such file or directory\n", 2);
}

void	stderr_cmd_not_found(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": command not found\n", 2);
	// exit(EXIT_FAILURE);
}

int	command_not_found(t_cmdl *command)
{
	return (command->path ? 0 : 1);
}

int	command_validity(t_cmdl *command)
{
	if (isbuiltin(command))
		return (_builtin_);
	else if (shell.paths_existence == UNEXISTING)
	{
		stderr_path_unset(command->args[0]);
		return (_unset_path_);
	}
	else if (command_not_found(command))
	{
		
		stderr_cmd_not_found(command->args[0]);
		return (_command_not_found_);
	}
	return (0);
}