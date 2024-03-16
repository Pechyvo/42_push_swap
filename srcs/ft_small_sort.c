/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:34:10 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 17:15:42 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

//	Sort two elements
void	ft_sort_two(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	one;
	int	two;

	if (i == 0)
	{
		one = (*stack_a)->content;
		two = (*stack_a)->next->content;
		if (one > two)
			sa(stack_a);
	}
	else
	{
		if (!*stack_b)
			return ;
		if (!(*stack_b)->next)
			return ;
		one = (*stack_b)->content;
		two = (*stack_b)->next->content;
		if (one < two && i == 1)
			sb(stack_b);
	}
}

// Sort three elements
void	ft_sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	if (!(*stack_a)->next->next)
		return ;
	one = (*stack_a)->content;
	two = (*stack_a)->next->content;
	three = (*stack_a)->next->next->content;
	if (one < three && three < two)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (one > three && one < two)
		rra(stack_a);
	else if (two < three && three < one)
		ra(stack_a);
	else if (one > two && one < three)
		sa(stack_a);
	else if (one > two && two > three)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

// Sort four elements
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	ft_sort_three(stack_a);
	if ((*stack_b)->index == 1)
		pa(stack_a, stack_b);
	else if ((*stack_b)->index == 2)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if ((*stack_b)->index == 3)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_b)->index == 4)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

// Helper function for sorting five elements
void	ft_five_helper(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next && !(*stack_b)->next->next)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
	}
	if (!(*stack_a)->next && (*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
	if (*stack_a && (*stack_a)->next && !(*stack_a)->next->next->next)
		ft_sort_three(stack_a);
}

// Sort five elements
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_stacklast(*stack_a)->pos;
	ft_stackindex(stack_a, i + 1);
	i = i / 2 + 1;
	while (ft_stacklast((*stack_a))->pos != i)
	{
		if ((*stack_a)->index < i)
		{
			pb(stack_b, stack_a);
			ft_five_helper(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	while ((*stack_b))
	{
		ft_sort_two(stack_a, stack_b, 0);
		ft_sort_two(stack_a, stack_b, 1);
		pa(stack_a, stack_b);
	}
}
