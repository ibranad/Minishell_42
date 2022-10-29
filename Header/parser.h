/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/29 19:04:48 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRS_LST
#define PRS_LST

typedef struct prs_lst_st
{
    int         i;
    int         size;
    int         apnd_flag;
    int         red_in_flag;
    int         red_out_flag;
    int         here_doc_flag;
    int         first_word;
    int         cmd_c;
    char        **paths;
    t_cmdl      *lst;
    t_cmdl      *tmp_2;
    t_toklist   *tmp;
    
}       t_prs_lst;

int     is_builtin(char *str);
int     cmd_count(t_toklist *tmp);
int     toklist_size_2alloc(t_toklist *tok_list);
int     cmd_case(t_prs_lst *p);
int     args_case(t_prs_lst *p);
int     ft_ispecial_char(char c);
int     here_doc_flag(t_prs_lst *p);
int     here_doc_word(t_prs_lst *p);
int     input_flag_case(t_prs_lst *p);
int     input_word_case(t_prs_lst *p);
int     output_flag_case(t_prs_lst *p);
int     output_word_case(t_prs_lst *p);
int     apnd_flag_case(t_prs_lst *p);
int     apnd_word_case(t_prs_lst *p);
int     pipe_case(t_prs_lst *p);
int     command_arg_case(t_prs_lst *p);
int     heredoc_case(t_prs_lst *p);
int     red_in_case(t_prs_lst *p);
int     red_out_case(t_prs_lst *p);
int     apnd_case(t_prs_lst *p);
char    *char_at_start_end(char *in , char c);
void    lst_init(t_cmdl **lst);
void    print_parsing_lst(t_cmdl *in);
void    dollar_white_space(t_exp *s, char *in);
void    ft_lstadd_back(t_cmdl **alst, t_cmdl *new);
void    t_prs_lst_init(t_prs_lst *p, t_toklist *tok_lst, t_envl *envl);
t_cmdl  *ft_lstlast(t_cmdl *lst);
t_cmdl  *ft_lstadd_new(int content);
t_cmdl  *create_parse_lst(int size);
t_cmdl  *ft_lstadd_new(int content);
t_cmdl  *parse_list(t_toklist *tok_lst, t_envl *envl);

#endif