/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:40:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/28 21:37:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->head->number > (*stack_a)->head->next->number)
		swap_one(&(*stack_a)->head, 'A');
}

void	sort_three(t_stack **stack_a)
{
	long	first;
	long	second;
	long	third;

	first = (*stack_a)->head->number;
	second = (*stack_a)->head->next->number;
	third = (*stack_a)->head->next->next->number;
	if (first > second && second < third && first < third)
		swap_one(&(*stack_a)->head, 'A');
	else if (first > second && second > third)
	{
		swap_one(&(*stack_a)->head, 'A');
		rrotate_one(stack_a, 'A');
	}
	else if (first > second && second < third && first > third)
		rotate_one(stack_a, 'A');
	else if (first < second && second > third && first < third)
	{
		swap_one(&(*stack_a)->head, 'A');
		rotate_one(stack_a, 'A');
	}
	else if (first < second && second > third && first > third)
		rrotate_one(stack_a, 'A');
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = find_min_target(*stack_a);
	if (min_index == 1)
		swap_one(&(*stack_a)->head, 'A');
	else if (min_index == 2)
	{
		rotate_one(stack_a, 'A');
		rotate_one(stack_a, 'A');
	}
	else if (min_index == 3)
		rrotate_one(stack_a, 'A');
	push(stack_b, stack_a, 'B');
	sort_three(stack_a);
	push(stack_a, stack_b, 'A');
}

void	handle_small_cases(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
}
