/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:22 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:39:15 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_rotate(a);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_rotate(b);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2 || !b || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_putendl_fd("rr", 1);
}
