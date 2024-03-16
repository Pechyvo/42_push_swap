/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

// #include <stdio.h>
// // Example function to print the index and character
// void print_index_char(unsigned int index, char *character) {
//     printf("Index: %u, Character: %c\n", index, *character);
// }

// int main() {
//     char str[] = "Hello, World!";

//     // Using your custom ft_striteri function
//     printf("Custom ft_striteri - Result:\n");
//     ft_striteri(str, print_index_char);

//     return 0;
// }
