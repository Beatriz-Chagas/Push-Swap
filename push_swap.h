/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 04:21:18 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/02 05:03:33 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// init
t_stack	*parse_args(int ac, char **av);
void	validate_args(char **args);
t_stack	*init_stack(char **args);

// operations
void	sa(t_stack	**a);
void	sb(t_stack	**b);
void	ss(t_stack	**a, t_stack	**b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sort
void	index_stack(t_stack	*a);
void	sort_small(t_stack	**a, t_stack	**b);
void	sort_big(t_stack	**a, t_stack	**b);

// utils
int		is_sorted(t_stack	*a);
int		stack_size(t_stack	*a);
char	free_stack(t_stack	**stack);
void	error_exit(void);

#endif