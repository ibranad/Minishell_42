/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:09:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 16:28:21 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

t_envl	*lstnew(char *key, char *value, int idx)
{
	t_envl	*lst;

	lst = malloc(sizeof(t_envl));
	if (!lst)
		malloc_fail();
	lst->idx = idx;
	lst->key = key;
	if (!value)
		lst->value = ft_strdup("");
	else
		lst->value = value;
	// free(entry);
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