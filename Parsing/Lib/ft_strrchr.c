/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:40:55 by ibnada            #+#    #+#             */
/*   Updated: 2021/11/26 01:12:25 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*result;

	str = (char *)s;
	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			result = &str[i];
		i++;
	}
	if (c == 0)
		return (&str[i]);
	return (result);
}
