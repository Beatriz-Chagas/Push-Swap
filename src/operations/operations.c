/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:12:05 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/18 00:17:42 by bchagas-         ###   ########.fr       */
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

void ft_push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*node;
	
	if (!stack_from || stack_from -> size == 0)
		return ;
	node = stack_from->head;
	
	stack_from->head = node->next;
	if (stack_from->head)
		stack_from->head->prev = NULL;
	else
		stack_from->tail = NULL;
	stack_from->size--;
	node->next = stack_to->head;
	node->prev = NULL;
	if (stack_to->head)
		stack_to->head->prev = node;
	else
		stack_to->tail = node;
	stack_to->head = node;
	stack_to->size++;			
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
