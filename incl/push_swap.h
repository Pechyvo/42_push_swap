/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:51:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 17:12:22 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

// Stack creation
typedef struct s_stack
{
	int				content;
	int				index;
	int				pos;
	int				pos_target;
	int				cost;
	int				cost_final;
	int				minus;
	struct s_stack	*next;
}	t_stack;

int			ft_error_handle(char **argv);
void		ft_sort_two(t_stack **stack_a, t_stack **stack_b, int i);
void		ft_sort_two_b(t_stack **stack_b);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int			ft_main_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_cost_a(t_stack **stack_a);
void		ft_cost_b(t_stack **stack_b);
void		ft_cost_final(t_stack **stack_a, t_stack **stack_b);
void		ft_stackindex(t_stack **stack, int argc);
void		ft_stackposition(t_stack **stack);
void		ft_stackminus(t_stack **stack);
t_stack		*ft_stacknew(int content);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack		*ft_stackprelast(t_stack *stack);
void		ft_stackclear(t_stack **stack);
long int	ft_stackatoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_maxnode(t_stack **stack);
int			ft_checksort_a(t_stack *stack_a);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif