/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:34:28 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
//* The OPENDIR function opens and returns a directory 
//* stream for reading the directory whose file name is dirname. 
//* The stream has type DIR *.
//* The READDIR returns a pointer to the next directory entry. It returns
//* NULL upon reaching the end of the directory or on error.
//chdir 
char	*pwd_util(t_envl **envl)
{
	char	*current_directory;
	char	*tmp;

	tmp = malloc(sizeof(char) * 250);
	current_directory = ft_strdup(getcwd(tmp, 250));
	free(tmp);
	if (!current_directory)
	{
		printf("%s\n", strerror(errno));
		return (ft_strjoin(get_env_var(*envl, "PWD"), "/."));
	}
	return (current_directory);
}

void	directory_changing(t_envl **envl, char *path)
{
	char	*oldpwd;

	oldpwd = ft_strdup(get_env_var(*envl, "PWD"));
	set_variable(ft_strdup("OLDPWD"), oldpwd, envl);
	chdir(path);
	set_variable(ft_strdup("PWD"), pwd_util(envl), envl);
}

void	change_dir(char *path, t_envl **envl)
{
	DIR	*dir;

	dir = opendir(path);
	if (path && !*path)
	{
		free(dir);
		return ;
	}
	else if (!dir)
	{
		printf("No such file or directory\n");
		set_builtins_exit_status(1);
	}
	else
	{
		directory_changing(envl, path);
		set_builtins_exit_status(0);
	}
	if (dir)
	{
		free(dir->__dd_buf);
		free(dir);
	}
}
