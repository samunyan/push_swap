/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:04:19 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:04:20 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "common.h"

typedef struct s_lookup_op
{
	char	*key;
	void	(*f)(t_stacks *);
}	t_lookup_op;

#endif