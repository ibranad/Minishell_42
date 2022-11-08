/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:02:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/08 15:41:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	del_one(t_envl *prev, t_envl *target, t_envl *next)
{
	prev->next = next;
	free_envl_n(target);
}

t_envl	*penult_node(t_envl **envl)
{
	t_envl *curr;

	curr = *envl;
	while (curr->next->next)
		curr = curr->next;
	return (curr);
}

// void	remove_node(t_envl *target, t_envl **envl, t_envl *prev)
// {
// 	t_envl	*temp;
// 	t_envl	*penult;

// 	penult = penult_node(envl);
// 	temp = NULL;
// 	if (target->idx == 0)
// 	{
// 		temp = *envl;
// 		*envl = (*envl)->next;
// 		(*envl)->idx = 0;
// 		free_envl_n(temp);
// 	}
// 	else if (!target->next)
// 	{
// 		free_envl_n(penult->next);
// 		penult->next = NULL;
// 	}
// 	else
// 		del_one(prev, target, target->next);
// }

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