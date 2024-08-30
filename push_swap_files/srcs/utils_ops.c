/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:52 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:53 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(char *ops)
{
	size_t				i;
	size_t				j;
	static t_hash_ops	hash_ops[12] = {{SA, "sa"}, {SB, "sb"},
	{SS, "ss"}, {RA, "ra"}, {RB, "rb"}, {RR, "rr"},
	{RRA, "rra"}, {RRB, "rrb"}, {RRR, "rrr"}, {PA, "pa"},
	{PB, "pb"}, {NULL, NULL}};

	i = 0;
	while (ops[i])
	{
		j = 0;
		while (hash_ops[j].key)
		{
			if (ops[i] == *(hash_ops[j].key))
			{
				ft_printf("%s\n", hash_ops[j].value);
				break ;
			}
			j++;
		}
		i++;
	}
}
