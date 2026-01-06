/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:58:10 by bchagas-          #+#    #+#             */
/*   Updated: 2026/01/06 03:56:51 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_read_and_exec(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(0);
			continue ;
		}
		if (!ft_exec_instruction(line, a, b))
		{
			free(line);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

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
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_read_and_exec(a, b);
	if (ft_is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
