/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:43:21 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/14 11:04:59 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/11/13 21:01:36 by ibnada           ###   ########.fr       */
>>>>>>> c3ce27e5a2aec428b8e7a5ec5c2ec6a35287c575
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	print_args(char **args)
{
	int	i;

	i = -1;
	if (!args)
		printf("args : NULL\n");
	else
	{
		printf("args : {");
		while (args[++i])
			printf("%s, ", args[i]);
		printf("%s", args[i]);
		printf("}\n");
	}
}

void	print_parsing_lst(t_cmdl *cmd)
{
	while (cmd)
	{
		printf("-------------------------------\n");
		printf("idx : %d\n", cmd->idx);
		printf("path : %s\n", cmd->path);
		print_args(cmd->args);
		printf("in fd : %d\n", cmd->in_fd);
		printf("out fd : %d\n", cmd->out_fd);
		printf("isbuiltin : %d\n", cmd->builtin);
		printf("-------------------------------\n");
		cmd = cmd->next;
	}
}

t_cmdl	*parser(void)
{
	t_parser	p;

	t_parser_init(&p);
	p.red_line = readline("Minishell $> ");
	if (p.red_line && p.red_line[0])
	{
		add_history(p.red_line);
		if (check_unrequired_by_subject(p.red_line) != 0)
			free(p.red_line);
		else
		{
			parser_short(&p);
			return (p.cmd_line);
		}
	}
	else if (!p.red_line)
		exit(g_shell.status);
<<<<<<< HEAD
	else
		free(p.red_line);
=======
>>>>>>> c3ce27e5a2aec428b8e7a5ec5c2ec6a35287c575
	return (NULL);
}
