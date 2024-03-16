/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// #include <stdlib.h>
// // Example function to delete the content of a node
// void delete_content(void *content) {
//     free(content);
// }
// int main() {
//     // Create a linked list with one node
//     t_list *head = malloc(sizeof(t_list));
//     char *data = strdup("Hello, World!");
//     head->content = data;
//     head->next = NULL;

//     // Using your custom ft_lstdelone function
//     printf("Custom ft_lstdelone: %s\n", (char *)(head->content));
//     ft_lstdelone(head, delete_content);

//     // Note: The linked list head is now invalid as it has been freed

//     return 0;
// }
