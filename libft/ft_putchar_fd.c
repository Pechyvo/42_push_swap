/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <unistd.h>
// int main() {
//     char character = 'A';
//     int file_descriptor = 1; // Assuming stdout for testing

//     // Using your custom ft_putchar_fd function
//     ft_putchar_fd(character, file_descriptor);
// 	printf("\n");

//     // Using the standard library's write function
//     write(file_descriptor, &character, 1);
// 	printf("\n");

//     return 0;
// }
