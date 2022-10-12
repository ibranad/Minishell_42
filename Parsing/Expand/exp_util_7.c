/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:51:42 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/12 18:35:18 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void    dollar_only_case(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    ptr = s->out;
    s->out = ft_strjoin(s->out, "$");
    s->g_i += 1;
    free(ptr);
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
