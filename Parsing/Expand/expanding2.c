/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 14:27:54 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>

#define SQ '\'' // Single Quote
#define DQ '\"' // Double Quote
#define DL '$'  // Dollar

int ft_strlen(char const *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
    if (s1)
	    while (s1[i] != '\0')
	    {
	    	join[j++] = s1[i++];
	    }
	i = 0;
    if (s2)
	    while (s2[i] != '\0')
	    {
	    	join[j++] = s2[i++];    
	    }
	join[j] = '\0';
	return (join);
}


int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	int		size_sub_str;

	if (!s)
		return (NULL);
	i = 0;
	s_len = strlen(s);
	if (start >= s_len)
		return (strdup(""));
	size_sub_str = s_len - start + 1;
	size_sub_str = min (size_sub_str, len + 1);
	sub = malloc (sizeof(char) * size_sub_str);
	if (!sub)
		return (NULL);
	strlcpy(sub, s + start, size_sub_str);
	return (sub);
}

char *get_until_dollar(char *in)
{
    int     i;
    char *out;

    i = 0;
    while(in[i])
    {
        if ((!isalnum(in[i])) && (in[i] != '_'))
        {
            if (!i)// if i = 0, like when the input is: $USER.$HOME
                i++;//ila mat incrementach substr radi ta5od (in, 0, 0) o rat returni empty string
            break;
        }
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

char *get_until_s_quote(char *in)
{
    int i;
    char *out;

    i = 0;
    while (in[i])
    {
        if(in[i] == '\'')
            break;
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

char *get_until_d_quote(char *in)
{
    int i;
    char *out;

    i = 0;
    while (in[i])
    {
        if (in[i] == '\"')
            break;
        i++;
    }
    out = ft_substr(in, 0, i);
    return (out);
}

char *d_quote_sp(char *in)
{
    //double_quote_special_case
    //this function handle this special case "'$HOME'"
    int i;
    int j;
    int l;
    char *out;

    i = 0;
    j = 0;
    l = strlen(in);
    out = malloc(sizeof(char) * 3);
    out[j++] = '\'';
    while(in[i])
    {
        out[j] = in[i];
        i++;
        j++;
    }
    out[j++] = '\'';
    out[j] = '\0';
    return (out);
}

char *expand_dq_sp(char *in)
{
    char *out = strdup("");
    char *not_expa = strdup("");
    char *expa = strdup("");
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
    char *out = strdup("");
    char *not_expa = strdup("");
    char *expa = strdup("");
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
        else if (in[i] == '\"')
        {
            i++;
            expa = get_until_d_quote(&in[i]);
            out = ft_strjoin(out, expand_dq_sp(expa));
            i += ft_strlen(expa) + 1;
        }
        else if (in[i] == '\'')
        {
            i++;
            not_expa = get_until_s_quote(&in[i]);
            out = ft_strjoin(out, not_expa);
            i += ft_strlen(not_expa) + 1;
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


// echo '"$USER"'
// echo "'$USER'"
// echo "'""$USER""'"
// echo "'$USER'"
// echo "'$USER'"