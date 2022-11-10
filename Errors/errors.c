/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 13:21:46 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"
int	only_slash(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{	
		if (string[i] != '/')
			return (0);
		i++;
	}
	return (1);
}


int	command_not_found(t_cmdl *command)
{
	
	if (command->path &&\
	 (!ft_strcmp(command->path, ".") || !ft_strcmp(command->path, "..")))
		return (1);
	else if (command->path && only_slash(command->path))
		return (2);
	else if (command->path)
		return (0);
	return (1);
}

int	stderr_cmd_is_dir(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": is a directory\n", 2);
	return (_command_not_found_);
}

int	command_validity(t_cmdl *command)
{
	if (isbuiltin(command))
		return (_builtin_);
	else if (shell.paths_existence == UNEXISTING)
		return (stderr_path_unset(command->args[0]));
	else if (command_not_found(command) == 1)
		return (stderr_cmd_not_found(command->args[0]));
	else if (command_not_found(command) == 2)
		return (stderr_cmd_is_dir(command->path));
	return (0);
}