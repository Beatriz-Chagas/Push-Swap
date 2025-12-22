/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 02:32:02 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/22 00:04:49 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *a)
{
	if (a->size < 2)
		return ;
	else if (a->size == 2 && a->head->value > a->head->next->value)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
}
//  213  |   132   |   321    |  231  |  312  |  123	|
//  sa   | sa + ra | sa + rra |  rra  |  ra   | return |
void    ft_sort_three(t_stack *a)
{
	int x;
	int y;
	int z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
	if (x > y && x < z && y < z)
		ft_sa(a);
	else if (x < y && y > z && z > x)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (x > y && y > z)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (x < y && x > z && y > z)
		ft_rra(a);
	else if (x > y && x > z && y < z)
		ft_ra(a);
	else
		return;
}
void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	push;

	if (a->size <= 3)
	{
		ft_sort_small(a);
		return ;
	}
	push = a->size - 3;
	while (push--)
	{
		ft_bring_min_top(a);
		ft_pb(a, b);
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_pa(a, b);
}
