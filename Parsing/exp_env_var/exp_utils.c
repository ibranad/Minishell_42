/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:48:46 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/05 18:30:11 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

char *replace_it(char *str, char **env)
{
    int     i;
    t_dol   var;

    post_dollar(&var, str);
    i = 0;
    while(env[i])
    {
        if (ft_strncmp(var.str, env[i], var.len) == 0)
            return(&env[i][var.len]);
        i++;
    }
    return(NULL);
}

int is_in_env(char *str, char **env)
{
    int i;
    int j;

    i = 0;
    str = add_char_end(str, '=');
    while (env[i])
    {
        if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
        {
            free(str);
            return (1);
        }
        i++;
    }
    free(str);
    return (0);
}

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
