/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:45 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:46 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort_max_3(t_stacks *stacks)
{
	size_t	size;

	size = ft_s_lstsize(stacks->a);
	if (size < 2)
		return ;
	if (get_value(stacks->a) > get_value(stacks->a->next))
		sa(stacks);
	if (size == 2)
		return ;
	if (get_value(stacks->a->next->next) < get_value(stacks->a))
		rra(stacks);
	if (get_value(stacks->a->next->next) < get_value(stacks->a->next))
	{
		rra(stacks);
		sa(stacks);
	}
}

void	stack_sort_max_5(t_stacks *stacks)
{
	int	pushed;

	pushed = 0;
	while (ft_s_lstsize(stacks->a) > 3)
	{
		rotate_smallest_to_top_of_a(stacks);
		pb(stacks);
		pushed++;
	}
	stack_sort_max_3(stacks);
	while (pushed)
	{
		pa(stacks);
		pushed--;
	}
}
