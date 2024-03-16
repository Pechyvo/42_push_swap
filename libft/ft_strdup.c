/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     const char str[] = "lorem ipsum dolor sit amet";
// // lorem ipsum dolor sit amet
//     // Using your custom ft_strdup function
//     char *result_ft = ft_strdup(str);

//     // Using the standard library's strdup function
//     char *result_std = strdup(str);

//     printf("Custom ft_strdup - Result: %s\n", result_ft);
//     printf("Standard strdup - Result: %s\n", result_std);

//     // Remember to free the allocated memory
//     free(result_ft);
//     free(result_std);

//     return 0;
// }
