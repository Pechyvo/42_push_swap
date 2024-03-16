/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:43:16 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 17:12:45 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Parse elements
static t_stack	*ft_parse(char **argv)
{
	t_stack	*stack_a;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
			stack_a = ft_stacknew(ft_stackatoi(argv[i]));
		else
			ft_stackadd_back(&stack_a, ft_stacknew(ft_stackatoi(argv[i])));
		i++;
	}
	return (stack_a);
}

// Choose sorting method for small amount of elements
static void	ft_small_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 3)
		ft_sort_two(stack_a, stack_b, 0);
	if (argc == 4)
		ft_sort_three(stack_a);
	if (argc == 5)
		ft_sort_four(stack_a, stack_b);
	if (argc == 6)
		ft_sort_five(stack_a, stack_b);
}

// Main function
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	ft_error_handle(argv);
	stack_a = ft_parse(argv);
	stack_b = NULL;
	ft_stackindex(&stack_a, argc);
	if (ft_checksort_a(stack_a) == 0)
	{
		ft_stackclear(&stack_a);
		return (0);
	}
	if (argc <= 6)
		ft_small_sort(argc, &stack_a, &stack_b);
	else
		ft_main_sort(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	return (0);
}
