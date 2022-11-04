/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/04 11:27:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	export_invalid_key(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (1);
	return (0);
}

int	not_valid_id(char *entry)
{
//  ** The name of a variable can contain only letters, numbers and underscore
	if (!*entry)
		return (1); 
	else if (*entry == '=' || *entry == '-')
		return (export_notvalid_stderr(entry));
	return (0);
}

int check_entry(char *entry, int *i)
{
	if (not_valid_id(entry)	&& ++(*i))
		return (1);
	return (0);
}

void	reset_variable(char *key, char *value, t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			curr->value = value;
			return ;
		}
		curr = curr->next;
	}
}

int	is_set(char *key, t_envl *envl)
{
	t_envl	*curr;
	
	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(key, curr->key))
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	set_variable(char *key, char *value, t_envl **envl)
{
	if (export_invalid_key(key))
		export_notvalid_stderr(key);
	else if (is_set(key, *envl))
		reset_variable(key, value, *envl);
	else
		lstadd_back(envl, lstnew(key, value));
}
