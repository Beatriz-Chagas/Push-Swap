/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 03:07:09 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/16 03:07:10 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_insert_pos(t_stack *a, int value)
{
	t_node	*curr;
	int		pos;

	curr = a->head;
	pos = 0;
	while (curr->next)
	{
		if (curr->value < value && curr->next->value > value)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}
	return (ft_get_pos(a, ft_find_min(a)));
}
