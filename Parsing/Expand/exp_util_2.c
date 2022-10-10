/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:15:57 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 20:17:19 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
    if (s1)
	    while (s1[i] != '\0')
	    {
	    	join[j++] = s1[i++];
	    }
	i = 0;
    if (s2)
	    while (s2[i] != '\0')
	    {
	    	join[j++] = s2[i++];    
	    }
	join[j] = '\0';
	return (join);
}

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
		return (strdup(""));
	size_sub_str = s_len - start + 1;
	size_sub_str = min (size_sub_str, len + 1);
	sub = malloc (sizeof(char) * size_sub_str);
	if (!sub)
		return (NULL);
	strlcpy(sub, s + start, size_sub_str);
	return (sub);
}

char *d_quote_sp(char *in)
{
    //double_quote_special_case
    //this function handle this special case "'$HOME'"
    int i;
    int j;
    int l;
    char *out;

    i = 0;
    j = 0;
    l = strlen(in);
    out = malloc(sizeof(char) * 3);
    out[j++] = '\'';
    while(in[i])
    {
        out[j] = in[i];
        i++;
        j++;
    }
    out[j++] = '\'';
    out[j] = '\0';
    return (out);
}