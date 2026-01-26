/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:57:04 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 11:31:57 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_one(t_stack **stack)
{
	t_list	*temp_head;
	t_list	*temp_tail;

	// Handle case where list is empty or list contains 1 node only
	if (!((*stack)-> head) || !((*stack)-> head -> next))
		return ;
	
	// Assign temp variables to head and tail of the stack,
	// i.e. point to first and last node
	temp_head = (*stack)-> head;
	temp_tail = (*stack)-> tail;

	// Set HEAD pointer to second node of the stack
	// Set previous pointer of the second node of the stack to NULL
	(*stack)-> head = (*stack)-> head -> next;
	(*stack)-> head -> previous = NULL;

	// Update next pointer of the last node in the stack to the first node
	(*stack)-> tail -> next = temp_head;

	// Set TAIL pointer to first node of the stack
	// Update first node's next pointer to NULL and previous pointer to last node
	(*stack)-> tail = temp_head;
	(*stack)-> tail -> next = NULL;
	(*stack)-> tail -> previous = temp_tail;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_one(stack_a);
	rotate_one(stack_b);
	write(1, "rr\n", 3);
}
