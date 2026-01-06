/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 05:05:15 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 03:41:02 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack *a, int *cost)
{
	while (*cost > 0)
	{
		ft_ra(a, 1);
		(*cost)--;
	}
	while (*cost < 0)
	{
		ft_rra(a, 1);
		(*cost)++;
	}
}

static void	rotate_b(t_stack *b, int *cost)
{
	while (*cost > 0)
	{
		ft_rb(b, 1);
		(*cost)--;
	}
	while (*cost < 0)
	{
		ft_rrb(b, 1);
		(*cost)++;
	}
}

void	ft_execute_cost(t_stack *a, t_stack *b, t_cost c)
{
	while (c.cost_a > 0 && c.cost_b > 0)
	{
		ft_rr(a, b, 1);
		c.cost_a--;
		c.cost_b--;
	}
	while (c.cost_a < 0 && c.cost_b < 0)
	{
		ft_rrr(a, b, 1);
		c.cost_a++;
		c.cost_b++;
	}
	rotate_a(a, &c.cost_a);
	rotate_b(b, &c.cost_b);
	ft_pa(a, b, 1);
}
