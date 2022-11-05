/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/05 16:59:18 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

void	free_cmdl_lst(t_cmdl **lst)
{
	t_cmdl *ptr;
	t_cmdl *ptr2;

	ptr = *lst;
	ptr2 = ptr;
	if (ptr)
	{
		while(ptr)
		{
			free_db_c(ptr2->args);
			free(ptr2);
			ptr = ptr->next;
			ptr2 = ptr;
		}
	}
}

int main(int ac, char **av, char **env)
{
	(void)ac; 
	(void)av;
	t_cmdl	*cmd_line;
	int 	fd;
	int		fd1;

	fd = dup(0);
	fd1 = dup(1);
	shell.env = set_env(env);
	while (1) 
	{
		handle_signals(before_readline_handle);
		cmd_line = parser();
		handle_signals(after_readline_handle);
		// print_parsing_lst(cmd_line);
		// exit(EXIT_SUCCESS);
		// continue; 
		execute(cmd_line, env);
		set_exit_status();
		dup2(fd, STDIN_FILENO);
		dup2(fd1, STDOUT_FILENO);
		free_cmdl_lst(&cmd_line);
	}
	return (0);
}
