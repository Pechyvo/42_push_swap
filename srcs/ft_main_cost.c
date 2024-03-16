/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:19:39 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:58:30 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// 
void	ft_cost_a(t_stack **stack_a)
{
	t_stack	*head;
	int		final;

	final = 0;
	ft_stackminus(stack_a);
	ft_stackindex(stack_a, ft_stacklast(*stack_a)->pos + 1);
	head = (*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->minus == 0)
		{
			(*stack_a)->cost = (*stack_a)->pos - 1;
			final = (*stack_a)->pos;
			(*stack_a) = (*stack_a)->next;
		}
		else if ((*stack_a)->minus == 1)
		{
			(*stack_a)->cost = final - 1;
			final -= 1;
			(*stack_a) = (*stack_a)->next;
		}
	}
	(*stack_a) = head;
}

// 
void	ft_cost_b(t_stack **stack_b)
{
	t_stack	*head;
	int		final;

	final = 0;
	ft_stackminus(stack_b);
	ft_stackindex(stack_b, ft_stacklast(*stack_b)->pos + 1);
	head = (*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->minus == 0)
		{
			(*stack_b)->cost = (*stack_b)->pos - 1;
			final = (*stack_b)->pos;
			(*stack_b) = (*stack_b)->next;
		}
		else if ((*stack_b)->minus == 1)
		{
			(*stack_b)->cost = final - ft_stacklast((*stack_b))->pos % 2;
			final -= 1;
			(*stack_b) = (*stack_b)->next;
		}
	}
	(*stack_b) = head;
}

// 
static void	ft_cost_final_helper(t_stack **stack_a, t_stack **stack_b,
															t_stack *head)
{
	t_stack	*target;
	long	target_content;

	target_content = LONG_MAX;
	target = NULL;
	while ((*stack_a))
	{
		if ((*stack_a)->content > (*stack_b)->content
			&& (*stack_a)->content < target_content)
		{
			target_content = (*stack_a)->content;
			target = (*stack_a);
			(*stack_a) = (*stack_a)->next;
		}
		else
			(*stack_a) = (*stack_a)->next;
	}
	(*stack_b)->cost_final = (target)->cost + (*stack_b)->cost;
	(*stack_b)->pos_target = (target)->pos;
	(*stack_b) = (*stack_b)->next;
	(*stack_a) = head;
}

// 
void	ft_cost_final(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = (*stack_a);
	head_b = (*stack_b);
	while (*stack_b)
	{
		ft_cost_final_helper(stack_a, stack_b, head_a);
	}
	(*stack_b) = head_b;
}
