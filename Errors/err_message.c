/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:59:46 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/06 17:05:50 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	export_notvalid_stderr(char *argument)
{
	if (argument && *argument == '-')
	{
		putstr_fd("Minishell: export: ", 2);
		write(2, "-", 1);
		write(2, argument + 1, 1);
		putstr_fd(": invalid option\n", 2);	
	}
	else
	{
		putstr_fd("Minishell: export: `", 2);
		putstr_fd(argument, 2);
		putstr_fd("': not a valid identifier\n", 2);
	}
	return (1);
}
