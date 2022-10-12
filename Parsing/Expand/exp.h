/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:34 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/12 18:35:08 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
#define EXP_H

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include <ctype.h>

#define SQ '\'' // Single Quote
#define DQ '\"' // Double Quote
#define DL '$'  // Dollar

typedef struct exp_s
{
    char *out;
    char *not_out;
    char *expa;
    int g_i;
}   t_exp;

typedef struct exp_sp
{
    char *out;
    char *not_expa;
    char *expa;
    int i_g;
}   t_exp_sp;

int     ft_isalnum(int c);
int	    min(int a, int b);
int     ft_isdigit(int c);
char    *d_quote_sp(char *in);
void    struct_init(t_exp *s);
char    *expand_dq_sp(char *in);
int     unclosed_quote(char *in);
int     ft_strlen(char const *str);
char	*ft_strdup(const char *s1);
void    struct_fill_sp(t_exp_sp *p);
char    *get_until_dollar(char *in);
void    struct_fill_sp(t_exp_sp *p);
char    *get_until_s_quote(char *in);
char    *get_until_d_quote(char *in);
void    exp_else(t_exp *s, char *in);
void    sq_expanding(t_exp *s, char *in);
void    dq_expanding(t_exp *s, char *in);
void    dollar_expanding(t_exp *s, char *in);
void    dollar_only_case(t_exp *s, char *in);
void    dollar_expanding_sp(t_exp_sp *p, char *in);
void    dollar_expanding_sp(t_exp_sp *p, char *in);
char	*ft_strjoin(char const *s1, char const *s2);
void    dollar_expanding_if_short(t_exp *s, char *in);
void    dollar_expanding_else_short(t_exp *s, char *in);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif