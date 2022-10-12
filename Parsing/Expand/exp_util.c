/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:26:35 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 20:17:50 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

char *get_until_dollar(char *in)
{
    int     i;
    char *out;

    i = 0;
    while(in[i])
    {
        if ((!ft_isalnum(in[i])) && (in[i] != '_'))
        {
            if (!i)// if i = 0, like when the input is: $USER.$HOME
                i++;//ila mat incrementach substr radi ta5od (in, 0, 0) o rat returni empty string
            break;
        }
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

char *get_until_s_quote(char *in)
{
    int i;
    char *out;

    i = 0;
    while (in[i])
    {
        if(in[i] == '\'')
            break;
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

char *get_until_d_quote(char *in)
{
    int i;
    char *out;

    i = 0;
    while (in[i])
    {
        if (in[i] == '\"')
            break;
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

void struct_init(t_exp *s)
{
    s->expa = NULL;
    s->not_out = NULL;
    s->out = NULL;
    s->g_i = 0;
}
