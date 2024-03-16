/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2026/07/26 00:00:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include <stdlib.h>
// // Helper function to print the contents of a linked list
// void print_list(t_list *head) {
//     while (head != NULL) {
//         printf("%d ", *(int *)(head->content));
//         head = head->next;
//     }
//     printf("\n");
// }
// int main() {
//     // Create an initial node
//     t_list *initial_node = malloc(sizeof(t_list));
//     int data1 = 42;
//     initial_node->content = &data1;
//     initial_node->next = NULL;

//     // Create a new node
//     t_list *new_node = malloc(sizeof(t_list));
//     int data2 = 24;
//     new_node->content = &data2;
//     new_node->next = NULL;

//     // Using your custom ft_lstadd_front function
//     ft_lstadd_front(&initial_node, new_node);

//     // Print the contents of the linked list
//	   // after adding a new node at the front
//     printf("Custom ft_lstadd_front - Result: ");
//     print_list(initial_node);

//     // Free the memory allocated for the linked list
//     free(initial_node);
//     free(new_node);

//     return 0;
// }
