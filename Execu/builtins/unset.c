/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:52:43 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	_unset(char **to_unset, t_envl **envl)
{
	t_envl	*curr;
	t_envl	*prev;
	int		i;

	i = 0;
	curr = *envl;
	while (to_unset[i])
	{
		if (unset_invalid_key(to_unset[i], &i))
			continue ;
		prev = *envl;
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
}
