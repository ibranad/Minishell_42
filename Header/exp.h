/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:50:49 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/08 16:00:33 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
# define EXP_H

# define SQ '\''
# define DQ '\"'
# define DL '$'

typedef struct exp_s
{
	int		g_i;
	char	*out;
	char	*not_out;
	char	*expa;
}	t_exp;

typedef struct uq
{
	int	i;
	int	s;
	int	d;
	int	d_flag;
	int	s_flag;
}	t_uq;

typedef struct exp_sp
{
	char	*out;
	char	*not_expa;
	char	*expa;
	int		i_g;
}	t_exp_sp;

int		multi_in(char *in);
int		multi_out(char *in);
int		unclosed_quote(char *in);
int		unreq_meta_char(char *in);
int		get_until_s_quote(char *in);
int		check_unrequired_by_subject(char *in);
char	*d_quote_sp(char *in);
char	*expand(char *cmd_line);
char	*ft_strdup(const char *s1);
char	*get_until_dollar(char *in);
char	*get_until_d_quote(char *in);
char	*add_char_first(char *in, char c);
char	*expander(t_envl *envl, char *in);
char	*expand_dq_sp(t_envl *envl, char *in);
char	*get_env_var(t_envl *envl, char *key);
char	*get_until_char(char *in, char c, char d);
void	struct_init(t_exp *s);
void	dq_short(t_exp *s, char *in);
void	struct_fill_sp(t_exp_sp *p);
void	struct_fill_sp(t_exp_sp *p);
void	exp_else(t_exp *s, char *in);
void	exp_else_sp(t_exp *s, char *in);
void	sq_expanding(t_exp *s, char *in);
void	dollar_only_case(t_exp *s, char *in);
void	dol_exp_sp_dig(t_exp_sp *p, char *in);
void	in_here_doc_handle(t_exp *s, char *in);
void	dol_exp_sp_ispecial(t_exp_sp *p, char *in);
void	dol_exp_sp_ispecalnum(t_exp_sp *p, char *in);
void	dollar_expanding_if_short(t_exp *s, char *in);
void	dq_expanding(t_envl *envl, t_exp *s, char *in);
void	expand_dq_sp_else_short(t_exp_sp *p, char *in);
void	dollar_expanding(t_envl *envl, t_exp *s, char *in);
void	dollar_expanding_sp(t_envl *envl, t_exp_sp *p, char *in);
void	dollar_expanding_else_short(t_envl *envl, t_exp *s, char *in);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
