/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:12:05 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/22 03:25:41 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
		
	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void ft_push(t_stack *from, t_stack *to)
{
	t_node	*node;
	
	if (!from || from -> size == 0)
		return ;
	node = from->head;
	
	from->head = node->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	from->size--;
	node->next = to->head;
	node->prev = NULL;
	if (to->head)
		to->head->prev = node;
	else
		to->tail = node;
	to->head = node;
	to->size++;			
}

void	ft_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->head;
	stack->head = node->next;
	stack->head->prev = NULL;
	node->next = NULL;
	node->prev = stack->tail;
	stack->tail->next = node;
	stack->tail = node;
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->tail;
	stack->tail = node->prev;
	stack->tail->next = NULL;
	node->prev = NULL;
	node->next = stack->head;
}
