/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:36 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/08 16:12:32 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	dol_exp_sp_dig(t_exp_sp *p, char *in)
{
	char	*ptr;

	ptr = NULL;
	p->i_g++;
	if (in[p->i_g] == '0')
	{
		ptr = p->out;
		p->out = ft_strjoin(p->out, "Minishell");
		free(ptr);
	}
	ptr = p->out;
	p->expa = get_until_dollar(&in[p->i_g + 1]);
	p->out = ft_strjoin(p->out, p->expa);
	free(ptr);
	p->i_g += ft_strlen(p->expa) + 1;
	free(p->expa);
}

void	dol_exp_sp_ispecial(t_exp_sp *p, char *in)
{
	char	*ptr;

	ptr = NULL;
	ptr = p->out;
	p->expa = get_until_dollar(&in[p->i_g + 1]);
	p->out = ft_strjoin(p->out, p->expa);
	free(ptr);
	p->i_g += ft_strlen(p->expa) + 1;
	free(p->expa);
}

void	dol_exp_sp_ispecalnum(t_exp_sp *p, char *in)
{
	char	*ptr;
	char	*str;

	ptr = NULL;
	ptr = p->out;
	p->expa = get_until_dollar(&in[p->i_g + 1]);
	str = add_char_first(p->expa, '$');
	p->out = ft_strjoin(p->out, str);
	free(ptr);
	free(str);
	p->i_g += ft_strlen(p->expa) + 1;
	free(p->expa);
}
