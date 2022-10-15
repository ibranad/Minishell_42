#include "../Header/minishell.h"

int	lstsize(t_cmdl *lst)
{
	t_cmdl	*current;
	int		i;

	if (!lst)
		return (0);
	current = lst;
	i = 1;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}