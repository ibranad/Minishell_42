/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:42 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/23 14:37:43 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_lstadd_front(t_cont **lst, t_cont *new)
{
	if (!(*lst))
		(*lst) = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

t_cont  *ft_lstnew(int content)
{
	t_cont	*new;

	new = malloc (sizeof(t_cont));
	new->next = NULL;
	return (new);
}

int ft_lstsize(t_cont *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int find_heredoc(char	**arr, int	len)
{
	int	i;
	int	j;
	int	fd;
	
	i = 0;
	j = 0;
	while (arr[i])
	{
		if (ft_strncmp(arr[i], "<", 1) == 0)
		{
			i++;
			if (ft_strncmp(arr[i], "<", 1) == 0)
			{
				i++;
				printf("lol\n");
				fd = ft_heredoc(arr[i]);
				if (i < len)
					continue ;
				else
					break ;
			}
		}
		i++;
	}
	return (fd);
}

int	main(void)
{
	char *line = "< cat  < < lim < < gh < < hj";
	char **arr;
	int	fd;
	int i = 0;;
	
	arr = ft_split(line, ' ');
	// while(arr[i])
	// {
	// 	printf("%s\n", arr[i]);
	// 	i++;
	// }
	fd = find_heredoc(arr, arr_len(arr));
	if (fd == -1)
	{
		printf("There was an error (heredoc fd = -1)\n");
		return(0);
	}
	char	c;

 	while (read(fd, &c, 1))
 		write(1, &c, 1);
}

/*
* cc -lreadline minishell_di_utils.c heredoc/heredoc.c Libft/ft_split.c Libft/ft_strncmp.c Libft/ft_strlcpy.c Libft/ft_strlen.c
*/