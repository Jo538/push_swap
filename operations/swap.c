/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:18:09 by admin             #+#    #+#             */
/*   Updated: 2026/01/28 18:23:23 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_one(t_list **head, char flag)
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

	if (flag == 'C')
		return ;
	if (flag == 'A')
		write(1, "sa\n", 3);
	else	
		write(1, "sb\n", 3);
}

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap_one(head_a, 'C');
	swap_one(head_b, 'C');
	write(1, "ss\n", 3);
}
