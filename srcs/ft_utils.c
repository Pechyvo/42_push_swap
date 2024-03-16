/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:41:27 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:46:17 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Convert a string to a long integer
long int	ft_stackatoi(const char *str)
{
	int		i;
	long	n;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	if (str[i] == 45)
	{
		neg *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			n *= 10;
			n += str[i] - 48;
			++i;
		}
		else
			return (0);
	}
	return (n * neg);
}

// Compare two strings
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// Find the maximum value in a stack
int	ft_maxnode(t_stack **stack)
{
	t_stack	*tmp;
	int		value;

	value = (*stack)->content;
	tmp = (*stack);
	while (tmp)
	{
		if (value < tmp->content)
		{
			value = tmp->content;
			tmp = tmp->next;
		}
		else if (value >= tmp->content)
			tmp = tmp->next;
	}
	return (value);
}

// Check if stack A is sorted
int	ft_checksort_a(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (1);
	}
	return (0);
}
