/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:50:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 16:11:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	uq_init(t_uq *p)
{
	p->i = 0;
	p->s = 0;
	p->d = 0;
	p->d_flag = 0;
	p->s_flag = 0;
}

void	dollar_expanding_sp(t_envl *envl, t_exp_sp *p, char *in)
{
	char	*ptr;

	ptr = NULL;
	if (ft_isdigit(in[p->i_g + 1]))
		dol_exp_sp_dig(p, in);
	else if (ft_ispecial_char(in[p->i_g + 1]))
		dol_exp_sp_ispecial(p, in);
	else if (!ft_ispecial_char(in[p->i_g + 1])
		&& !ft_isalnum(in[p->i_g + 1]) && in[p->i_g + 1] != '_')
		dol_exp_sp_ispecalnum(p, in);
	else
	{
		ptr = p->out;
		p->expa = get_until_dollar(&in[p->i_g + 1]);
		p->out = ft_strjoin(p->out, get_env_var(envl, p->expa));
		free(ptr);
		p->i_g += ft_strlen(p->expa) + 1;
		free(p->expa);
	}
}

void	unclosed_quote_short(t_uq *s, char *in)
{
	while (in[s->i])
	{
		if (in[s->i] == '\"' && s->s_flag == 0)
		{
			s->d++;
			if (s->d_flag == 0)
				s->d_flag = 1;
			else
				s->d_flag = 0;
		}
		if (in[s->i] == '\'' && s->d_flag == 0)
		{
			s->s++;
			if (s->s_flag == 0)
				s->s_flag = 1;
			else
				s->s_flag = 0;
		}
		s->i++;
	}
}

int	unclosed_quote(char *in)
{
	t_uq	s;

	uq_init(&s);
	if (!in)
		return (-1);
	unclosed_quote_short(&s, in);
	if ((s.d % 2) == 0 && (s.s % 2) == 0)
		return (0);
	else
	{
		if (g_shell.prs_error == 0)
			g_shell.prs_error = 1;
		putstr_fd("Minishell: Syntax error unclosed quote\n", 2);
		set_builtins_exit_status(258);
		return (1);
	}
}
