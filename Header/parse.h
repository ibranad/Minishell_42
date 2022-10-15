/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:34 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/15 18:11:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define CYAN "\033[0;36m"
# define WHITE "\x1B[37m"

typedef struct s_cmdl
{
	int				idx;
	char			*path;
	char			**args;
	int				in_fd;
	int				out_fd;
	int				builtin;
	struct s_cmdl	*next;
	
}				t_cmdl;


#endif