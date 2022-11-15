/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/15 21:02:21 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct prs_lst_st
{
	int			i;
	int			size;
	int			in_flag;
	int			out_flag;
	int			apnd_flag;
	int			red_in_flag;
	int			red_out_flag;
	int			here_doc_flag;
	int			first_word;
	int			cmd_c;
	int			prs_error;
	char		**paths;
	t_cmdl		*lst;
	t_cmdl		*tmp_2;
	t_toklist	*tmp;
}	t_prs_lst;

typedef struct hdoc_st
{
	char	*line;
	int		pip[2];
	int		e;
	int		lim_l;
}	t_hdoc;

typedef struct parser
{
	char		*red_line;
	char		*out;
	t_toklist	*tokens;
	t_cmdl		*cmd_line;
	int			error_code;
}	t_parser;

int		cmd_case(t_prs_lst *p);
int		get_builtin(char *str);
int		args_case(t_prs_lst *p);
int		apnd_case(t_prs_lst *p);
int		sym_only(t_toklist *tk);
int		pipe_case(t_prs_lst *p);
int		ft_ispecial_char(char c);
int		cmd_count(t_toklist *tmp);
int		red_in_case(t_prs_lst *p);
int		parser_short(t_parser *p);
int		space_between_in(char *in);
int		heredoc_case(t_prs_lst *p);
int		red_out_case(t_prs_lst *p);
int		here_doc_word(t_prs_lst *p);
int		here_doc_flag(t_prs_lst *p);
int		space_between_out(char *in);
int		apnd_flag_case(t_prs_lst *p);
int		apnd_word_case(t_prs_lst *p);
int		input_flag_case(t_prs_lst *p);
int		input_word_case(t_prs_lst *p);
int		output_word_case(t_prs_lst *p);
int		command_arg_case(t_prs_lst *p);
int		output_flag_case(t_prs_lst *p);
int		toklist_size_2alloc(t_toklist *tok_list);
char	*char_at_start_end(char *in, char c);
void	error_printing(void);
void	lst_init(t_cmdl **lst);
void	pipe_init(t_prs_lst *p);
void	t_parser_init(t_parser *p);
void	print_parsing_lst(t_cmdl *in);
void	dollar_white_space(t_exp *s, char *in);
void	ft_lstadd_back(t_cmdl **alst, t_cmdl *new);
void	t_prs_lst_init(t_prs_lst *p, t_toklist *tok_lst, t_envl *envl);
t_cmdl	*ft_lstlast(t_cmdl *lst);
t_cmdl	*ft_lstadd_new(int content);
t_cmdl	*create_parse_lst(int size);
t_cmdl	*ft_lstadd_new(int content);
t_cmdl	*parse_list(t_toklist *tok_lst, t_envl *envl);
void	move_to_pipe(t_prs_lst *p);
int		gettingcounter(int current_token);

#endif
