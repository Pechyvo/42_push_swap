/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:33:50 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:36:36 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Shift up all elements of a stack by 1
// The first element becomes the last one
static void	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	head = (*stack);
	(*stack) = (*stack)->next;
	tail = ft_stacklast(*stack);
	head->next = NULL;
	tail->next = head;
	ft_stackposition(stack);
}

// Shifts up all elements of a stack_a
void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

// Shifts up all elements of a stack_b
void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

// Shifts up all elements of both stacks
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
