/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/24 08:42:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	__exit(g_shell shell)
{
	(void)shell;
	printf("EXITIIIING!!!\n");
	exit(EXIT_SUCCESS);
}