/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:34:28 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 16:01:01 by obouizga         ###   ########.fr       */
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
char *pwd_util(void)
{
	char	*current_directory;
	char	*tmp;

	tmp = malloc(sizeof(char) * 250);
	current_directory = ft_strdup(getcwd(tmp, 250));
	free(tmp);
	return (current_directory);
}

void	directory_changing(t_envl **envl, char *path)
{
	set_variable("OLDPWD", get_env_var(*envl, "PWD"), envl);
	chdir(path);
	set_variable("PWD", pwd_util(), envl);
}

void	change_dir(char *path, t_envl **envl)
{
	DIR	*dir;

	dir = opendir(path);
	if (path && !*path)
		return ;
	else if (!path || *path == '~')
		directory_changing(envl, get_env_var(*envl, "HOME"));
	else if (!dir)
		printf("%s\n", strerror(errno));
	else
		directory_changing(envl, path);
}