/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/02 21:53:06 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/11/03 10:20:28 by obouizga         ###   ########.fr       */
>>>>>>> 64a6320438c5481074e9067c6815ad9ef3a8607b
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minishell.h"

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
	}  
	return (0);
}
