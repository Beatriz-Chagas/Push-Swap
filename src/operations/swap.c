/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:18 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 01:46:23 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	ft_swap(a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	ft_swap(b);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack *a, t_stack *b, int print)
{
	if (!a || a->size < 2 || !b || b->size < 2)
		return ;
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_putendl_fd("ss", 1);
}
