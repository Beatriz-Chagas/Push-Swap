/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:22 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/18 00:29:14 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putendl_fd("rr", 1);
}
