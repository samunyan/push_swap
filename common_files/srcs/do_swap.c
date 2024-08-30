/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:39 by samunyan          #+#    #+#             */
/*   Updated: 2022/06/08 18:04:40 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	do_swap(t_s_list **stack)
{
	t_s_list	*head;
	t_s_list	*next;

	if (ft_s_lstsize(*stack) < 2)
		return ;
	head = *stack;
	next = head->next;
	*stack = next;
	head->next = next->next;
	next->next = head;
}

void	sa(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
		return ;
	do_swap(&stacks->a);
	add_op(stacks, SA);
}

void	sb(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->b) < 2)
		return ;
	do_swap(&stacks->b);
	add_op(stacks, SB);
}

void	ss(t_stacks *stacks)
{
	if (ft_s_lstsize(stacks->a) < 2)
	{
		sb(stacks);
		return ;
	}
	if (ft_s_lstsize(stacks->b) < 2)
	{
		sa(stacks);
		return ;
	}
	do_swap(&stacks->a);
	do_swap(&stacks->b);
	add_op(stacks, SS);
}
