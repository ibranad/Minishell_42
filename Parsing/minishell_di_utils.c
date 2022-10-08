/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:42 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/08 16:08:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_lstadd_front(t_cmdl **lst, t_cmdl *new)
{
	if (!(*lst))
		(*lst) = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

t_cmdl  *ft_lstnew(void)
{
	t_cmdl	*new;

	new = malloc (sizeof(t_cmdl));
	new->next = NULL;
	return (new);
}

int ft_lstsize(t_cmdl *lst)
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

int find_heredoc(char	**arr, int	len)
{
	int	i;
	int	j;
	int	fd;
	
	i = 0;
	j = 0;
	while (arr[i])
	{
		if (ft_strncmp(arr[i], "<", 1) == 0)
		{
			i++;
			if (ft_strncmp(arr[i], "<", 1) == 0)
			{
				i++;
				printf("lol\n");
				fd = ft_heredoc(arr[i]);
				if (i < len)
					continue ;
				else
					break ;
			}
		}
		i++;
	}
	return (fd);
}
