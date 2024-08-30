/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:52 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:53 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# define SA		"a"
# define SB		"b"
# define SS		"c"
# define RA		"d"
# define RB		"e"
# define RR		"f"
# define RRA	"g"
# define RRB	"h"
# define RRR	"i"
# define PA		"j"
# define PB		"k"

typedef struct s_stacks
{
	t_s_list	*a;
	t_s_list	*b;
	char		*ops;
}	t_stacks;

t_stacks	*init_stacks(size_t size, char **tab);
void		free_stacks(t_stacks *stacks);
void		ft_err_exit(t_stacks *stacks);
int			get_value(t_s_list *node);
int			stack_is_sorted_ascending(t_s_list *lst);

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

void		add_op(t_stacks *stacks, const char *op);
void		print_stacks(t_stacks *stacks);
void		print_arr(int a[], size_t n);
#endif