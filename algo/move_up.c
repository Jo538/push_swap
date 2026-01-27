/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:31:40 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/27 17:04:45 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operation_type(int index, int size)
{
	char	*operation;

	if (index < (size / 2 + 1))
		operation = 1;
	else
		operation = -1;
	return (operation);
}

void	repeat_move(t_stack **stack, int reps, int operation)
{
	int	i;

	i = 0;
	while (i < reps)
	{
		if (operation == 1)
			rotate_one(stack);
		else
			rrotate_one(stack);
		i++;
	}
}

void	repeat_move_2(t_stack **stack_a, t_stack **stack_b, int reps, int ops)
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
}

void	move_to_top(t_stack **stack_a, t_stack **stack_b, int index_a, int index_b)
{
	int		size_a;
	int		size_b;
	int		operation_a;
	int		operation_b;
	int		min;

	size_a = size_stack(stack_a);
	size_b = size_stack(stack_b);

	operation_a = operations_direction(index_a, size_a);
	operation_b = operations_direction(index_b, size_b);

	if (index_a < index_b)
		min = index_a;
	else
		min = index_b;

	if (operation_a == operation_b)
		repeat_move_2(stack_a, stack_b, min, operation_a);
}


