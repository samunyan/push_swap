/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:25 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:26 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_moves_for_b(t_stacks *stacks, int **moves, int size_b)
{
	t_s_list	*tmp_b;
	int			i;

	i = 0;
	tmp_b = stacks->b;
	while (tmp_b)
	{
		moves[B][i] = ft_s_lstfind_position(stacks->b, tmp_b);
		if (moves[B][i] > size_b / 2)
			moves[B][i] -= size_b;
		tmp_b = tmp_b->next;
		i++;
	}
}

static t_s_list	*get_node_with_value_greater_than(t_s_list *a, int value,
		int size_a)
{
	int	*arr;
	int	i;

	arr = get_sorted_array_from_list(a, size_a);
	if (!arr)
		return (NULL);
	i = 0;
	if (value < arr[i] || value > arr[size_a - 1])
	{
		free(arr);
		return (get_smallest(a, size_a));
	}
	while (i < size_a - 1 && !(arr[i] < value && value < arr[i + 1]))
		i++;
	while (a && (get_value(a) != arr[i + 1]))
		a = a->next;
	free(arr);
	return (a);
}

static void	compute_moves_for_a(t_stacks *stacks, int **moves, int size_a)
{
	t_s_list	*tmp_a;
	t_s_list	*tmp_b;
	int			i;

	i = 0;
	tmp_b = stacks->b;
	while (tmp_b)
	{
		tmp_a = get_node_with_value_greater_than(stacks->a,
				get_value(tmp_b), size_a);
		if (!tmp_a)
		{
			ft_free_arr_until((void **)moves, 1);
			ft_err_exit(stacks);
		}
		moves[A][i] = ft_s_lstfind_position(stacks->a, tmp_a);
		if (moves[A][i] > size_a / 2)
			moves[A][i] -= size_a;
		tmp_b = tmp_b->next;
		i++;
	}
}

static int	**alloc_arrays_for_moves(int size)
{
	int	**moves;
	int	i;

	moves = malloc(sizeof(int *) * 2);
	if (!moves)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		moves[i] = malloc(sizeof(int) * size);
		if (!moves[i])
		{
			ft_free_arr_until((void **)moves, i);
			return (NULL);
		}
		i++;
	}
	return (moves);
}

int	**compute_moves(t_stacks *stacks)
{
	int	size_b;
	int	**moves;

	size_b = ft_s_lstsize(stacks->b);
	moves = alloc_arrays_for_moves(size_b);
	if (!moves)
		ft_err_exit(stacks);
	compute_moves_for_b(stacks, moves, size_b);
	compute_moves_for_a(stacks, moves, ft_s_lstsize(stacks->a));
	return (moves);
}
