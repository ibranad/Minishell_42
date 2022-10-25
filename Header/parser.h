/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/25 18:48:18 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRS_LST
#define PRS_LST

int         is_builtin(char *str);
void        lst_init(t_cmdl **lst);
t_cmdl      *ft_lstlast(t_cmdl *lst);
int         cmd_count(t_toklist *tmp);
t_cmdl      *ft_lstadd_new(int content);
t_cmdl      *create_parse_lst(int size);
t_cmdl      *ft_lstadd_new(int content);
void        print_parsing_lst(t_cmdl *in);
char        *char_at_start_end(char *in , char c);
void        dollar_white_space(t_exp *s, char *in);
int         toklist_size_2alloc(t_toklist *tok_list);
void        ft_lstadd_back(t_cmdl **alst, t_cmdl *new);
t_cmdl      *parse_list(t_toklist *tok_lst, t_envl *envl);

#endif