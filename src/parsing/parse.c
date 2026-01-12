/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 03:50:35 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/27 04:36:43 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_join_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	char	**result;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = joined;
		joined = ft_strjoin(joined, argv[i]);
		free(tmp);
		tmp = joined;
		joined = ft_strjoin(joined, " ");
		free(tmp);
		i++;
	}
	result = ft_split(joined, ' ');
	free(joined);
	return (result);
}

int	ft_atol_safe(char *str, long *out)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
	}
	*out = result * sign;
	return (1);
}

int	ft_has_duplicate(t_stack *a, int value)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_push_number(t_stack *a, char *s)
{
	long	value;

	if (!ft_atol_safe(s, &value))
		return (0);
	if (ft_has_duplicate(a, (int)value))
		return (0);
	ft_stack_push_back(a, (int)value);
	return (1);
}

int	ft_parse(int argc, char **argv, t_stack *a)
{
	char	**numbers;
	int		i;

	numbers = ft_join_args(argc, argv);
	if (!numbers[0])
	{
		ft_free_split(numbers);
		return (1);
	}
	i = 0;
	while (numbers[i])
	{
		if (!ft_valid_number(numbers[i]))
			return (ft_free_split(numbers), 1);
		if (!ft_push_number(a, numbers[i]))
			return (ft_free_split(numbers), 1);
		i++;
	}
	ft_free_split(numbers);
	return (0);
}
