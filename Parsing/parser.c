/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:43:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/21 16:10:28 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	print_args(char **args)
{
	int i;

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

void print_parsing_lst(t_cmdl *cmd)
{
    while(cmd)
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

t_cmdl	*parser(t_envl *envl)
{
	char		*red_line;
	t_toklist	*tokens;
	t_cmdl		*cmd_line;
	
	red_line = NULL;
	red_line = readline(CYAN "Minishell $> " WHITE);
	printf("\033[0m");
	if (red_line[0])
	{
		add_history(red_line);
		if (check_unrequired_by_subject(red_line) == -1)
			printf("Syntax error: Unclosed quote\n");
		else
		{
			red_line = expander(envl, red_line);
			tokens = lexer(red_line);
			cmd_line = parse_list(tokens->next, shell.env);
			return (cmd_line);
		}
	}
	free(red_line);
	return (NULL);
}