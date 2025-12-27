/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 02:32:02 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:42:35 by bchagas-         ###   ########.fr       */
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
		ft_sa(a);
	else if (x > y && y > z)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (x > y && y < z && x > z)
		ft_ra(a);
	else if (x < y && y > z && x < z)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (x < y && y > z && x > z)
		ft_rra(a);
}

static void	ft_sort_four(t_stack *a, t_stack *b)
{
	if (a->size != 4)
		return ;
	ft_bring_min_top(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

static void	ft_sort_five(t_stack *a, t_stack *b)
{
	if (a->size != 5)
		return ;
	ft_bring_min_top(a);
	ft_pb(a, b);
	ft_bring_min_top(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	ft_sort_small(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return ;
	else if (a->size == 2 && a->head->value > a->head->next->value)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
}
