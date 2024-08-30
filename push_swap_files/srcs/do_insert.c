/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:34 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:35 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_best_move(int *moves_a, int *moves_b, int size)
{
	int	moves;
	int	i;
	int	saved_index;
	int	tmp;

	moves = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (moves_a[i] >= 0 && moves_b[i] >= 0)
			tmp = ft_max(moves_a[i], moves_b[i]);
		else if (moves_a[i] < 0 && moves_b[i] < 0)
			tmp = ft_abs(ft_min(moves_a[i], moves_b[i]));
		else if (moves_a[i] >= 0 && moves_b[i] < 0)
			tmp = moves_a[i] + ft_abs(moves_b[i]);
		else if (moves_a[i] < 0 && moves_b[i] >= 0)
			tmp = moves_b[i] + ft_abs(moves_a[i]);
		if (tmp < moves)
		{
			saved_index = i;
			moves = tmp;
		}
		i++;
	}
	return (saved_index);
}

void	insert_from_b_in_a(t_stacks *stacks)
{
	int	**moves;
	int	best_move;

	while (stacks->b)
	{
		moves = compute_moves(stacks);
		best_move = choose_best_move(moves[A], moves[B],
				ft_s_lstsize(stacks->b));
		do_best_move(moves, stacks, best_move);
		pa(stacks);
		ft_free_arr_until((void **)moves, 1);
	}
}
