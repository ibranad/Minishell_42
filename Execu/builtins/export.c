/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/29 09:33:57 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
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

// int	valid_key(char *key)
// {
// 	int	i;
// 	i = -1;
// 	if (key[0] == '=')
// 		return (0);
// 	while (key[++i])
// 		if (!is_digit(key[i]) && !is_alpha(key[i]) && key[i] != '_')
// 			return (0);
// 	return (1);
// }

void	disp_export(t_envl **envl)
{
	t_envl	*curr;

	curr = *envl;
	while (curr)
	{
		printf("[%i] declare -x %s=%s\n", curr->idx, curr->key, curr->value);
		curr = curr->next;
	}
}
int	env_leng(t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr->next)
		curr = curr->next;
	return (curr->idx);
}

// *In case the key_val is NULL so there's no argument we just display the content of ENV
void	_export(char **entries, t_envl **envl)
{
	int	i;
	int	l;
	
	l = env_leng(*envl);
	i = 0;
	if (!entries)
		disp_export(envl);
	else
	{
		while (entries[i])
		{
			lstadd_back(envl, lstnew(split(entries[i], '='), ++l));
			free(entries[i++]);
		}
		free(entries);
	}
}