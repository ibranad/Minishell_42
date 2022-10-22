/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/22 10:39:26 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/10/22 10:47:50 by obouizga         ###   ########.fr       */
>>>>>>> 78fd5b63ed9287fce0b816b79eb022d2f939bbc5
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
		// add_history(cmd_line);
		print_parsing_lst(cmd_line);
<<<<<<< HEAD
		//execute(cmd_line, shell);
		// handle_signals();
=======
		execute(cmd_line, shell);
>>>>>>> 78fd5b63ed9287fce0b816b79eb022d2f939bbc5
	}
	return (0);
}
