/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:03:38 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/21 21:06:11 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEREDOC_H
# define HEREDOC_H

# include "../minishell.h"

int	ft_hd_short(char *line, char *lim, int pip);
int	ft_heredoc(char *lim);

#endif