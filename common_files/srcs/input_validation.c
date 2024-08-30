/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:18 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:19 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	number_is_in_stack(t_s_list *a, int nb)
{
	while (a)
	{
		if (nb == get_value(a))
			return (1);
		a = a->next;
	}
	return (0);
}

static int	str_is_numeric(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		i++;
		if (!s[i])
			return (1);
	}
	return (0);
}

static int	add_number_to_stack(t_stacks *stacks, char *s)
{
	t_s_list	*new;
	int			*number;

	number = malloc(sizeof(int));
	if (!number)
		return (0);
	*number = ft_atoi(s);
	if (!ft_atoi_is_valid(*number, s) || number_is_in_stack(stacks->a, *number))
	{
		free(number);
		return (0);
	}
	new = ft_s_lstnew(number);
	if (!new)
	{
		free(number);
		return (0);
	}
	ft_s_lstadd_back(&(stacks->a), new);
	return (1);
}

static void	gather_numbers(t_stacks *stacks, size_t size, char **tab)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!str_is_numeric(tab[i]) || !add_number_to_stack(stacks, tab[i]))
			ft_err_exit(stacks);
		i++;
	}
}

t_stacks	*init_stacks(size_t size, char **tab)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_err_exit(stacks);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->ops = NULL;
	gather_numbers(stacks, size, tab);
	return (stacks);
}
