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

// Push from stack_b to stack_a

void	push(t_stack **stack_a, t_stack **stack_b, char flag)
{
	t_list *temp;

	if (!(*stack_b) || !(*stack_b)->head)
		return ;
	
	temp = (*stack_b)->head;
	
	// Update stack_b head to the second node
	(*stack_b)->head = (*stack_b)->head->next;
	if ((*stack_b)->head)
		(*stack_b)->head->previous = NULL;
	else
		(*stack_b)->tail = NULL; // Stack B is now empty
	
	// Link temp node to stack_a
	temp->next = (*stack_a)->head;
	temp->previous = NULL;
	
	if ((*stack_a)->head)
		(*stack_a)->head->previous = temp;
	else
		(*stack_a)->tail = temp; // Stack A was empty
	
	(*stack_a)->head = temp;

	if (flag == 'A')
		write(1, "pa\n", 3);
	else	
		write(1, "pb\n", 3);
}
