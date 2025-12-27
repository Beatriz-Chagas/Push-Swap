/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:52:10 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:47:03 by bchagas-         ###   ########.fr       */
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
	t_node	*current;
	t_node	*max;

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

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	cur = a->head;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		i++;
	}
}

int	ft_get_median(t_stack *a)
{
	int	*arr;
	int	median;

	if (!a || a->size == 0)
		return (0);
	arr = stack_to_array(a);
	if (!arr)
		return (0);
	sort_array(arr, a->size);
	median = arr[a->size / 2];
	free(arr);
	return (median);
}
