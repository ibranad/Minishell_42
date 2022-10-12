/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:50:44 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/12 11:00:31 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c < 32 || c >= 127)
		return (0);
	else
		return (1);
}

int	ft_isblank(int c)
{
	if (c == 32 || c == 10 || c == 9)
		return (1);
	return (0);
}
