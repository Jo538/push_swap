/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:16:17 by admin             #+#    #+#             */
/*   Updated: 2026/01/28 18:08:04 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push from head_b to head_a

void	push(t_list **head_a, t_list **head_b, char flag)
{
	t_list *temp;

	if (!(*head_b))
		return ;
	temp = *head_b; // create temp pointer to first node in stack_b
	
	// Link head_b to the second node in stack_b
	(*head_b) = (*head_b)-> next;
	(*head_b)-> previous = NULL; 

	// Link the fist node in stack_a and stack_b
	temp -> next = *head_a;
	*head_a = temp;
	(*head_a)-> next -> previous = *head_a;
	(*head_a)-> previous = NULL;

	if (flag == 'A')
		write(1, "pa\n", 3);
	else	
		write(1, "pb\n", 3);
}
