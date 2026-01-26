/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:43:43 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 12:08:41 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_one(t_stack **stack)
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

	// Set TAIL pointer to second last node of the stack
	// Update second last node's next pointer to NULL
	(*stack)-> tail = temp_tail -> previous;
	(*stack)-> tail -> next = NULL;

	// Set HEAD pointer to last node of the stack
	// Set previous pointer of the last node of the stack to NULL
	// Set next pointer of the last node of the stack to first node
	(*stack)-> head = temp_tail;
	(*stack)-> head -> previous = NULL;
	(*stack)-> head -> next = temp_head;

	// Update previous pointer of the first node to the last node
	temp_head -> previous = (*stack)-> head;
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rrotate_one(stack_a);
	rrotate_one(stack_b);
	write(1, "rrr\n", 4);
}