/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:09:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

t_envl	*lstnew(char *key, char *value)
{
	t_envl	*lst;

	lst = malloc(sizeof(t_envl));
	if (!lst)
		malloc_fail();
	lst->key = key;
	lst->value = value;
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
		curr = keep;
	}
}

int	cmdline_size(t_cmdl *lst)
{
	t_cmdl	*current;
	int		i;

	if (!lst)
		return (0);
	current = lst;
	i = 1;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}
