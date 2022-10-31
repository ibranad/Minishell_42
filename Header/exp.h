/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:50:49 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 13:56:26 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXP_H
#define EXP_H

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

char *add_char_first(char *in, char c);
int 	unreq_meta_char(char *in);
char    *d_quote_sp(char *in);
void    struct_init(t_exp *s);
char    *expand_dq_sp(t_envl *envl, char *in);
int     unclosed_quote(char *in);
char	*ft_strdup(const char *s1);
void    dq_short(t_exp *s,char *in);
void    struct_fill_sp(t_exp_sp *p);
char    *get_until_dollar(char *in);
void    struct_fill_sp(t_exp_sp *p);
int 	get_until_s_quote(char *in);
char    *get_until_d_quote(char *in);
void    exp_else(t_exp *s, char *in);
void    exp_else_sp(t_exp *s, char *in);
void    sq_expanding(t_exp *s, char *in);
void    dq_expanding(t_envl *envl, t_exp *s, char *in);
void    dollar_expanding(t_envl *envl, t_exp *s, char *in);
void    dollar_only_case(t_exp *s, char *in);
int     check_unrequired_by_subject(char *in);
char    *get_until_char(char *in, char c, char d);
void    dollar_expanding_sp(t_envl *envl, t_exp_sp *p, char *in);
char    *expander(t_envl *envl, char *in);
void    dollar_expanding_if_short(t_exp *s, char *in);
void    dollar_expanding_else_short(t_envl *envl, t_exp *s, char *in);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*expand(char *cmd_line);
void    in_here_doc_handle(t_exp *s, char *in);
char	*get_env_var(t_envl *envl, char *key);
void dol_exp_sp_dig(t_exp_sp *p, char *in);
void dol_exp_sp_ispecial(t_exp_sp *p, char *in);
void dol_exp_sp_ispecalnum(t_exp_sp *p, char *in);

#endif