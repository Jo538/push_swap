/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:46:36 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 22:25:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_rotation_cost(int index, int size, int direction)
{
	int	cost;

	if (direction == 1)
		cost = index;
	else
		cost = size - index;
	return (cost);
}

int	cost_to_top(int index_target, int index_a, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;
	int		rotate_a;
	int		rotate_b;

	rotate_a = (index_a <= size_a / 2);
	rotate_b = (index_target <= size_b / 2);	
	cost_a = get_rotation_cost(index_a, size_a, rotate_a);
	cost_b = get_rotation_cost(index_target, size_b, rotate_b);
	if (rotate_a == rotate_b)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	final_rotation(t_stack **stack_a)
{
	int	min;
	int	size_a;

	size_a = size_stack(*stack_a);
	min = find_min_target(*stack_a);
	if (min <= size_a / 2)
	{
		while (min > 0)
		{
			rotate_one(stack_a, 'A');
			min--;
		}
	}
	else
	{
		while (min < size_a)
		{
			rrotate_one(stack_a, 'A');
			min++;
		}
	}
}

int	find_cheapest(t_pair *array, int size_a)
{
	int	min;
	int	index_min;
	int	i;

	min = 2147483647;
	index_min = 0;
	i = 0;

	while (i < size_a)
	{
		if (array[i].all_cost < min)
		{
			min = array[i].all_cost;
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

t_pair	*compute_pairs(t_stack	*stack_a, t_stack *stack_b, char flag)
{
	int		size_a;
	int		size_b;
	t_pair	*array;
	int		i;
	t_list	*temp_a;

	size_a = size_stack(stack_a);
	size_b = size_stack(stack_b);
	array = (t_pair *)ft_calloc(size_a, sizeof(t_pair));
	if (!array)
		return (NULL);

	i = 0;
	temp_a = stack_a -> head;
	while (i < size_a)
	{
		if (flag == 'B')
			array[i].target_index = find_target_b(temp_a -> number, stack_b);
		else
			array[i].target_index = find_target_a(temp_a -> number, stack_b);
		array[i].all_cost = cost_to_top(array[i].target_index, i, size_a, size_b);
		temp_a = temp_a -> next;
		i++;
	}
	return (array);
}
