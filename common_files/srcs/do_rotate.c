/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:08 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:09 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	do_rotate(t_s_list **stack)
{
	t_s_list	*tmp;

	if (ft_s_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_s_lstadd_back(stack, tmp);
}

void	ra(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
		return ;
	do_rotate(&stacks->a);
	add_op(stacks, RA);
}

void	rb(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->b) < 2)
		return ;
	do_rotate(&stacks->b);
	add_op(stacks, RB);
}

void	rr(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
	{
		rb(stacks);
		return ;
	}
	if (ft_s_lstsize(stacks->b) < 2)
	{
		ra(stacks);
		return ;
	}
	do_rotate(&stacks->a);
	do_rotate(&stacks->b);
	add_op(stacks, RR);
}
