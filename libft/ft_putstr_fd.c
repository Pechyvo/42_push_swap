/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// #include <stdio.h>
// #include <unistd.h>
// int main() {
//     char str[] = "Hello, World!";
//     int file_descriptor = 1; // Assuming stdout for testing

//     // Using your custom ft_putstr_fd function
//     //printf("Custom ft_putstr_fd - Result: ");
//     ft_putstr_fd(str, file_descriptor);
// 	printf("\n");

//     // Using the standard library's write function
//     //printf("\nStandard write - Result: ");
//     write(file_descriptor, str, sizeof(str) - 1);
//		// sizeof(str) - 1 to exclude the null terminator
// 	printf("\n");

//     return 0;
// }
