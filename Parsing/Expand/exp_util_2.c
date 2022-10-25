/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:23:01 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/25 10:13:14 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void    dollar_expanding(t_envl *envl, t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    if (ft_isdigit(in[s->g_i + 1]))
        dollar_expanding_if_short(s, in);
    else
        dollar_expanding_else_short(envl, s, in);
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

void dollar_expanding_else_short(t_envl *envl, t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    ptr = s->out;
    s->expa = get_until_dollar(&in[s->g_i + 1]);
    s->out = ft_strjoin(s->out, get_env_var(envl, s->expa));
    free(ptr);
    s->g_i += ft_strlen(s->expa) + 1;
    free(s->expa);
}

void dq_expanding(t_envl *envl, t_exp *s, char *in)
{
    //This sub_function is used for norm purpose
    char *ptr;
    char *ptr2;

    ptr = NULL;
    s->g_i++;
    ptr = s->out;
    s->expa = get_until_d_quote(&in[s->g_i]);
    ptr2 = expand_dq_sp(envl, s->expa);
    ptr2 = char_at_start_end(ptr2 , '\"');
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
    s->not_out = char_at_start_end(s->not_out , '\'');
    s->out = ft_strjoin(s->out, s->not_out);
    free(ptr);
    s->g_i += ft_strlen(s->not_out) + 1;
    free(s->not_out);
}
