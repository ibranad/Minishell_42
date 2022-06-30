/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:01:47 by ibnada            #+#    #+#             */
/*   Updated: 2021/11/26 01:10:45 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)c)
			return (&string[i]);
		i++;
	}
	if (c == 0)
		return (&string[i]);
	return (0);
}
