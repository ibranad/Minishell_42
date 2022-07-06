/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:44:07 by ibnada            #+#    #+#             */
/*   Updated: 2021/11/21 13:54:41 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*tcs1;
	const unsigned char	*tcs2;

	tcs1 = (const unsigned char *)s1;
	tcs2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tcs1[i] != tcs2[i])
			return (tcs1[i] - tcs2[i]);
		i++;
	}
	return (0);
}
