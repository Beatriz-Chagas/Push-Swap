/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 02:32:02 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/25 06:44:56 by bchagas-         ###   ########.fr       */
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

void	ft_sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;

	if (x > y && y < z && x < z)          // 2 1 3
		ft_sa(a);
	else if (x > y && y > z)              // 3 2 1
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (x > y && y < z && x > z)     // 3 1 2
		ft_ra(a);
	else if (x < y && y > z && x < z)     // 1 3 2
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (x < y && y > z && x > z)     // 2 3 1
		ft_rra(a);
}
t_node	*ft_find_value(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->head;
	while (cur)
	{
		if (cur->value == value)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	ft_bring_value_top(t_stack *a, int value)
{
	int	pos;

	pos = ft_get_pos(a, ft_find_value(a, value));
	if (pos <= a->size / 2)
		while (pos--)
			ft_ra(a);
	else
		while (pos++ < a->size)
			ft_rra(a);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	second_min;

	if (a->size <= 3)
		return (ft_sort_small(a));

	min = ft_find_min(a)->value;
	ft_bring_value_top(a, min);
	ft_pb(a, b);

	second_min = ft_find_min(a)->value;
	ft_bring_value_top(a, second_min);
	ft_pb(a, b);

	ft_sort_three(a);

	if (b->head->value < b->head->next->value)
		ft_sb(b);

	ft_pa(a, b);
	ft_pa(a, b);
}
