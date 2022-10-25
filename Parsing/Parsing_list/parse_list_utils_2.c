/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:51:03 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/25 09:56:40 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../Header/minishell.h"

char *char_at_start_end(char *in , char c)
{
    int i;
    int j;
    char *out;

    i = 0;
    j = 1;
    out = malloc(sizeof(char) * ft_strlen(in) + 3);
    out[0] = c;
    while(in[i])
    {
        out[j] = in[i];
        i++;
        j++;
    }
    out[j++] = c;
    out [j] = '\0';
    return (out);
}