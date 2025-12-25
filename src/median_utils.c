/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:52:10 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/25 01:03:21 by bchagas-         ###   ########.fr       */
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
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*ft_find_max(t_stack *a)
{
	t_node  *current;
	t_node  *max;
	
	if (!a || !a->head)
		return (NULL);
	current = a->head;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;   
	}
	return (max);
}

int	ft_get_median(t_stack *a)
{
	t_node	*min;
	t_node	*max;

	min = ft_find_min(a);
	max = ft_find_max(a);
	return ((min->value + max->value) / 2);
}
