/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:26:28 by admin             #+#    #+#             */
/*   Updated: 2026/01/28 22:26:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_different(t_stack **stack_a, t_stack **stack_b, t_pair *array, int index_a, char flag)
{
	int		sizes[2];
	int		ops[2];
	char	flags[2];

	sizes[0] = size_stack(*stack_a);
	sizes[1] = size_stack(*stack_b);
	ops[0] = operation_type(index_a, sizes[0]);
	ops[1] = operation_type(array[index_a].target_index, sizes[1]);
	if (flag == 'B')
	{
		flags[0] = 'A';
		flags[1] = 'B';
	}
	else
	{
		flags[0] = 'B';
		flags[1] = 'A';
	}
	execute_stack_move(stack_a, index_a, sizes[0], ops[0], flags[0]);
	execute_stack_move(stack_b, array[index_a].target_index, sizes[1], ops[1], flags[1]);
}

void	execute_same_direction(t_stack **sa, t_stack **sb, int *costs, int ops, char flag)
{
	int		min;
	char	flag_a;
	char	flag_b;

	min = (costs[0] < costs[1]) ? costs[0] : costs[1];
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
	move_common(sa, sb, min, ops, flag);
	if (costs[0] > costs[1])
		move_single(sa, costs[0] - min, ops, flag_a);
	else if (costs[1] > costs[0])
		move_single(sb, costs[1] - min, ops, flag_b);
}

void	move_to_top(t_stack **stack_a, t_stack **stack_b, t_pair *array, int index_a, char flag)
{
	int		ops_a;
	int		ops_b;
	int		costs[2];

	ops_a = operation_type(index_a, size_stack(*stack_a));
	ops_b = operation_type(array[index_a].target_index, size_stack(*stack_b));
	costs[0] = get_rotation_cost(index_a, size_stack(*stack_a), ops_a);
	costs[1] = get_rotation_cost(array[index_a].target_index, 
			size_stack(*stack_b), ops_b);
	if (ops_a == ops_b)
		execute_same_direction(stack_a, stack_b, costs, ops_a, flag);
	else
		move_different(stack_a, stack_b, array, index_a, flag);
}
