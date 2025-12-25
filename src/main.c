/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:39:24 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/25 06:04:16 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->head;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
// void	print_stack(t_stack *a, char *name)
// {
// 	t_node	*tmp;

// 	tmp = a->head;
// 	ft_printf("%s: ", name);
// 	while (tmp)
// 	{
// 		ft_printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_stacknew();
	b = ft_stacknew();
	if (!a || !b)
		return (1);
	if (ft_parse(argc, argv, a))
		return (ft_putendl_fd("Error", 2), 1);
	if (!ft_is_sorted(a))
	{
		if (a->size <= 3)
			ft_sort_small(a);
		else if (a->size <= 5)
			ft_sort_five(a, b);
		else
			ft_sort(a, b);
	}
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}

