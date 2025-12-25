/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:27:01 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/25 06:18:47 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_push_all_b(t_stack *a, t_stack *b)
// {
// 	int median;
// 	int	rotations;

// 	median = ft_get_median(a);
// 	while (a->size > 3)
// 	{
// 		rotations = a->size;
// 		while (rotations-- && a->size > 3)
// 		{
// 			if (a->head->value < median)
// 				ft_pb(a, b);
// 			else
// 				ft_ra(a);
// 		}
// 		median = ft_get_median(a);
// 	}
// 	ft_sort_small(a);
// }
void	ft_push_all_b(t_stack *a, t_stack *b)
{
	int	pushed;
	int	size;
	int	median;

	size = a->size;
	median = ft_get_median(a);
	pushed = 0;
	while (size-- && pushed < a->size - 3)
	{
		if (a->head->value <= median)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
			ft_ra(a);
	}
	ft_sort_small(a);
}

t_cost	ft_calculate_cost(t_stack *a, t_stack *b, t_node *node)
{
	t_cost	cost;
	int		pos_a;
	int		pos_b;

	pos_a = ft_find_insert_pos(a, node->value);
	pos_b = ft_get_pos(b, node);
	if (pos_b <= b->size / 2)
		cost.cost_b = pos_b;
	else
		cost.cost_b = pos_b - b->size;
	if (pos_a <= a->size / 2)
		cost.cost_a = pos_a;
	else
		cost.cost_a = pos_a - a->size;
	cost.total = abs(cost.cost_a) + abs(cost.cost_b);
	cost.target = node;
	return (cost);
}

t_cost	ft_find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_cost	best;
	t_cost	current;
	int		first;
	
	cur = b->head;
	first = 1;
	while (cur)
	{
		current = ft_calculate_cost(a, b, cur);
		if (first || current.total < best.total)
		{
			best = current;
			first = 0;
		}
		cur = cur->next;
	}
	return (best);
}
void	ft_rotate_min_to_top(t_stack *a)
{
	t_node	*min;
	int		pos;
	
	min = ft_find_min(a);
	pos = ft_get_pos(a, min);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ft_ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			ft_rra(a);		
	}
}
#include <stdio.h>
void	ft_sort(t_stack *a, t_stack *b)
{
	t_cost	c;
	
	
	if (a->size <= 3)
	{
		ft_sort_small(a);
		return ;
	}
	if (a->size <= 5)
	{
		ft_sort_five(a, b);
		return ;
	}
	ft_push_all_b(a, b);
	while (b->size)
	{
		c = ft_find_cheapest(a, b);
		ft_execute_cost(a, b, c);
	}
	ft_rotate_min_to_top(a);
}