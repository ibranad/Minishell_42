/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/06 16:09:28 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	disp_export(t_envl **envl)
{
	t_envl	*curr;

	curr = *envl;
	while (curr)
	{
		printf("declare -x %s", curr->key);
		if (curr->value)
			printf("=\"%s\"", curr->value);
		printf("\n");
		curr = curr->next;
	}
}

char	**get_entry(char *assignment)
{
	char	**entry;
	int 	i;

	i = 0;
	entry = ft_calloc(3, sizeof(char *));
	if (!entry)
		malloc_fail();
	while (assignment[i] && assignment[i] != '=')
		entry[0] = charjoin(entry[0], assignment[i++]);
	if (assignment[i] == '=')
	{
		while (assignment[++i])
			entry[1] = charjoin(entry[1], assignment[i]);
		entry[1] = charjoin(entry[1], assignment[i]);
	}
	return (entry);
}

int	reset_variable(char *key, char *value, t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			if (value)
				curr->value = value;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void	set_variable(char *key, char *value, t_envl **envl)
{
	if (export_invalid_key(key))
		export_notvalid_stderr(key);
	else if (reset_variable(key, value, *envl))
		return ;
	else
		lstadd_back(envl, lstnew(key, value));
}
