/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:12:05 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/16 04:49:02 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
		
	if (!stack || stack->size < 2)
		return;
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
void ft_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	
	if (!stack_a || stack_a -> size == 0)
		return ;
	node = stack_a->head;
	
	stack_a->head = node->next;
	if (stack_a->head)
		stack_a->head->prev = NULL;
	else
		stack_a->tail = NULL;
	stack_a->size--;
	node->next = stack_b->head;
	node->prev = NULL;
	if (stack_b->head)
		stack_b->head->prev = node;
	else
		stack_b->tail = node;
	stack_b->head = node;
	stack_b->size++;			
}
