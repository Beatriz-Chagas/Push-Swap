/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 04:21:18 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/22 04:48:20 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN (-2147483647 - 1)

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_cost
{
	int		cost_a;
	int		cost_b;
	int		total;
	t_node	*target;
}	t_cost;

/* parsing */
int		ft_parse(int argc, char **argv, t_stack *a);
int		ft_has_duplicate(t_stack *a, int value);
int		ft_push_number(t_stack *a, char *s);
char	**ft_join_args(int argc, char **argv);
int		ft_atol_safe(char *s, long *out);

/* stack */
t_stack	*ft_stacknew(void);
void	ft_stack_push_back(t_stack *stack, int value);
void	ft_stack_free(t_stack *stack);

/* sort */
void	ft_sort(t_stack *a, t_stack *b);
void	ft_sort_small(t_stack *a);
void	ft_sort_three(t_stack *a);
void	ft_sort_five(t_stack *a, t_stack *b);

/* Turk */
void	ft_push_all_b(t_stack *a, t_stack *b);
t_cost	ft_calculate_cost(t_stack *a, t_stack *b, t_node *node);
t_node	*ft_find_cheapest(t_stack *a, t_stack *b);
void	ft_execute_cost(t_stack *a, t_stack *b, t_cost cost);

/* helpers */
t_node	*ft_find_min(t_stack *a);
int		ft_get_pos(t_stack *a, t_node *n);
int		ft_find_insert_pos(t_stack *a, int value);
void	ft_bring_min_top(t_stack *a);

/* operations */
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *from, t_stack *to);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

#endif