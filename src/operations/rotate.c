/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:22 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 01:47:18 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	ft_rotate(a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	ft_rotate(b);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack *a, t_stack *b, int print)
{
	if (!a || a->size < 2 || !b || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		ft_putendl_fd("rr", 1);
}
