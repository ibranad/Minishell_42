/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:52:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 15:41:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	free_db_c(char **strings)
{
	char	**k;

	k = strings;
	while (*strings)
		free(*(strings++));
	free(k);
}

void	free_envl_n(t_envl *node)
{
	free(node->key);
	free(node->value);
	free(node);
}