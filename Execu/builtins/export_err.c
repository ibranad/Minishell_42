/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:17:13 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	export_invalid_key(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isalpha(s[i]) && s[i] != '_')
			return (1);
	}
	return (0);
}

int	not_valid_id(char *entry)
{
	if (!*entry)
		return (1);
	else if (*entry == '=' || *entry == '+')
		return (export_notvalid_stderr(entry, 0));
	return (0);
}

int	check_entry(char *entry, int *i)
{
	if (not_valid_id(entry) && ++(*i))
		return (1);
	return (0);
}
