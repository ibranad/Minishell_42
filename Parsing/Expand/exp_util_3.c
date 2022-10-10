/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:23:01 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 20:25:30 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void dollar_expanding(t_exp *s, char *in)
{
    if (isdigit(in[s->g_i + 1]))
        {
            s->g_i++;
            if (in[s->g_i] == '0')
                s->out = ft_strjoin(s->out, "Minishell");
            s->expa = get_until_dollar(&in[s->g_i + 1]);
            s->out = ft_strjoin(s->out, s->expa);
            free(s->expa);
            s->g_i += ft_strlen(s->expa);
        }
        else
        {
            s->expa = get_until_dollar(&in[s->g_i + 1]);
            s->out = ft_strjoin(s->out, getenv(s->expa));
            free(s->expa);
            s->g_i += ft_strlen(s->expa) + 1;
        }
}

void dq_expanding(t_exp *s, char *in)
{
    //This sub_function is used for norm purpose
    s->g_i++;
    s->expa = get_until_d_quote(&in[s->g_i]);
    s->out = ft_strjoin(s->out, expand_dq_sp(s->expa));
    free(s->expa);
    s->g_i += ft_strlen(s->expa) + 1;
}

void sq_expanding(t_exp *s, char *in)
{
    //This sub_function is used for norm purpose
    s->g_i++;
    s->not_out = get_until_s_quote(&in[s->g_i]);
    s->out = ft_strjoin(s->out, s->not_out);
    free(s->not_out);
    s->g_i += ft_strlen(s->not_out) + 1;
}