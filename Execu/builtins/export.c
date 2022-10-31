/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 12:54:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
// TODO:
// * VERIFYIING THE KEY
//		** "-" not a valid identifier
//		** "=..." not a valid identifier
//		** ""
//  	** The name of a variable can contain only letters, numbers and underscore
// * FORMATTING THE KIES:
// 		**

// *CASES:
//		** export new_var = value --> [export: `=': not a valid identifier] (new_var and value are both exported)
//		** export new_var= value --> [nothing output] (new_var's exported with "" and value's exported with no value)
//		** export new_var =val --> [export: `=val': not a valid identifier] (new_var's exported with no value)
//		** export --new_var=value --> [export: --:invalid option] nothing is exported
// 
//		** I should check before if the new_var already exits in the env

void	disp_export(t_envl **envl)
{
	t_envl	*curr;

	curr = *envl;
	while (curr)
	{
		printf("declare -x %s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
}

int	envl_len(t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr->next)
		curr = curr->next;
	return (curr->idx);
}

void	reset_variable(char *key, char *value, t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			free(curr->value);
			curr->value = ft_strdup(value);		
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

void	set_variable(char *key, char *value, t_envl **envl, int len)
{
	if (is_set(key, *envl))
		reset_variable(key, value, *envl);
	else
		lstadd_back(envl, lstnew(key, value, ++len));
}
// *In case the key_val is NULL so there's no argument we just display the content of ENV
void	_export(char **entries, t_envl **envl)
{
	int		i;
	int		len;
	char	**entry;

	len = envl_len(*envl);
	i = 0;
	if (!*entries)
		disp_export(envl);
	else
	{
		while (entries[i])
		{
			entry = split(entries[i], '=');
			set_variable(entry[0], entry[1], envl, ++len);
			free(entries[i++]);
		}
	}
}
