/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:41 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:42 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_non_lis_to_b(t_stacks *stacks)
{
	int	size;
	int	*arr;
	int	*lis;

	size = ft_s_lstsize(stacks->a);
	arr = create_array_from_list(stacks->a, size);
	if (!arr)
		ft_err_exit(stacks);
	lis = ft_get_lis(arr, size);
	free(arr);
	if (!lis)
		ft_err_exit(stacks);
	while (size)
	{
		if (ft_binary_search(lis + 1, *lis, get_value(stacks->a)) < 0)
			pb(stacks);
		else
			ra(stacks);
		size--;
	}
	free(lis);
}

void	rotate_smallest_to_top_of_a(t_stacks *stacks)
{
	t_s_list	*smallest;
	int			i;

	smallest = get_smallest(stacks->a, ft_s_lstsize(stacks->a));
	i = ft_s_lstfind_position(stacks->a, smallest);
	if (i > ft_s_lstsize(stacks->a) / 2)
	{
		while (stacks->a != smallest)
			rra(stacks);
	}
	else
	{
		while (stacks->a != smallest)
			ra(stacks);
	}
}

void	stack_sort_large(t_stacks *stacks)
{
	push_non_lis_to_b(stacks);
	insert_from_b_in_a(stacks);
	rotate_smallest_to_top_of_a(stacks);
}
