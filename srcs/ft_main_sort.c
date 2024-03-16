/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:30:57 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:46:56 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Quick sort algorithm
static int	ft_quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_stacklast(*stack_a)->pos;
	ft_stackindex(stack_a, i + 1);
	if (i <= 3)
	{
		ft_sort_three(stack_a);
		return (1);
	}
	i = i / 2 + 1;
	while (ft_stacklast((*stack_a))->pos != i)
	{
		if ((*stack_a)->index <= i)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	return (ft_quick_sort(stack_a, stack_b));
}

// Double rotate helper function
static void	ft_double_rotate(t_stack **stack_a, t_stack **stack_b,
									t_stack *target, t_stack *inner)
{
	int	cost_a;
	int	cost_b;
	int	i;

	i = 0;
	cost_a = inner->cost;
	cost_b = target->cost;
	if (inner->minus != target->minus)
		return ;
	if (cost_a == cost_b)
		i = inner->cost;
	else if (cost_a > cost_b)
		i = cost_b;
	else if (cost_a < cost_b)
		i = cost_a;
	while (i != 0)
	{
		if (inner->minus == 1)
			rrr(stack_a, stack_b);
		else if (inner->minus == 0)
			rr(stack_a, stack_b);
		i--;
	}
}

// Inner push helper function
static void	ft_inner_push(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	t_stack	*head_a;
	t_stack	*inner;

	head_a = (*stack_a);
	while (target->pos_target != (*stack_a)->pos)
		(*stack_a) = (*stack_a)->next;
	inner = (*stack_a);
	(*stack_a) = head_a;
	ft_double_rotate(stack_a, stack_b, target, inner);
	while (target->content != (*stack_b)->content)
	{
		if (target->minus == 1)
			rrb(stack_b);
		else if (target->minus == 0)
			rb(stack_b);
	}
	while (inner->content != (*stack_a)->content)
	{
		if (inner->minus == 1)
			rra(stack_a);
		else if (inner->minus == 0)
			ra(stack_a);
	}
	pa(stack_a, stack_b);
}

// Cost based sorting
static void	ft_cost_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;
	t_stack	*target;

	ft_cost_a(stack_a);
	ft_cost_b(stack_b);
	ft_cost_final(stack_a, stack_b);
	head_b = (*stack_b);
	target = (*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->cost_final < target->cost_final)
			target = (*stack_b);
		else if ((*stack_b)->cost_final == target->cost_final)
		{
			if ((*stack_b)->content < target->content)
				target = (*stack_b);
		}
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = head_b;
	ft_inner_push(stack_a, stack_b, target);
}

// Main sorting algorithm
int	ft_main_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*middle;

	ft_quick_sort(stack_a, stack_b);
	while (ft_checksort_a(*stack_a) != 0 || (*stack_b) != NULL)
	{
		ft_cost_sort(stack_a, stack_b);
		if (!*stack_b)
			break ;
	}
	middle = (*stack_a);
	while ((*stack_a)->content <= middle->content)
		middle = middle->next;
	ft_stackminus(stack_a);
	while (ft_checksort_a(*stack_a) != 0)
	{
		if (middle->minus == 1)
			rra(stack_a);
		else
			ra(stack_a);
	}
	return (0);
}
