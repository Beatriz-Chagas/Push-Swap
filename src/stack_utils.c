/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:35:12 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/22 02:48:53 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_min(t_stack *a)
{
	t_node	*current;
	t_node	*min;

	if (!a || !a->head)
		return (NULL);
	current = a->head;
	min = current;
	while(current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

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

	current = a->head;
	pos = 0;
	while (current->next)
	{
		if (current->value < value && current->next->value > value)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (ft_get_pos(a, ft_find_min(a)));
}

void ft_bring_min_top(t_stack *a)
{
	t_node	*min;
	int		pos;
	
	min = ft_find_min(a);
	pos = ft_get_pos(a, min);
	if(pos <= a->size / 2)
	{
		while (a->head != min)
			ft_ra(a);
	}
	else
	{
		while (a->head != min)
			ft_rra(a);
	}
}