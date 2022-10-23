/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:52:43 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 15:30:17 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

// *The will-be-unset variables should be stored inside a 2d array
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

void	_unset(char **to_unset, t_envl **envl)
{
	t_envl	*curr;
	t_envl	*prev;
	int		i;

	i = 0;
	prev = *envl;
	curr = *envl;
	while (to_unset[i])
	{
		curr = *envl;
		while (curr)
		{
			if (!ft_strcmp(to_unset[i], curr->key))
				remove_node(curr, envl, prev);
			prev = curr;
			curr = curr->next;
		}
		i++;
	}
	// free_db_c(to_unset);
}
