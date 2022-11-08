/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:02:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/08 11:23:31 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	del_one(t_envl *prev, t_envl *node, t_envl *next)
{
	prev->next = next;
	free_envl_n(node);
}

t_envl	*penult_node(t_envl **envl)
{
	t_envl *curr;

	curr = *envl;
	while (curr->next->next)
		curr = curr->next;
	return (curr);
}

void	remove_node(t_envl *curr, t_envl **envl, t_envl *prev)
{
	t_envl	*temp;
	t_envl	*penult;

	penult = penult_node(envl);
	temp = NULL;
	if (curr->idx == 0)
	{
		temp = *envl;
		*envl = (*envl)->next;
		(*envl)->idx = 0;
		free_envl_n(temp);
	}
	else if (curr == penult->next)
	{
		free_envl_n(penult->next);
		penult->next = NULL;
	}
	else
		del_one(prev, curr, curr->next);
}