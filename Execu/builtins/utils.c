/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:05:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 20:11:26 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	isbuiltin(t_cmdl *cmd)
{
	if (cmd->builtin != - 1)
		return (1);
	return (0);
}

int	notbuiltin(t_cmdl *cmd)
{
	if (!isbuiltin(cmd))
		return (1);
	return (0);
}