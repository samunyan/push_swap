/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:25 by samunyan          #+#    #+#             */
/*   Updated: 2022/06/08 18:04:27 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

# define A		0
# define B		1

typedef struct s_hash_ops
{
	char	*key;
	char	*value;
}	t_hash_ops;

void		sort_stacks(t_stacks *stacks);
void		stack_sort_max_3(t_stacks *stacks);
void		stack_sort_max_5(t_stacks *stacks);
void		stack_sort_large(t_stacks *stacks);
int			**compute_moves(t_stacks *stacks);
void		insert_from_b_in_a(t_stacks *stacks);
void		do_best_move(int **moves, t_stacks *stacks, int best_move);
void		rotate_smallest_to_top_of_a(t_stacks *stacks);
void		print_ops(char *ops);
int			*create_array_from_list(t_s_list *lst, size_t size);
int			*get_sorted_array_from_list(t_s_list *lst, int size);
t_s_list	*get_smallest(t_s_list *stack, int size);

#endif