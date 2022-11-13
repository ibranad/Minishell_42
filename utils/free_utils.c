/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:52:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	free_db_c_start(char **strings, int start)
{
	int	i;

	i = start + 1;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (1);
}

int	free_db_c(char **strings)
{
	int	i;

	if (!strings)
		return (0);
	i = 0;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (1);
}

void	free_envl_n(t_envl *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	free_token_list(t_toklist *tokens)
{
	t_toklist	*curr;
	t_toklist	*keep;

	curr = tokens;
	while (curr)
	{
		keep = curr;
		if (curr->nature != _head)
			free(curr->lexeme);
		free(curr);
		curr = keep->next;
	}
}

void	free_cmdl_lst(t_cmdl **lst)
{
	t_cmdl	*ptr;
	t_cmdl	*ptr2;

	if (!*lst)
		return ;
	ptr = *lst;
	ptr2 = ptr;
	if (ptr)
	{
		while (ptr)
		{
			free(ptr2->path);
			free_db_c(ptr2->args);
			free(ptr2);
			ptr = ptr->next;
			ptr2 = ptr;
		}
	}
}
