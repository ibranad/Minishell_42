/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:48:46 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/08 18:37:44 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"


char *char_remove(char *str, char c)
{
  int i;
  char *line;

  i = 0;
  line = malloc(sizeof(char) * (strlen(str) - find_char(str, c)) + 1);
  int j = 0;
  
  while (str[i])
  {
    if (str[i] == c)
    {
      i++;
      if (str[i + 1] == c)
        while (str[i] == c)
          i++;
      line[j] = str[i];
    }
    else
      line[j] = str[i];
    i++;
    j++;
  }
  line[j] = 0;
  return(line);
}

int if_last_is(char *str, char c)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {
        j = i + 1;
        if (str[j] == '\0' && str[i] == c)
            return (1);
      i++;
    }
    return (0);
}
