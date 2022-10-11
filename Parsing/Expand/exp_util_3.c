/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:23:01 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/11 17:56:51 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void dollar_expanding(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    if (ft_isdigit(in[s->g_i + 1]))
        {
            s->g_i++;
            ptr = s->out;
            if (in[s->g_i] == '0')
            {
                s->out = ft_strjoin(s->out, "Minishell");
                free(ptr);
            }
            ptr = s->out;
            s->expa = get_until_dollar(&in[s->g_i + 1]);
            s->out = ft_strjoin(s->out, s->expa);
            free(ptr);
            s->g_i += ft_strlen(s->expa) + 1;
            free(s->expa);
        }
        else
        {
            ptr = s->out;
            s->expa = get_until_dollar(&in[s->g_i + 1]);
            s->out = ft_strjoin(s->out, getenv(s->expa));
            free(ptr);
            s->g_i += ft_strlen(s->expa) + 1;
            free(s->expa);
        }
}

void dq_expanding(t_exp *s, char *in)
{
    //This sub_function is used for norm purpose
    char *ptr;
    char *ptr2;

    ptr = NULL;
    s->g_i++;
    ptr = s->out;
    s->expa = get_until_d_quote(&in[s->g_i]);
    ptr2 = expand_dq_sp(s->expa);
    s->out = ft_strjoin(s->out, ptr2);
    free(ptr);
    free(ptr2);
    s->g_i += ft_strlen(s->expa) + 1;
    free(s->expa);
}

void sq_expanding(t_exp *s, char *in)
{
    //This sub_function is used for norm purpose
    char *ptr;
    
    ptr = NULL;
    s->g_i++;
    ptr = s->out;
    s->not_out = get_until_s_quote(&in[s->g_i]);
    s->out = ft_strjoin(s->out, s->not_out);
    free(ptr);
    s->g_i += ft_strlen(s->not_out) + 1;
    free(s->not_out);
}

int ft_strlen(char const *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}