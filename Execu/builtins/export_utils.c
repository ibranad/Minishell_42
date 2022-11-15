/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

char	*concat_value(char *key, int *index, char *assign)
{
	char	*concat;

	concat = NULL;
	*index += 2;
	concat = ft_strdup(get_env_var(g_shell.env, key));
	while (assign[*index])
		concat = charjoin(concat, assign[(*index)++]);
	return (concat);
}

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

char	**get_entry(char *assign)
{
	char	**entry;
	int		i;
	int		len;

	if (!assign)
		return (NULL);
	len = ft_strlen(assign);
	i = 0;
	entry = ft_calloc(2, sizeof(char *));
	while (assign[i] && assign[i] != '=' && assign[i] != '+')
		entry[0] = charjoin(entry[0], assign[i++]);
	if (!assign[i])
		return (entry);
	if (assign[i] == '=')
	{
		while (assign[++i])
			entry[1] = charjoin(entry[1], assign[i]);
		entry[1] = charjoin(entry[1], assign[i]);
	}
	else if (i && assign[i] == '+' && i + 2 < len && assign[i + 1] == '=')
		entry[1] = concat_value(entry[0], &i, assign);
	while (assign[i])
			entry[0] = charjoin(entry[0], assign[i++]);
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
			free(key);
			if (value)
			{
				free(curr->value);
				curr->value = value;
			}
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void	set_variable(char *key, char *value, t_envl **envl)
{
	if (export_invalid_key(key))
		export_notvalid_stderr(key, 1);
	else if (reset_variable(key, value, *envl))
		return ;
	else
		lstadd_back(envl, lstnew(key, value));
}
