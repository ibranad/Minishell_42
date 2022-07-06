/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tri_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:30:56 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/05 18:31:12 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

char    *expand_it(char *str,char **env)
{
    char    *old;
    char    *new;
    char    *line;
    int     i;
    int     j;
    int     size;

    i = 0;
    j = 0;
    old = env_var(str);
    new = replace_it(old, env);

    size = ((ft_strlen(str) - ft_strlen(old)) + ft_strlen(new));
    line = malloc(sizeof(char) * (size + 1));
    while (i < size)
    {
        if (str[i] == '$')
        {
            while(new[j])
            {
                line[i] = new[j];
                i++;
                j++;
            }
        }
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

