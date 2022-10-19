/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/19 14:37:04 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRS_LST
#define PRS_LST

int         cmd_count(t_toklist *tmp);
int         is_builtin(char *str);
int         toklist_size_2alloc(t_toklist *tok_list);
void        lst_init(t_cmdl **lst);
void        ft_lstadd_back(t_cmdl **alst, t_cmdl *new);
void        print_parsing_lst(t_cmdl *in);
t_cmdl      *parse_list(t_toklist *tok_lst, t_envl *envl);
t_cmdl      *ft_lstlast(t_cmdl *lst);
t_cmdl      *ft_lstadd_new(int content);
t_cmdl      *create_parse_lst(int size);
t_cmdl      *ft_lstadd_new(int content);


#endif