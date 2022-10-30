/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 10:30:28 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

char	*path_unset(char *cmd)
{
	putstr_fd("minishell", 2);
	putstr_fd(cmd, 2);
	putstr_fd(": No such file or directory\n", 2);
	return (NULL);
}

void	_err_cmd_not_found(char *command)
{
	putstr_fd("Minishell: ", 2);
	putstr_fd(command, 2);
	putstr_fd(": command not found\n", 2);
	// exit(EXIT_FAILURE);
}