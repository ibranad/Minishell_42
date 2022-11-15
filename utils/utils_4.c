/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:02:49 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	nbrlen(int nbr)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		neg = 1;
		nbr = nbr * -1;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + neg);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			sign;
	int			len;
	char		*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = nbrlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
		nbr = n;
	if (nbr < 0)
		nbr = nbr * -1;
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

int	not_integer(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
		return (1);
	else if (s[i] == '-' && !s[i + 1])
		return (1);
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	mem = malloc(count * size);
	if (!mem)
		malloc_fail();
	i = 0;
	while (i < count * size)
	{
		*(mem + i) = 0;
		i++;
	}
	return (mem);
}
