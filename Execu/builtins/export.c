/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	_export(char **entries, t_envl **envl)
{
	int		i;
	char	**entry;

	i = 0;
	if (!*entries)
		disp_export(envl);
	else
	{
		while (entries[i])
		{
			if (check_entry(entries[i], &i))
				continue ;
			entry = get_entry(entries[i]);
			set_variable(entry[0], entry[1], envl);
			free(entry);
			i++;
		}
	}
}
