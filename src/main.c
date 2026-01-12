/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:39:24 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 00:52:39 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		ft_stack_free(a);
		ft_stack_free(b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!ft_is_sorted(a))
		ft_sort(a, b);
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
