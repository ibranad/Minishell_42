/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:59:52 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/06 11:22:39 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
#define EXP_H

# include "../minishell.h"

int		env_pass(char *str);
int		pd_alloc(char *str);
int		find_char(char *str, char c);
int		if_last_is(char *str, char c);
int		dollar_number(char *str, char c);
int		is_in_env(char *str, char **env);
char	*str_rep(char *str);
char	*env_var(char *str);
char	*space_add(char *str);
char    *double_quote(char *str);
char    *single_quote(char *str);
char	*t_strjoin(char *s1, char *s2);
char	*char_remove(char *str, char c);
char	*add_char_end(char *str, char c);
char	*expand_it(char *str,char **env);
char	*replace_it(char *str, char **env);
char	*expand_extra(char *str, char **env);
char	**char_rep(char **str, char old, char new);
void	print_2d_arr(char **arr);

#endif
