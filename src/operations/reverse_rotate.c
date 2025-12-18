/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:25 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/18 00:47:23 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
