/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:28:36 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:36:42 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Swaps first two elements of a stack
static void	ft_swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = (*stack);
	second = (*stack)->next->next;
	(*stack) = (*stack)->next;
	(*stack)->next = head;
	head->next = second;
	ft_stackposition(stack);
}

// Swaps first two elements of a stack_a
void	sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

// Swaps first two elements of a stack_b
void	sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

// Swaps first two elements of a both stacks separately
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
