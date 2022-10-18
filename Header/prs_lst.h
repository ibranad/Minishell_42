/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/17 17:46:30 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRS_LST
#define PRS_LST

void        lst_init(t_cmdl **lst);
int         cmd_count(t_toklist *tmp);
void        ft_lstadd_back(t_cmdl **alst, t_cmdl *new);
void        parse_list(t_toklist *tok_lst, t_envl *envl);
t_cmdl      *ft_lstlast(t_cmdl *lst);
t_cmdl      *ft_lstadd_new(int content);
t_cmdl      *create_parse_lst(int size);
t_cmdl      *ft_lstadd_new(int content);
t_cmdl      *create_parse_lst(int size);

#endif