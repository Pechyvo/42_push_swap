/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int data = 42;

//     // Using your custom ft_lstnew function
//     t_list *node = ft_lstnew(&data);

//     // Print the content of the created node
//     if (node != NULL) {
//         printf("Custom ft_lstnew - Content: %d\n", *(int *)(node->content));
//         free(node);
//     } else {
//         printf("Custom ft_lstnew - Node creation failed.\n");
//     }

//     return 0;
// }
