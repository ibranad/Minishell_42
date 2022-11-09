/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:43:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/09 20:21:21 by ibnada           ###   ########.fr       */
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

int sym_only(t_toklist *tk)
{
	int i;
	t_toklist *tmp;

	i = 0;
	tmp = tk;
	// if (tmp->nature == _pipe && tmp->index == 1)
	// {
	// 	putstr_fd("Syntax Error near unexpected token ",2);
	// 	putstr_fd("`newline'\n",2);
	// 	return (-1);
	// }
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 1 && ((tk->nature == _pipe) 
	|| (tk->nature == _chev) || (tk->nature == _ichev)))
	{
		error_printing();
		return (-1);
	}
	return(0);
}

t_cmdl	*parser(void)
{
	char		*red_line;
	char		*out;
	t_toklist	*tokens;
	t_cmdl		*cmd_line;
	
	red_line = NULL;
	red_line = readline(CYAN"Minishell $> "RESET_COLOR);
	if (red_line && red_line[0])
	{
		add_history(red_line);
		if (check_unrequired_by_subject(red_line) != 0)
			free(red_line);
		else
		{
			out = red_line;
			red_line = expander(shell.env, out);
			printf("Expanding [%s]\n", red_line);
			tokens = lexer(red_line);
			free(out);
			free(red_line);
			if (sym_only(tokens->next) == -1)
				return (NULL);
			cmd_line = parse_list(tokens->next, shell.env);
			print_parsing_lst(cmd_line);
			free_token_list(tokens);
			return (cmd_line);
		}
	}
	else if (!red_line)
		exit(0);
	return (NULL);
}