/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:02:49 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/25 19:41:54 by ibnada           ###   ########.fr       */
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