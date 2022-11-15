/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:58:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

static size_t	get_words_n(char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	alloc_place_string(int *bords, size_t k, char **split, char *s)
{
	int	j;
	int	st;
	int	e;

	st = bords[0];
	e = bords[1];
	split[k] = malloc(sizeof(char) * (e - st + 2));
	if (!split[k])
		return (0);
	j = -1;
	while (++j <= e - st)
		split[k][j] = s[st + j];
	split[k][j] = '\0';
	return (1);
}

static char	**free_return_null(char **split, int k)
{
	while (k >= 0)
		free(split[k--]);
	free(split);
	return (NULL);
}

static char	**s_alloc(size_t words, char c, char *s)
{
	char	**split;
	int		i;
	size_t	k;
	int		bords[2];

	i = 0;
	k = 0;
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	while (k < words)
	{
		while (s[i] && s[i] == c)
			i++;
		bords[0] = i;
		while (s[i] && s[i] != c)
			i++;
		bords[1] = i - 1;
		if (!alloc_place_string(bords, k, split, s))
			split = free_return_null(split, k);
		k++;
	}
	split[k] = 0;
	return (split);
}

char	**split(char const *s, char c)
{
	size_t	words;
	char	**split;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	if (!str)
		return (NULL);
	words = get_words_n(str, c);
	split = s_alloc(words, c, str);
	if (!split)
		return (NULL);
	return (split);
}
