/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:05:18 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/16 04:59:35 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
    ft_swap(a);
    ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack *b)
{
    ft_swap(b);
    ft_putendl_fd("sb", 1);
}
void	ft_ss(t_stack *a, t_stack *b)
{
    ft_swap(a);
    ft_swap(b);
    ft_putendl_fd("ss", 2);
}