/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:25 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 01:48:34 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	ft_reverse_rotate(a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	ft_reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack *a, t_stack *b, int print)
{
	if (!a || a->size < 2 || !b || b->size < 2)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrr", 1);
}
