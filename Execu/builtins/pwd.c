/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:57:15 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/12 12:57:16 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	_pwd(void)
{
	char	*s;

	s = malloc(250);
	if (!getcwd(s, 250))
	{
		printf("%s\n", get_env_var(shell.env, "PWD"));
		free(s);
		return ;
	}
	printf("%s\n", getcwd(s, 250));
	free(s);
}
