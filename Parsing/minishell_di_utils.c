/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:42 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/06 15:44:20 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_lstadd_front(t_cont **lst, t_cont *new)
{
	if (!(*lst))
		(*lst) = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

t_cont  *ft_lstnew(int content)
{
	t_cont	*new;

	new = malloc (sizeof(t_cont));
	new->in_fd = content;
	new->next = NULL;
	return (new);
}

int ft_lstsize(t_cont *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}