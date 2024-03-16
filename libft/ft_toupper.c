/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int i = 97;
// 	printf("%c\n", i);
// 	printf("%c\n", i);
// 	int orig = toupper(i);
// 	int my = ft_toupper(i);
// 	printf("%c\n", orig);
// 	printf("%c\n", my);
// 	return (0);
// }
