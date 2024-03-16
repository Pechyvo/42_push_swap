/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char source[] = "Hello, World!";
//     char destination[20];
//     char destination_std[20];

//     // Test your custom ft_memcpy function
//     ft_memcpy(NULL, NULL, 5);

//     // Test the standard library's memcpy function
//     memcpy(NULL, NULL, 5);

//     printf("Custom ft_memcpy - Destination: %s\n", destination);
//     printf("Standard memcpy - Destination: %s\n", destination_std);

//     return 0;
// }
