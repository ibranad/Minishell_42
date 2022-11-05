/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/05 14:44:13 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	_export(char **entries, t_envl **envl)
{
	int		i;
	char	**entry;

	i = 0;
	if (!*entries)
		disp_export(envl);
	else
	{
		while (entries[i])
		{
			if (check_entry(entries[i], &i))
				continue ;
			entry = split(entries[i], '=');
			set_variable(entry[0], entry[1], envl);
			i++;
		}
	}
}

// TODO:
// * VERIFYIING THE KEY
//		** "-" not a valid identifier
//		** "=..." not a valid identifier
//		** ""
// *CASES:
//		** export new_var = value --> [export: `=': not a valid identifier] (new_var and value are both exported)
//		** export new_var= value --> [nothing output] (new_var's exported with "" and value's exported with no value)
//		** export new_var =val --> [export: `=val': not a valid identifier] (new_var's exported with no value)
//		** export --new_var=value --> [export: --:invalid option] nothing is exported
// 
//		** I should check before if the new_var already exits in the env


// *In case the key_val is NULL so there's no argument we just display the content of ENV

// * export =.... key=val k1=v1 k2=v2 : --> message error and k1 and k2 are exported with their values.
// export ""=""	 


//export +++-+
//export g======
// env is not export
