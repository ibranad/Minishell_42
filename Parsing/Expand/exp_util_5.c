/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:02:48 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/11 18:34:46 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void struct_fill_sp(t_exp_sp *p)
{
    p->out = NULL;
    p->not_expa = NULL;
    p->expa = NULL;
    p->i_g = 0;
}

char *expand_dq_sp(char *in)
{
    t_exp_sp p;
    char *ptr;
    
    ptr = NULL;
    struct_fill_sp(&p);
    while (in[p.i_g])
    {
        if (in[p.i_g] == '$')
            dollar_expanding_sp(&p,in);
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

void dollar_expanding_sp(t_exp_sp *p, char *in)
{
    char *ptr;

    ptr = NULL;
    if (ft_isdigit(in[p->i_g + 1]))
    {
        p->i_g++;
        if (in[p->i_g] == '0')
        {
            ptr = p->out;
            p->out = ft_strjoin(p->out, "Minishell");
            free(ptr);
        }
        ptr = p->out;
        p->expa = get_until_dollar(&in[p->i_g + 1]);
        p->out = ft_strjoin(p->out, p->expa);
        free(ptr);
        p->i_g += ft_strlen(p->expa);
        free(p->expa);
    }
    else
    {
        ptr = p->out;
        p->expa = get_until_dollar(&in[p->i_g + 1]);
        p->out = ft_strjoin(p->out, getenv(p->expa));
        free(ptr);
        p->i_g += ft_strlen(p->expa) + 1;
        free(p->expa);
    }
}

int unclosed_quote(char *in)
{
    //This fonction checks for unclosed quotes (sucess(l9at unclosed quote) return 1, failure(mal9athach) return 0)
    //in case of empty string this fonction returns -1
    int i;
    int s;//single quote
    int d;//double quote

    if (!in)
        return (-1);
    i = 0;
    s = 0;
    d = 0;
    while (in[i])
    {
        if (in[i] == '\"')
            d++;
        else if (in[i] == '\'')
            s++;
        i++;
    }
    if ((d % 2) == 0 && (s % 2) == 0)
        return (0);
    else
        return (1);
}
