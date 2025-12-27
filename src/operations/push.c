/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:02 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:38:37 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b || b->size == 0)
		return ;
	ft_push(b, a);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0)
		return ;
	ft_push(a, b);
	ft_putendl_fd("pb", 1);
}
