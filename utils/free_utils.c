/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:52:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/04 14:26:44 by ibnada           ###   ########.fr       */
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