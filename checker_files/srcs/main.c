/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:04:21 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:04:22 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_op(char *op, t_stacks *stacks)
{
	size_t				i;
	static t_lookup_op	lookup_op[12] = {{"sa\n", sa}, {"sb\n", sb},
	{"ss\n", ss}, {"ra\n", ra}, {"rb\n", rb}, {"rr\n", rr},
	{"rra\n", rra}, {"rrb\n", rrb}, {"rrr\n", rrr},
	{"pa\n", pa}, {"pb\n", pb}, {NULL, NULL}};

	i = 0;
	while (lookup_op[i].key)
	{
		if (ft_strcmp(op, lookup_op[i].key) == 0)
		{
			lookup_op[i].f(stacks);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*op;

	if (argc == 1)
		return (0);
	stacks = init_stacks(argc - 1, argv + 1);
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (!do_op(op, stacks))
		{
			free(op);
			ft_err_exit(stacks);
		}
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted_ascending(stacks->a) && !stacks->b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stacks);
	return (0);
}
