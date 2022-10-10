/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 20:25:09 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

char *expand_dq_sp(char *in)
{
    char *out = NULL;
    char *not_expa = NULL;
    char *expa = NULL;
    int i;

    i = 0;
    while (in[i])
    {
        if (in[i] == '$')
        {
            if (isdigit(in[i + 1]))
            {
                i++;
                if (in[i] == '0')
                    out = ft_strjoin(out, "Minishell");
                expa = get_until_dollar(&in[i + 1]);
                out = ft_strjoin(out, expa);
                i += ft_strlen(expa);
            }
            else
            {
                expa = get_until_dollar(&in[i + 1]);
                out = ft_strjoin(out, getenv(expa));
                i += ft_strlen(expa) + 1;
            }
        }
        else
        {
            not_expa = get_until_dollar(&in[i]);
            out = ft_strjoin(out, not_expa);
            i += ft_strlen(not_expa);
        }
    }
    return (out);
}

char *expand_var_in_str(char *in)
{
    //expand env variable in any given string
    //for example input:echo $USER$USER -> output:ibnadaibnada
    t_exp s;

    struct_init(&s);
    while (in[s.g_i])
    {
        if (in[s.g_i] == '$')
            dollar_expanding(&s,in);
        else if (in[s.g_i] == '\"')
            dq_expanding(&s, in);
        else if (in[s.g_i] == '\'')
            sq_expanding(&s, in);
        else
        {
            s.not_out = get_until_dollar(&in[s.g_i]);
            s.out = ft_strjoin(s.out, s.not_out);
            free(s.not_out);
            s.g_i += ft_strlen(s.not_out);
        }
    }
    return (s.out);
}


int main(int ac, char *av[], char *env[])
{
    int i;
    char *str;
    
    while(1)
    {
        str = readline("Prompt-> ");
        printf("->%s\n", expand_var_in_str(str));
    }
}