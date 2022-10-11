/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/11 19:15:43 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

// char *expand_dq_sp(char *in)
// {
//     char *out = NULL;
//     char *not_expa = NULL;
//     char *expa = NULL;
//     int i;

//     i = 0;
//     while (in[i])
//     {
//         if (in[i] == '$')
//         {
//             if (ft_isdigit(in[i + 1]))
//             {
//                 i++;
//                 if (in[i] == '0')
//                     out = ft_strjoin(out, "Minishell");
//                 expa = get_until_dollar(&in[i + 1]);
//                 out = ft_strjoin(out, expa);
//                 i += ft_strlen(expa);
//             }
//             else
//             {
//                 expa = get_until_dollar(&in[i + 1]);
//                 out = ft_strjoin(out, getenv(expa));
//                 i += ft_strlen(expa) + 1;
//             }
//         }
//         else
//         {
//             not_expa = get_until_dollar(&in[i]);
//             out = ft_strjoin(out, not_expa);
//             i += ft_strlen(not_expa);
//         }
//     }
//     return (out);
// }

char *expand_var_in_str(char *in)
{
    //expand env variable in any given string
    //for example input:echo $USER$USER -> output:ibnadaibnada
    t_exp s;
    char *ptr;

    ptr = NULL;
    struct_init(&s);
    while (in[s.g_i])
    {
        if (in[s.g_i] == '$' && !in[s.g_i + 1])
        {
            s.out = ft_strjoin(s.out, "$");
            s.g_i += 1;
        }
        if (in[s.g_i] == '$')
            dollar_expanding(&s,in);
        else if (in[s.g_i] == '\"')
            dq_expanding(&s, in);
        else if (in[s.g_i] == '\'')
            sq_expanding(&s, in);
        else
        {
            ptr = s.out;
            s.not_out = get_until_dollar(&in[s.g_i]);
            s.out = ft_strjoin(ptr, s.not_out);
            free(ptr);
            s.g_i += ft_strlen(s.not_out);
            free(s.not_out);
        }
    }
    return (s.out);
}

int check_unrequired_by_subject(char *in)
{
    if (unclosed_quote(in) == 1)
        return(-1);//error code -1: unclosed quote
    if ()
}

int main(int ac, char *av[], char *env[])
{
    int i;
    char *str;
    
    while(1)
    {
        str = readline("Prompt-> ");
        char *ptr = expand_var_in_str(str);
        printf("->%s\n", ptr);
        free(ptr);
        free(str);
    }
}