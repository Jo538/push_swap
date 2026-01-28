/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 17:47:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	size_stack(t_stack *stack)
{
	t_list	*temp;
	int		size;

	temp = stack -> head;

	size = 0;
	while (temp)
	{
		size++;
		temp = temp -> next;
	}
	return (size);
}

int	is_sorted(t_stack *stack)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = stack -> head;
	while (temp -> next)
	{
		if ((temp -> number) > (temp -> next -> number))
			count++;
		temp = temp -> next;
	}
	if (count >= 1 && (temp -> number > stack-> head -> number))
		return (0);
	return (1);
}

int	find_max_target(t_stack *stack)
{
	t_list	*temp;
	int		max;
	int		i;
	int		index_max;

	temp = stack -> head;
	max = temp -> number;
	i = 0;
	index_max = 0;

	while (temp)
	{
		if (temp -> number > max)
		{
			max = temp -> number;
			index_max = i;
		}
		temp = temp -> next;
		i++;
	}
	return (index_max);
}

int	find_min_target(t_stack *stack)
{
	t_list	*temp;
	int		min;
	int		i;
	int		index_min;

	temp = stack -> head;
	min = temp -> number;
	i = 0;
	index_min = 0;

	while (temp)
	{
		if (temp -> number < min)
		{
			min = temp -> number;
			index_min = i;
		}
		temp = temp -> next;
		i++;
	}
	return (index_min);
}

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
		if ((temp -> number < num) && (!found || (temp -> number > b_tar)))
		{
			b_tar = temp -> number;
			index_btar = i;
			found = 1;
		}
		temp = temp -> next;
		i++;
	}
	if (!found)
		return (find_max_target(stack));
	return (index_btar);
}

int	find_target_b(int num, t_stack *stack)
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
		if ((temp -> number > num) && (!found || (temp -> number > b_tar)))
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
