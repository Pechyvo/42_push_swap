/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Shifts down all elements of a stack by 1
// The last element becomes the first one
static void	ft_reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	tail = ft_stacklast(*stack);
	head = ft_stackprelast(*stack);
	tail->next = (*stack);
	(*stack) = tail;
	head->next = NULL;
	ft_stackposition(stack);
}

// Shifts down all elements of stack_a
void	rra(t_stack **stack_a)
{
	ft_reverse(stack_a);
	write(1, "rra\n", 4);
}

// Shifts down all elements of stack_b
void	rrb(t_stack **stack_b)
{
	ft_reverse(stack_b);
	write(1, "rrb\n", 4);
}

// Shifts down all elements of both stacks
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	write(1, "rrr\n", 4);
}
