/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:22:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/03 08:54:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

char	**get_paths(t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "PATH"))
		{
			shell.paths_existence = EXISTING;	
			return ((split(curr->value, ':')));
		}
		curr = curr->next;
	}
	shell.paths_existence = UNEXISTING;
	return (NULL);
}

char	*fetch_path(char *cmd, char **paths)
{
	int		i;
	char	*path;
	
	if (!paths)
		return (NULL);
	str_tolower(cmd);
	i = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	while (paths[i])
	{
		path = strjoin_s(paths[i], cmd);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_env_var(t_envl *envl, char *key)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

// void	set_exit_status(void)
// {
// 	if (!WIFEXITED(shell.status) && WEXITSTATUS(shell.status) != 127)
// 	{
// 		printf("Program exited abnormally and it's NOT about a C.N.F\n");
// 		shell.status += 128;
// 		printf("And so the shell.status = %d\n", shell.status);
// 	}
// 	else if (WIFEXITED(shell.status))
// 	{
// 		printf("Program exited Normally\n");
// 		printf("Hence shell.status = %d\n", shell.status);
// 		shell.status = WEXITSTATUS(shell.status);
// 		printf("and WEXITSTATUS(shell.status) = %d\n",shell.status);
// 	}
// }
/*
	WIFEXITED will return true if the child process exited normally 
*/

void	set_exit_status(void)
{
	if (!WIFEXITED(shell.status))
		shell.status += 128;
	else
		shell.status = WEXITSTATUS(shell.status);
}