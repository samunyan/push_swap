/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:01 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:02 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	*do_push(t_s_list **stack_from, t_s_list **stack_to)
{
	t_s_list	*tmp;

	if (*stack_from == NULL)
		return (NULL);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_s_lstadd_front(stack_to, tmp);
	return (*stack_to);
}

void	pa(t_stacks *stacks)
{
	if (do_push(&stacks->b, &stacks->a))
		add_op(stacks, PA);
}

void	pb(t_stacks *stacks)
{
	if (do_push(&stacks->a, &stacks->b))
		add_op(stacks, PB);
}
