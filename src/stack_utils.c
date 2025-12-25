/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:35:12 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/25 06:23:31 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_pos(t_stack *a, t_node *n)
{
	t_node	*current;
	int		pos;
	
	if(!a || !n)
		return (0);
	current = a->head;
	pos = 0;
	while (current)
	{
		if (current == n)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
	
}

int	ft_find_insert_pos(t_stack *a, int value)
{
	t_node	*current;
	int		pos;
	int		min;
	int		max;

	min = ft_find_min(a)->value;
	max = ft_find_max(a)->value;
	current = a->head;
	pos = 0;
	if (value < min || value > max)
		return (ft_get_pos(a, ft_find_min(a)));
	while (current->next)
	{
		if (current->value < value && current->next->value > value)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (ft_get_pos(a, ft_find_min(a)));
}

void	ft_bring_min_top(t_stack *a)
{
	int	pos;

	if (!a || a->size < 2)
		return ;
	pos = ft_get_pos(a, ft_find_min(a));
	if (pos <= a->size / 2)
		while (pos--)
			ft_ra(a);
	else
		while (pos++ < a->size)
			ft_rra(a);
}
