/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:57:04 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 22:30:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_one(t_stack **stack, char flag)
{
	t_list	*temp_head;
	t_list	*temp_tail;

	if (!((*stack)-> head) || !((*stack)-> head -> next))
		return ;
	temp_head = (*stack)-> head;
	temp_tail = (*stack)-> tail;
	(*stack)-> head = (*stack)-> head -> next;
	(*stack)-> head -> previous = NULL;
	(*stack)-> tail -> next = temp_head;
	(*stack)-> tail = temp_head;
	(*stack)-> tail -> next = NULL;
	(*stack)-> tail -> previous = temp_tail;
	if (flag == 'C')
		return ;
	if (flag == 'A')
		write(1, "ra\n", 3);
	else	
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_one(stack_a, 'C');
	rotate_one(stack_b, 'C');
	write(1, "rr\n", 3);
}
