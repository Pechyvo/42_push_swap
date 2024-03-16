/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:22:56 by svalchuk          #+#    #+#             */
/*   Updated: 2024/03/08 16:33:25 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Check for duplicates
static int	ft_duplicates_handle(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = i + 1;
		while (argv[n])
		{
			if (ft_strcmp(argv[i], argv[n]) == 0)
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

// Check for symbols
static int	ft_symbol_handle(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == 45 && n == 0)
				n++;
			if (ft_isdigit(argv[i][n]) == 0)
				return (1);
			else
				n++;
		}
		i++;
	}
	return (0);
}

// Check for integer overflow
static int	ft_integer_handle(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_stackatoi(argv[i]) > INT_MAX || ft_stackatoi(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

// Check for 0 and -0
static int	ft_zero_handle(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[1][0] == '\0')
			return (1);
		if (argv[i][0] == 48 && argv [i][1])
			return (1);
		else if (argv[i][0] == 45 && argv[i][1] == 48)
			return (1);
		i++;
	}
	return (0);
}

// Error handling function
int	ft_error_handle(char **argv)
{
	if (ft_zero_handle(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_integer_handle(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_duplicates_handle(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (ft_symbol_handle(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}
