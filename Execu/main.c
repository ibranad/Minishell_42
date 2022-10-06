/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:47:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/05 17:37:08 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO builtins :
// * pwd ✅
// * env ✅
// * cd ✅
// * exit 
// * echo  ✅
// * export ✅
// * unset ✅
/*
*/
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_shell	shell;
	shell.env = set_env(env);
	_echo(ac - 1, av + 1);
	return (0);	
}
