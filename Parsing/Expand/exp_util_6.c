/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:50:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/31 20:47:43 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

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
    {
        putstr_fd("Syntax error : Unclosed quote\n", 2);
        return (1);
    }
}

void dollar_expanding_sp(t_envl *envl, t_exp_sp *p, char *in)
{
    char *ptr;

    ptr = NULL;
    
    if (ft_isdigit(in[p->i_g + 1]))
        dol_exp_sp_dig(p, in);
    if (ft_ispecial_char(in[p->i_g + 1]))
    {
        dol_exp_sp_ispecial(p, in);
        // ptr = p->out;
        // p->expa = get_until_dollar(&in[p->i_g + 1]);
        // p->out = ft_strjoin(p->out, p->expa);
        // free(ptr);
        // p->i_g += ft_strlen(p->expa) + 1;
        // free(p->expa);
    }
    else if (!ft_ispecial_char(in[p->i_g + 1]) && !ft_isalnum(in[p->i_g + 1]))
    {
        dol_exp_sp_ispecalnum(p, in);
            //ptr = p->out;
            // p->expa = get_until_dollar(&in[p->i_g + 1]);
            // char *str = add_char_first(p->expa, '$');
            // p->out = ft_strjoin(p->out, str);
            // free(ptr);
            // p->i_g += ft_strlen(p->expa) + 1;
            // free(p->expa);
    }
    else
    {
        ptr = p->out;
        p->expa = get_until_dollar(&in[p->i_g + 1]);//+1
        p->out = ft_strjoin(p->out, get_env_var(envl, p->expa));
        free(ptr);
        p->i_g += ft_strlen(p->expa) + 1;//+1
        free(p->expa);
    }
}

void dol_exp_sp_dig(t_exp_sp *p, char *in)
{
    char *ptr;

    ptr = NULL;
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
    p->i_g += ft_strlen(p->expa) + 1;
    free(p->expa);
}

void dol_exp_sp_ispecial(t_exp_sp *p, char *in)
{
    char *ptr;

    ptr = NULL;
    ptr = p->out;
    p->expa = get_until_dollar(&in[p->i_g + 1]);
    p->out = ft_strjoin(p->out, p->expa);
    free(ptr);
    p->i_g += ft_strlen(p->expa) + 1;
    free(p->expa);
}

void dol_exp_sp_ispecalnum(t_exp_sp *p, char *in)
{
    char *ptr;
    
    ptr = NULL;
    ptr = p->out;
    p->expa = get_until_dollar(&in[p->i_g + 1]);
    char *str = add_char_first(p->expa, '$');
    p->out = ft_strjoin(p->out, str);
    free(ptr);
    p->i_g += ft_strlen(p->expa) + 1;
    free(p->expa);
}