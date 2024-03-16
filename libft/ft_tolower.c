/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c += 32);
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int i = 66;
// 	printf("%c\n", i);
// 	printf("%c\n", i);
// 	int orig = tolower(i);
// 	int my = ft_tolower(i);
// 	printf("%c\n", orig);
// 	printf("%c\n", my);
// 	return (0);
// }
