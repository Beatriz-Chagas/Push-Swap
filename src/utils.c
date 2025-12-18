/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:35:12 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/18 06:32:35 by bchagas-         ###   ########.fr       */
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
		
	}
}

int		ft_get_pos(t_stack *a, t_node *n);

int		ft_find_insert_pos(t_stack *a, int value);
