/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/28 15:07:12 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

char	*path_unset(char *cmd)
{
	printf("minishell %s: No such file or directory\n", cmd);
	return (NULL);
}

void	_err_cmd_not_found(char *command)
{
	putstr_fd(command, 2);
	putstr_fd(": command not found\n", 2);
	exit(EXIT_FAILURE);
}