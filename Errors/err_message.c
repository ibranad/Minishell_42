/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:59:46 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/05 15:08:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	export_notvalid_stderr(char *argument)
{
	putstr_fd("Minishell: export: `", 2);
	putstr_fd(argument, 2);
	putstr_fd("': not a valid identifier\n", 2);
	return (1);
}
