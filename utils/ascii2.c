/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:50:44 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	str_tolower(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '$')
		return ;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}
