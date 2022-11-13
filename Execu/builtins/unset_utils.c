/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:02:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	del_one(t_envl *prev, t_envl *target, t_envl *next)
{
	prev->next = next;
	free_envl_n(target);
}

void	remove_node(t_envl *target, t_envl **envl, t_envl *prev)
{
	t_envl	*temp;

	temp = NULL;
	if (target == *envl)
	{
		temp = *envl;
		*envl = (*envl)->next;
		free_envl_n(temp);
	}
	else
		del_one(prev, target, target->next);
}
