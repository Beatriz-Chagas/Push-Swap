/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:35:12 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:48:10 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_pos(t_stack *a, t_node *n)
{
	t_node	*cur;
	int		pos;

	if (!a || !n)
		return (-1);
	cur = a->head;
	pos = 0;
	while (cur)
	{
		if (cur == n)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

int	ft_find_insert_pos(t_stack *a, int value)
{
	t_node	*cur;
	int		pos;
	int		min;
	int		max;

	cur = a->head;
	pos = 0;
	min = ft_find_min(a)->value;
	max = ft_find_max(a)->value;
	if (value < min || value > max)
		return (ft_get_pos(a, ft_find_min(a)));
	while (cur->next)
	{
		if (cur->value < value && cur->next->value > value)
			return (pos + 1);
		cur = cur->next;
		pos++;
	}
	return (0);
}

void	ft_bring_min_top(t_stack *a)
{
	int	pos;
	int	rot;

	if (!a || a->size < 2)
		return ;
	pos = ft_get_pos(a, ft_find_min(a));
	if (pos == -1)
		return ;
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ft_ra(a);
	}
	else
	{
		rot = a->size - pos;
		while (rot-- > 0)
			ft_rra(a);
	}
}

void	ft_finalize_stack(t_stack *a)
{
	int	pos;

	pos = ft_get_pos(a, ft_find_min(a));
	if (pos <= a->size / 2)
		while (pos--)
			ft_ra(a);
	else
		while (pos++ < a->size)
			ft_rra(a);
}
