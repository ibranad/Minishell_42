/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:34:28 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 12:58:56 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
//* The OPENDIR function opens and returns a directory 
//* stream for reading the directory whose file name is dirname. 
//* The stream has type DIR *.
//* The READDIR returns a pointer to the next directory entry. It returns
//* NULL upon reaching the end of the directory or on error.
//chdir
//closedir
// *l9walb: cd .. segfaults when you delete 
void	change_dir(char *path, t_envl **envl)
{
	DIR	*dir;

	// entry = split("OLD_PWD ")
	dir = opendir(path);
	if (path && !*path)
		return ;
	else if (!path || *path == '~')
		chdir(get_env_var(*envl, "HOME"));
	else if (!dir)
		printf("%s\n", strerror(errno));
	else
	{
		set_variable("OLDPWD", get_env_var(*envl, "PWD"), envl, -42);
		chdir(path);
	}
}