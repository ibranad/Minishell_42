/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:47:05 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	ft_ispecial_char(char c)
{
	if (c == '`' || c == '#' || c == '&' || c == '*'
		|| c == '\\' || c == '[' || c == ']' || c == '{' || c == '}'
		|| c == ';' || c == '<' || c == '>' || c == '/' || c == '?'
		|| c == '!' || c == '(' || c == ')')
		return (1);
	else
		return (0);
}

int	multi_out(char *in)
{
	int	i;
	int	out_flag;

	i = 0;
	out_flag = 0;
	while (in[i])
	{
		if (out_flag == 3)
		{
			if (g_shell.prs_error == 0)
				g_shell.prs_error = 1;
			putstr_fd(strerror(errno), 2);
			putstr_fd("\n", 2);
			return (-1);
		}
		if (in[i] == '>')
			out_flag++;
		else if (in[i] != ' ' && in[i] != '\t' && in[i] != '>')
			out_flag = 0;
		i++;
	}
	return (out_flag);
}

int	multi_in(char *in)
{
	int	i;
	int	in_flag;

	i = 0;
	in_flag = 0;
	while (in[i])
	{
		if (in_flag == 3)
		{
			error_printing();
			return (-1);
		}
		if (in[i] == '<')
			in_flag++;
		else if (in[i] != ' ' && in[i] != '\t' && in[i] != '<')
			in_flag = 0;
		i++;
	}
	return (in_flag);
}

int	space_between_in(char *in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		if (in[i] == '<')
		{
			while (in[i + 1] == ' ' || in[i + 1] == '\t')
			{
				i++;
				if (in[i + 1] == '<')
				{
					if (g_shell.prs_error == 0)
						g_shell.prs_error = 1;
					error_printing();
					return (-1);
				}
			}
		}
		i++;
	}
	return (0);
}

int	space_between_out(char *in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		if (in[i] == '>')
		{
			while (in[i + 1] == ' ' || in[i + 1] == '\t')
			{
				i++;
				if (in[i + 1] == '>')
				{
					error_printing();
					return (-1);
				}
			}
		}
		i++;
	}
	return (0);
}
