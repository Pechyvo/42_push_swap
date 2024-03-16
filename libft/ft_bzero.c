/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char buffer[10];
//     char buffer_std[10];

//     // Using your custom ft_bzero function
//     ft_bzero(buffer, sizeof(buffer));

//     // Using the standard library's bzero function
//     bzero(buffer_std, sizeof(buffer_std));

//     printf("Custom ft_bzero: ");
//     for (size_t i = 0; i < sizeof(buffer); i++) {
//         printf("%d ", buffer[i]);
//     }
//     printf("\n");

//     printf("Standard bzero: ");
//     for (size_t i = 0; i < sizeof(buffer_std); i++) {
//         printf("%d ", buffer_std[i]);
//     }
//     printf("\n");

//     return 0;
// }
