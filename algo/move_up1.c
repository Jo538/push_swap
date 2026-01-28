/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:31:40 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 22:26:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operation_type(int index, int size)
{
	int	ops;

	if (index <= size / 2)
		ops = 1;
	else
		ops = -1;
	return (ops);
}

char	min_index(int index_a, int target_b)
{
	if (index_a < target_b)
		return (index_a);
	return (target_b);
}

void	move_common(t_stack **stack_a, t_stack **stack_b, int reps, int ops, char flag)
{
	int	i;

	i = 0;
	while (i < reps)
	{
		if (ops == 1)
			rotate_both(stack_a, stack_b);
		else
			rrotate_both(stack_a, stack_b);
		i++;
	}
	(void)flag;
}

void	move_single(t_stack **stack, int reps, int ops, char stack_flag)
{
	int	i;

	i = 0;
	while (i < reps)
	{
		if (ops == 1)
			rotate_one(stack, stack_flag);
		else
			rrotate_one(stack, stack_flag);
		i++;
	}
}

void	execute_stack_move(t_stack **stack, int index, int size, int ops, char flag)
{
	if (ops == 1)
		move_single(stack, index, ops, flag);
	else
		move_single(stack, size - index, ops, flag);
}
