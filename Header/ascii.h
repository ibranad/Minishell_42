/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:14:54 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/15 17:17:45 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_H
# define ASCII_H

char	**split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_isblank(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
char	*charjoin(char *s1, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif