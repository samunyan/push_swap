/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:22 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_stacks(t_stacks *stacks)
{
	ft_s_lstclear(&(stacks->a), free);
	ft_s_lstclear(&(stacks->b), free);
	free(stacks->ops);
	free(stacks);
}

void	ft_err_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	get_value(t_s_list *node)
{
	return ((*(int *)node->content));
}

int	stack_is_sorted_ascending(t_s_list *lst)
{
	while (lst && lst->next)
	{
		if (get_value(lst) > get_value(lst->next))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	add_op(t_stacks *stacks, const char *op)
{
	ft_append(&(stacks->ops), op);
	if (!stacks->ops)
		ft_err_exit(stacks);
}
