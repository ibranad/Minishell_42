/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 20:01:37 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	path_unset(char *cmd)
{
	printf("%s : No such file or directory\n", cmd);
	exit(EXIT_FAILURE);
}

void	_err_cmd_not_found(char *command)
{
	putstr_fd(command, 2);
	putstr_fd(": command not found\n", 2);
}