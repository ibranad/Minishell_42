/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:16:57 by ibnada            #+#    #+#             */
/*   Updated: 2021/11/26 01:47:04 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	int		size_sub_str;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	size_sub_str = s_len - start + 1;
	size_sub_str = min (size_sub_str, len + 1);
	sub = malloc (sizeof(char) * size_sub_str);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size_sub_str);
	return (sub);
}
