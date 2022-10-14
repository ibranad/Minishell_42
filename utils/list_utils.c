/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:09:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 15:47:00 by obouizga         ###   ########.fr       */
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

int	not_integer(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '-' && !ft_isdigit(s[i]))
		return (1);
	else if (s[i] == '-' && !s[i + 1])
		return (1);
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (1);
	return (0);
}