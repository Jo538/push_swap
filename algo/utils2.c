/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:46:36 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 11:53:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_cheapest(t_pair *array, int size_a)
{
	int	min;
	int	index_min;
	int	i;

	min = size_a;
	index_min = -1;
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

t_pair	*compute_pairs(t_stack	*stack_a, t_stack *stack_b)
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
		array[i].target_index = find_target(temp_a -> number, stack_b);
		array[i].all_cost = cost_to_top(array[i].target_index, i, size_a, size_b);
		temp_a = temp_a -> next;
		i++;
	}
	return (array);
}
