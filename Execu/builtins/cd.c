/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:34:28 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 15:36:56 by obouizga         ###   ########.fr       */
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
/*
char	*purify(char *s)
{
	return (s);
}

void change_dir(char *s)
{
	char	*path;

	path = purify(s);
	if (!ft_fork())
	{
		pwd();
		chdir(path);
		pwd();
	}
}

*/
// *l9walb: cd .. segfaults when you delete 
void	change_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (!dir)
		printf("%s\n", strerror(errno));
	else
		chdir(path);
}