/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:44:25 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 14:48:34 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Allocates memory for a new node and initializes it with the specified content
t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// Returns the last node of the stack
t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
	}
	return (node);
}

// Adds the specified node to a stack making it the last node
void	ft_stackadd_back(t_stack **stack, t_stack *next)
{
	if (!stack)
		return ;
	if (stack)
	{
		if (*stack)
		{
			ft_stacklast(*stack)->next = next;
			return ;
		}
	}
	*stack = next;
}

// Add a new element to the beginning of a stack
t_stack	*ft_stackprelast(t_stack *stack)
{
	if (stack != NULL)
	{
		while (stack->next->next != NULL)
			stack = stack->next;
	}
	return (stack);
}

// Clears the stack by freeing the memory of all its nodes
void	ft_stackclear(t_stack **stack)
{
	t_stack	*head;

	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		(*stack) = head;
	}
}
