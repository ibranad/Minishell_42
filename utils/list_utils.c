/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:09:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/15 18:42:32 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

t_envl	*lstnew(char **entry, int idx)
{
	t_envl	*lst;

	lst = malloc(sizeof(t_envl));
	if (!lst)
		malloc_fail();
	lst->idx = idx;
	lst->key = entry[0];
	if (!entry[1])
		lst->value = ft_strdup("\"\"");
	else
		lst->value = entry[1];
	free(entry);
	lst->next = NULL;
	return (lst);
}

void	lstadd_back(t_envl **lst, t_envl *new)
{
	t_envl	*current;

	if (new)
	{
		if (*lst)
		{
			current = *lst;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*lst = new;
	}
}

void	free_env(t_envl *envl)
{
	t_envl	*curr;
	t_envl	*keep;

	curr = envl;
	while (curr)
	{
		keep = curr->next;
		free(curr->key);
		free(curr->value);
		
		// free(curr);
		curr = keep;
	}
}
