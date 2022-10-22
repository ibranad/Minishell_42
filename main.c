/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/22 10:47:50 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmdl	*cmd_line;

	shell.env = set_env(env);
	while (1)
	{
		handle_signals();
		cmd_line = parser(shell.env);
		print_parsing_lst(cmd_line);
		execute(cmd_line, shell);
	}
	return (0);
}
