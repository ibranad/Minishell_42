/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:34 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/10 20:09:02 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
#define EXP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>

#define SQ '\'' // Single Quote
#define DQ '\"' // Double Quote
#define DL '$'  // Dollar

typedef struct exp_s
{
    char *out;
    char *not_out;
    char *expa;
    int g_i;
}   t_exp;

char *get_until_dollar(char *in);
char *get_until_s_quote(char *in);
char *get_until_d_quote(char *in);


#endif