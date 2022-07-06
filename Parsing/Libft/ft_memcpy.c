/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:06:33 by ibnada            #+#    #+#             */
/*   Updated: 2021/11/21 13:59:06 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tcd;
	unsigned char	*tcs;

	i = 0;
	tcd = (unsigned char *)dest;
	tcs = (unsigned char *)src;
	if (tcs == NULL && tcd == NULL)
		return (NULL);
	if (tcs == tcd)
		return (dest);
	while (i < n)
	{
		tcd[i] = tcs[i];
		i++;
	}
	return (dest);
}
