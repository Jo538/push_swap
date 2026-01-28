/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:43:43 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 22:30:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_one(t_stack **stack, char flag)
{
	t_list	*temp_head;
	t_list	*temp_tail;

	if (!((*stack)-> head) || !((*stack)-> head -> next))
		return ;
	temp_head = (*stack)-> head;
	temp_tail = (*stack)-> tail;
	(*stack)-> tail = temp_tail -> previous;
	(*stack)-> tail -> next = NULL;
	(*stack)-> head = temp_tail;
	(*stack)-> head -> previous = NULL;
	(*stack)-> head -> next = temp_head;
	temp_head -> previous = (*stack)-> head;
	if (flag == 'C')
		return ;
	if (flag == 'A')
		write(1, "rra\n", 4);
	else	
		write(1, "rrb\n", 4);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rrotate_one(stack_a, 'C');
	rrotate_one(stack_b, 'C');
	write(1, "rrr\n", 4);
}
