/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:42:07 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:59:23 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Reset the index
static void	ft_resetindex(t_stack **stack)
{
	t_stack	*head;

	head = (*stack);
	while (*stack)
	{
		(*stack)->index = 0;
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
}

// Index helper function
static void	ft_indexhelper(t_stack **tmp, t_stack **stack, int value)
{
	while (*stack)
	{
		if (value >= (*stack)->content && (*stack)->index == 0)
		{
			(*tmp) = (*stack);
			value = (*stack)->content;
			(*stack) = (*stack)->next;
		}
		else if (value <= (*stack)->content || (*stack)->index != 0)
			(*stack) = (*stack)->next;
	}
}

// Indexing the stack
void	ft_stackindex(t_stack **stack, int argc)
{
	t_stack	*head;
	t_stack	*tmp;
	int		value;
	int		i;

	if (!*stack)
		return ;
	i = 1;
	tmp = NULL;
	value = ft_maxnode(stack);
	head = (*stack);
	ft_resetindex(stack);
	while (argc != 1)
	{
		ft_indexhelper(&tmp, stack, value);
		tmp->index = i;
		i++;
		argc--;
		(*stack) = head;
		value = ft_maxnode(stack);
	}
	tmp = head;
	ft_stackposition(stack);
}

// Positioning the stack
void	ft_stackposition(t_stack **stack)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = (*stack);
	while (*stack)
	{
		(*stack)->pos = i;
		(*stack) = (*stack)->next;
		i++;
	}
	(*stack) = head;
}

// Sign of the stack
void	ft_stackminus(t_stack **stack)
{
	t_stack	*head;
	int		middle;
	int		len;

	if (!*stack)
		return ;
	head = (*stack);
	len = ft_stacklast(*stack)->pos;
	middle = len / 2 + len % 2;
	while (*stack)
	{
		if ((*stack)->pos <= middle)
			(*stack)->minus = 0;
		else
			(*stack)->minus = 1;
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
}
