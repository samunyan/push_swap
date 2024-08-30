/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:06 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:07 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	do_reverse_rotate(t_s_list **stack)
{
	t_s_list	*new_head;
	t_s_list	*last;

	if (ft_s_lstsize(*stack) < 2)
		return ;
	new_head = ft_s_lstlast(*stack);
	last = *stack;
	while (last->next != new_head)
		last = last->next;
	last->next = NULL;
	ft_s_lstadd_front(stack, new_head);
}

void	rra(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
		return ;
	do_reverse_rotate(&stacks->a);
	add_op(stacks, RRA);
}

void	rrb(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->b) < 2)
		return ;
	do_reverse_rotate(&stacks->b);
	add_op(stacks, RRB);
}

void	rrr(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
	{
		rrb(stacks);
		return ;
	}
	if (ft_s_lstsize(stacks->b) < 2)
	{
		rra(stacks);
		return ;
	}
	do_reverse_rotate(&stacks->a);
	do_reverse_rotate(&stacks->b);
	add_op(stacks, RRR);
}
