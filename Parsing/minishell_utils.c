/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:50:28 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/06 18:02:56 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	saj_short(t_vt *v, char *src)
{
	while (v->i < v->s_len)
	{
		v->arr[v->i] = src[v->i];
		v->i++;
	}
}

char	*slash_av_join(char *src, char c, char *dest)
{
	t_vt	v;

	v.i = 0;
	v.j = 0;
	v.s_len = ft_strlen(src);
	v.d_len = ft_strlen(dest);
	v.arr = malloc(sizeof(char) * (v.s_len + v.d_len + 2));
	saj_short(&v, src);
	while (v.j < 1)
	{
		v.arr[v.i] = c;
		v.i++;
		v.j++;
	}
	v.j = 0;
	while (v.j < v.d_len)
	{
		v.arr[v.i] = dest[v.j];
		v.i++;
		v.j++;
	}
	v.arr[v.i] = '\0';
	return (v.arr);
}

char	*get_path_line(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

char	**get_path(char **env)
{
	char	*ar;
	char	**arr;

	ar = get_path_line(env);
	arr = ft_split(ar, ':');
	return (arr);
}

char	*av_join_acess(char **env, char *av)
{
	int		i;
	char	*joining;

	i = 0;
	while (env[i])
	{
		joining = slash_av_join(env[i], '/', av);
		if (access(joining, F_OK & X_OK) == 0)
			return (joining);
		i++;
	}
	return (joining);
}

// int main(int ac, char **av, char **env)
// {
//     char    **arr;
//     char    **c_arg;
//     char    *cmd;

//     arr = get_path(env);
// 	c_arg = ft_split("ls -l", ' ');
// 	cmd = av_join_acess(arr, c_arg[0]);
//     printf("%s\n", cmd);
// }
