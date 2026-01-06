/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 02:32:02 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 03:50:57 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
	if (x > y && y < z && x < z)
		ft_sa(a, 1);
	else if (x > y && y > z)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		ft_ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		ft_rra(a, 1);
}

static void	ft_sort_four(t_stack *a, t_stack *b)
{
	if (a->size != 4)
		return ;
	ft_bring_min_top(a);
	ft_pb(a, b, 1);
	ft_sort_three(a);
	ft_pa(a, b, 1);
}

static void	ft_sort_five(t_stack *a, t_stack *b)
{
	if (a->size != 5)
		return ;
	ft_bring_min_top(a);
	ft_pb(a, b, 1);
	ft_bring_min_top(a);
	ft_pb(a, b, 1);
	ft_sort_three(a);
	ft_pa(a, b, 1);
	ft_pa(a, b, 1);
}

void	ft_sort_small(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return ;
	else if (a->size == 2 && a->head->value > a->head->next->value)
		ft_sa(a, 1);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
}
