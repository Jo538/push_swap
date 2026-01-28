/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/28 20:08:44 by admin            ###   ########.fr       */
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
