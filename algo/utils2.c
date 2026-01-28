/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:46:36 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 18:03:04 by admin            ###   ########.fr       */
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
		if (flag == 'A')
			array[i].target_index = find_target_a(temp_a -> number, stack_b);
		else
			array[i].target_index = find_target_b(temp_a -> number, stack_b);
		array[i].all_cost = cost_to_top(array[i].target_index, i, size_a, size_b);
		temp_a = temp_a -> next;
		i++;
	}
	return (array);
}

void	sort_three(t_stack **stack_a)
{
	long	a;
	long	b;
	long	c;

	a = (*stack_a)->head->number;
	b = (*stack_a)->head->next->number;
	c = (*stack_a)->head->next->next->number;
	if (a > b && b < c && a < c)
		swap_one(&(*stack_a)->head);
	else if (a > b && b > c)
	{
		swap_one(&(*stack_a)->head);
		rrotate_one(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_one(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_one(&(*stack_a)->head);
		rotate_one(stack_a);
	}
	else if (a < b && b > c && a > c)
		rrotate_one(stack_a);
}
