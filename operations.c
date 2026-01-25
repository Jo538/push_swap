/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:18:09 by admin             #+#    #+#             */
/*   Updated: 2026/01/25 12:35:52 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **head, char *swap_type)
{
	t_list	*temp;

	if (!(*head) || !((*head)-> next))
		return ;
	temp = *head; // create temp node that points to first node
	*head = (*head) -> next; // have head point to second node

	// Link node 1 and node 3 together
	temp -> next = (*head)-> next;
	temp -> next -> previous = temp;

	// Link node 1 and node 2 back together
	temp -> previous = *head;
	(*head)-> next = temp;
	(*head)-> previous = NULL;
	
	write(1, swap_type, 2);
	write(1, "\n", 1);
}
