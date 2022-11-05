/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:02:48 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/05 14:45:44 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void struct_fill_sp(t_exp_sp *p)
{
    p->out = NULL;
    p->not_expa = NULL;
    p->expa = NULL;
    p->i_g = 0;
}

void    dollar_only_case_sp(t_exp_sp *s, char *in)
{
    (void)in;
    char *ptr;
    printf("hello1\n");
    ptr = NULL;
    ptr = s->out;
    s->out = ft_strjoin(s->out, "$");
    s->i_g += 1;
    free(ptr);
}

void    dollar_white_space_sp(t_exp_sp *s, char *in)
{
    char *ptr;
    char *ptr2;

    ptr = NULL;
    ptr = s->out;
    s->out = ft_strjoin(ptr, "$");
    s->not_expa = get_until_dollar(&in[s->i_g]);
    ptr2 = s->out;
    s->out = ft_strjoin(ptr, s->not_expa);
    free(ptr);
    free(ptr2);
    s->i_g += ft_strlen(s->not_expa);
    free(s->not_expa);
}

void    dollar_ques_mark_sp(t_exp_sp *s, char *in)
{
    (void)in;
    char *ptr;
    char *ptr2;

    ptr = NULL;
    ptr2 = s->out;
    ptr = ft_itoa(shell.status);
    s->i_g++;
    s->out = ft_strjoin(s->out, ptr);
    s->i_g++;
    free(ptr);
    free(ptr2);
}

char *expand_dq_sp(t_envl *envl, char *in)
{
    t_exp_sp p;
    char *ptr;
    
    ptr = NULL;
    struct_fill_sp(&p);
    while (in[p.i_g])
    {
        if (in[p.i_g] == '$' && !in[p.i_g + 1])
            dollar_only_case_sp(&p, in);
        else if (in[p.i_g] == '$' && in[p.i_g + 1] == '?')
            dollar_ques_mark_sp(&p, in);
        else if (in[p.i_g] == '$' && (in[p.i_g + 1] == ' ' || in[p.i_g + 1] == '\t'))
            dollar_white_space_sp(&p, in);
        else if (in[p.i_g] == '$' && (in[p.i_g + 1] == '_' || ft_isalnum(in[p.i_g + 1])))
            dollar_expanding_sp(envl, &p, in);
        else
        {
            ptr = p.out;
            p.not_expa = get_until_dollar(&in[p.i_g]);
            p.out = ft_strjoin(p.out, p.not_expa);
            free(ptr);
            p.i_g += ft_strlen(p.not_expa);
            free(p.not_expa);
        }
    }
    return (p.out);
}

