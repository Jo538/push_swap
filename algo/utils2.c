/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:46:36 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 19:35:49 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_target_a(int num, t_stack *stack)
{
	t_list	*temp;
	int		b_tar;
	int		i;
	int		index_btar;
	int		found;

	temp = stack -> head;
	i = 0;
	index_btar = 0;
	found = 0;

	while (temp)
	{
		if ((temp -> number > num) && (!found || (temp -> number < b_tar)))
		{
			b_tar = temp -> number;
			index_btar = i;
			found = 1;
		}
		temp = temp -> next;
		i++;
	}
	if (!found)
		return (find_min_target(stack));
	return (index_btar);
}

int	cost_to_top(int index_target, int index_a, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;

	if (index_a < (size_a / 2 + 1))
		cost_a = index_a;
	else
		cost_a = size_a - index_a;
	if (index_target < (size_b / 2 + 1))
		cost_b = index_target;
	else
		cost_b = size_b - index_target;
	return (cost_a + cost_b);
}

void	final_rotation(t_stack **stack_a)
{
	int	min;
	int	size_a;

	size_a = size_stack(*stack_a);
	min = find_min_target(*stack_a);
	if (min < size_a / 2 + 1)
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

void	sort_three(t_stack **stack_a)
{
	long	a;
	long	b;
	long	c;

	a = (*stack_a)->head->number;
	b = (*stack_a)->head->next->number;
	c = (*stack_a)->head->next->next->number;
	if (a > b && b < c && a < c)
		swap_one(&(*stack_a)->head, 'A');
	else if (a > b && b > c)
	{
		swap_one(&(*stack_a)->head, 'A');
		rrotate_one(stack_a, 'A');
	}
	else if (a > b && b < c && a > c)
		rotate_one(stack_a, 'A');
	else if (a < b && b > c && a < c)
	{
		swap_one(&(*stack_a)->head, 'A');
		rotate_one(stack_a, 'A');
	}
	else if (a < b && b > c && a > c)
		rrotate_one(stack_a, 'A');
}
