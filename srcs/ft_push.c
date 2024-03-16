/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Takes the first element of one stack and puts it at the top of another
static void	ft_push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*content;
	t_stack	*head;
	int		index;

	if ((*stack_from) == NULL)
		return ;
	head = (*stack_from)->next;
	index = (*stack_from)->index;
	content = ft_stacknew((*stack_from)->content);
	content->next = (*stack_to);
	free(*stack_from);
	(*stack_from) = head;
	(*stack_to) = content;
	(*stack_to)->index = index;
	ft_stackposition(stack_from);
	ft_stackposition(stack_to);
}

// Pushes first element of stack_b to stack_a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

// Pushes first element of stack_a to stack_b
void	pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
