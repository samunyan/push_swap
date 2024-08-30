/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:13 by samunyan          #+#    #+#             */
/*   Updated: 2022/06/08 18:04:15 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stacks *stacks)
{
	if (stack_is_sorted_ascending(stacks->a))
		return ;
	if (ft_s_lstsize(stacks->a) <= 3)
		stack_sort_max_3(stacks);
	else if (ft_s_lstsize(stacks->a) <= 5)
		stack_sort_max_5(stacks);
	else
		stack_sort_large(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = init_stacks(argc - 1, argv + 1);
	sort_stacks(stacks);
	if (stacks->ops)
		print_ops(stacks->ops);
	free_stacks(stacks);
	return (0);
}
