/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:23:01 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/12 17:41:57 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void dollar_expanding(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    if (ft_isdigit(in[s->g_i + 1]))
        dollar_expanding_if_short(s, in);
    else
        dollar_expanding_else_short(s, in);
}

void dollar_expanding_if_short(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    s->g_i++;
    ptr = s->out;
    if (in[s->g_i] == '0')
    {
        s->out = ft_strjoin(s->out, "Minishell");
        free(ptr);
        ptr = s->out;
    }
    s->expa = get_until_dollar(&in[s->g_i + 1]);
    s->out = ft_strjoin(s->out, s->expa);
    free(ptr);
    s->g_i += ft_strlen(s->expa) + 1;
    free(s->expa);
}

void dollar_expanding_else_short(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    ptr = s->out;
    s->expa = get_until_dollar(&in[s->g_i + 1]);
    s->out = ft_strjoin(s->out, getenv(s->expa));
    free(ptr);
    s->g_i += ft_strlen(s->expa) + 1;
    free(s->expa);
}