/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:51:03 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 18:07:20 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

char	*char_at_start_end(char *in, char c)
{
	int		i;
	int		j;
	char	*out;

	if (!in)
		return (NULL);
	i = 0;
	j = 1;
	out = malloc(sizeof(char) * ft_strlen(in) + 3);
	out[0] = c;
	while (in[i])
	{
		out[j] = in[i];
		i++;
		j++;
	}
	out[j++] = c;
	out [j] = '\0';
	return (out);
}

void	error_printing(void)
{
	if (g_shell.prs_error == 0)
	{
		g_shell.prs_error = 1;
		putstr_fd("Minishell: Syntax error near", 2);
		putstr_fd(" unexpected token\n", 2);
		set_builtins_exit_status(258);
	}
}

void	t_prs_lst_init(t_prs_lst *p, t_toklist *tok_lst, t_envl *envl)
{
	p->i = 0;
	p->size = toklist_size_2alloc(tok_lst);
	p->apnd_flag = 0;
	p->red_in_flag = 0;
	p->out_flag = 0;
	p->red_out_flag = 0;
	p->here_doc_flag = 0;
	p->first_word = 0;
	p->cmd_c = 0;
	p->paths = get_paths(envl);
	p->lst = create_parse_lst(p->size);
	lst_init(&p->lst);
	p->tmp_2 = p->lst;
	p->tmp = tok_lst;
	p->in_flag = -1;
}

int	toklist_size_2alloc(t_toklist *tok_list)
{
	int			i;
	t_toklist	*tmp;

	i = 0;
	tmp = tok_list;
	while (tmp)
	{
		if (tmp->nature == _pipe)
			i++;
		tmp = tmp->next;
	}
	return (i + 1);
}

void	lst_init(t_cmdl **lst)
{
	t_cmdl	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->args = 0;
		tmp->builtin = 0;
		tmp->idx = i;
		tmp->in_fd = 0;
		tmp->out_fd = 1;
		tmp->path = 0;
		i++;
		tmp = tmp->next;
	}
}
