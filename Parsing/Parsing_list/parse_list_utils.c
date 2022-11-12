/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:46:41 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/12 20:58:21 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

t_cmdl	*ft_lstadd_new(int content)
{
	t_cmdl	*new;

	new = malloc(sizeof(t_cmdl));
	new->idx = content;
	new->next = 0;
	return (new);
}

t_cmdl	*ft_lstlast(t_cmdl *lst)
{
	t_cmdl	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_cmdl **alst, t_cmdl *new)
{
	t_cmdl	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

t_cmdl	*create_parse_lst(int size)
{
	int		i;
	t_cmdl	*new;
	t_cmdl	*lst;

	i = 0;
	lst = 0;
	while (i < size)
	{
		new = ft_lstadd_new(i);
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}
int gettingCounter(int current_token)
{
	if (current_token == _pipe)
		return (-1);
	if (current_token == _word)
		return (0);
	if (current_token == _chev || current_token == _ichev)
		return (2);
	if (current_token == _dchev || current_token == _dichev)
		return (2);
	return (-1);
}
int	cmd_count(t_toklist *tmp)
{
	int			i;
	int		counter = 0;
	t_toklist	*p;

	i = 0;
	p = tmp;
	while (p != 0 && p->nature != _pipe)
	{
		counter += gettingCounter(p->nature);
		i++;
		p = p->next;
	}
	return (i - counter);
}
