/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:50:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/02 20:47:44 by ibnada           ###   ########.fr       */
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
    int d_flag;
    int s_flag;

    if (!in)
        return (-1);
    i = 0;
    s = 0;
    d = 0;
    d_flag = 0;
    s_flag = 0;
    while (in[i])
    {
        if (in[i] == '\"' && s_flag == 0)
        {
            d++;
            if(d_flag == 0)
              d_flag = 1;
            else
              d_flag = 0;
        }
        if (in[i] == '\'' && d_flag == 0)
        {
            s++; 
            if (s_flag == 0)
                s_flag = 1;
            else
                s_flag = 0;
        }
        i++;
    }
    if ((d % 2) == 0 && (s % 2) == 0)
        return (0);
    else
    {
        printf("Syntax error : Unclosed quote\n");
        return (1);
    }
}

void dollar_expanding_sp(t_envl *envl, t_exp_sp *p, char *in)
{
    char *ptr;

    ptr = NULL;
    
    if (ft_isdigit(in[p->i_g + 1]))
        dol_exp_sp_dig(p, in);
    else if (ft_ispecial_char(in[p->i_g + 1]))
        dol_exp_sp_ispecial(p, in);
    else if (!ft_ispecial_char(in[p->i_g + 1]) && !ft_isalnum(in[p->i_g + 1]))
        dol_exp_sp_ispecalnum(p, in);
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
    // printf("hello1\n");
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
    printf("hello2\n");
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
    printf("hello3\n");
    ptr = NULL;
    ptr = p->out;
    p->expa = get_until_dollar(&in[p->i_g + 1]);
    char *str = add_char_first(p->expa, '$');
    p->out = ft_strjoin(p->out, str);
    free(ptr);
    p->i_g += ft_strlen(p->expa) + 1;
    free(p->expa);
}