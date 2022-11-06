/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:47:05 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/06 16:50:53 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int ft_ispecial_char(char c)
{
    if (c == '`' || c == '#' || c == '&' || c == '*' 
    || c == '\\' || c == '['|| c == ']' || c == '{' || c == '}'
    || c == ';' || c == '<' || c == '>' || c == '/' || c == '?'
    || c == '!' || c == '(' || c == ')')
        return(1);
    else
        return(0);
}

int multi_out(char *in)
{
    int i;
    int out_flag;
    
    i = 0;
    out_flag = 0;
    while (in[i])
    {
        if (out_flag == 3)
        {
            putstr_fd(strerror(errno), 2);
            putstr_fd("\n", 2);
            return(-1);
        }
        if (in[i] == '>')
            out_flag++;
        else if (in[i] != ' ' && in[i] != '\t' && in[i] != '>')
            out_flag = 0;
        i++;
    }
    return (out_flag);
}

int multi_in(char *in)
{
    int i;
    int in_flag;
    
    i = 0;
    in_flag = 0;
    while (in[i])
    {
        if (in_flag == 3)
        {
            putstr_fd("Syntax error near unexpected token `newline\'", 2);
            putstr_fd("\n", 2);
            return(-1);
        }
        if (in[i] == '<')
            in_flag++;
        else if (in[i] != ' ' && in[i] != '\t' && in[i] != '<')
            in_flag = 0;
        i++;
    }
    return (in_flag);
}

int check_unrequired_by_subject(char *in)
{
    if (unclosed_quote(in) == 1)
        return(-1);
    if (multi_in(in) < 0)
        return(-2);
    if (multi_out(in) < 0)
        return(-3);
    return (0);
}

void    dollar_only_case(t_exp *s, char *in)
{
    (void)in;
    char *ptr;

    ptr = NULL;
    ptr = s->out;
    s->out = ft_strjoin(s->out, "$");
    s->g_i += 1;
    free(ptr);
}

char *add_char_first(char *in, char c)
{
    int i;
    int j;
    char *out;
    
    i = 0;
    j = 0;
    out = malloc(sizeof(char) * strlen(in) + 2);
    out[j++] = c;
    while (in[i])
    {
        out[j] = in[i];
        i++;
        j++;
    }
    out[j] = '\0';
    return(out);
}

void exp_else(t_exp *s, char *in)
{
    char *ptr;

    ptr = NULL;
    ptr = s->out;
    s->not_out = get_until_dollar(&in[s->g_i]);
    s->out = ft_strjoin(ptr, s->not_out);
    free(ptr);
    s->g_i += ft_strlen(s->not_out);
    free(s->not_out);
}