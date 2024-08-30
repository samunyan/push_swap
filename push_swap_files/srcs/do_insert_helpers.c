/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_insert_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:30 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:31 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rra_and_rrb(t_stacks *stacks, int rotate_a, int rotate_b)
{
	rotate_a = ft_abs(rotate_a);
	rotate_b = ft_abs(rotate_b);
	while (rotate_a && rotate_b)
	{
		rrr(stacks);
		rotate_a--;
		rotate_b--;
	}
	while (rotate_a)
	{
		rra(stacks);
		rotate_a--;
	}
	while (rotate_b)
	{
		rrb(stacks);
		rotate_b--;
	}
}

static void	do_ra_and_rb(t_stacks *stacks, int rotate_a, int rotate_b)
{
	while (rotate_a && rotate_b)
	{
		rr(stacks);
		rotate_a--;
		rotate_b--;
	}
	while (rotate_a)
	{
		ra(stacks);
		rotate_a--;
	}
	while (rotate_b)
	{
		rb(stacks);
		rotate_b--;
	}
}

static void	do_ra_and_rrb(t_stacks *stacks, int rotate_a, int rotate_b)
{
	rotate_b = ft_abs(rotate_b);
	while (rotate_a)
	{
		ra(stacks);
		rotate_a--;
	}
	while (rotate_b)
	{
		rrb(stacks);
		rotate_b--;
	}
}

static void	do_rra_and_rb(t_stacks *stacks, int rotate_a, int rotate_b)
{
	rotate_a = ft_abs(rotate_a);
	while (rotate_a)
	{
		rra(stacks);
		rotate_a--;
	}
	while (rotate_b)
	{
		rb(stacks);
		rotate_b--;
	}
}

void	do_best_move(int **moves, t_stacks *stacks, int best_move)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = moves[A][best_move];
	rotate_b = moves[B][best_move];
	if (rotate_a < 0 && rotate_b < 0)
		do_rra_and_rrb(stacks, rotate_a, rotate_b);
	else if (rotate_a >= 0 && rotate_b >= 0)
		do_ra_and_rb(stacks, rotate_a, rotate_b);
	else if (rotate_a >= 0 && rotate_b < 0)
		do_ra_and_rrb(stacks, rotate_a, rotate_b);
	else if (rotate_a < 0 && rotate_b >= 0)
		do_rra_and_rb(stacks, rotate_a, rotate_b);
}
