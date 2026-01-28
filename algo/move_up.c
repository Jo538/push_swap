/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:31:40 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 20:37:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operation_type(int index, int size)
{
	int	ops;

	if (index < (size / 2 + 1))
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

void	move_different(t_stack **stack_a, t_stack **stack_b, t_pair *array, int index_a, char flag)
{
	int	size_a;
	int	size_b;
	int	ops_a;
	int	ops_b;
	char	flag_a;
	char	flag_b;

	size_a = size_stack(*stack_a);
	size_b = size_stack(*stack_b);
	ops_a = operation_type(index_a, size_a);
	ops_b = operation_type(array[index_a].target_index, size_b);
	if (flag == 'B')
	{
		flag_a = 'A';
		flag_b = 'B';
	}
	else
	{
		flag_a = 'B';
		flag_b = 'A';
	}
	if (ops_a == 1)
		move_single(stack_a, index_a, ops_a, flag_a);
	else
		move_single(stack_a, size_a - index_a, ops_a, flag_a);
	if (ops_b == 1)
		move_single(stack_b, array[index_a].target_index, ops_b, flag_b);
	else
		move_single(stack_b, size_b - array[index_a].target_index, ops_b, flag_b);
}

void	move_to_top(t_stack **stack_a, t_stack **stack_b, t_pair *array, int index_a, char flag)
{
	int		size_a;
	int		size_b;
	int		ops_a;
	int		ops_b;
	int		min;
	char	flag_a;
	char	flag_b;

	size_a = size_stack(*stack_a);
	size_b = size_stack(*stack_b);
	ops_a = operation_type(index_a, size_a);
	ops_b = operation_type(array[index_a].target_index, size_b);
	min = min_index(index_a, array[index_a].target_index);
	if (flag == 'B')
	{
		flag_a = 'A';
		flag_b = 'B';
	}
	else
	{
		flag_a = 'B';
		flag_b = 'A';
	}
	if (ops_a == ops_b)
	{
		move_common(stack_a, stack_b, min, ops_a, flag);
		if (index_a > array[index_a].target_index)
			move_single(stack_a, index_a - min, ops_a, flag_a);
		else
			move_single(stack_b, array[index_a].target_index - min, ops_b, flag_b);
	}
	else
		move_different(stack_a, stack_b, array, index_a, flag);
}


