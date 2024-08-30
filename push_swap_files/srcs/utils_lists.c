/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:20:49 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s_list	*get_smallest(t_s_list *stack, int size)
{
	t_s_list	*smallest;

	smallest = stack;
	while (size)
	{
		if (get_value(stack) < get_value(smallest))
			smallest = stack;
		stack = stack->next;
		size--;
	}
	return (smallest);
}

int	*create_array_from_list(t_s_list *lst, size_t size)
{
	int		*arr;
	size_t	j;

	arr = malloc(sizeof(int) * (size + 1));
	if (!arr)
		return (NULL);
	j = 0;
	while (j < size && lst)
	{
		arr[j] = get_value(lst);
		j++;
		lst = lst->next;
	}
	return (arr);
}

int	*get_sorted_array_from_list(t_s_list *lst, int size)
{
	int	*arr;

	arr = create_array_from_list(lst, size);
	if (arr)
		ft_quicksort(arr, 0, size - 1);
	return (arr);
}
