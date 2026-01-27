/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/27 11:17:52 by jchartie         ###   ########.fr       */
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

int	find_target(int num, t_stack *stack)
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

int	*create_targets(t_stack *stack_a, t_stack *stack_b)
{
	int		*targets;
	t_list	*temp;
	int		size;
	int		i;

	temp = stack_a -> head;

	size = 0;
	while (temp)
	{
		size++;
		temp = temp -> next;
	}

	printf("\nsize of targets array: %d\n", size);

	targets = (int *)ft_calloc(size, sizeof(int));
	if (!targets)
		return (NULL);

	temp = stack_a -> head;

	i = 0;
	while (temp)
	{
		targets[i] = find_target(temp -> number, stack_b);
		i++;
		temp = temp -> next;
	}
	return (targets);
}

int	*cost_to_tops(int *targets, t_stack *stack, int size_a, int size_b)
{
	t_list	*temp;
	int		*cost_to_top;
	int		cost_a;
	int		cost_b;
	int		i;

	temp = stack -> head;

	cost_to_top = (int *)ft_calloc(size_a, sizeof(int));
	if (!cost_to_top)
		return (NULL);

	i = 0;
	temp = stack -> head;
	while (temp)
	{
		if (i < (size_a / 2 + 1))
			cost_a = i;
		else
			cost_a = size_a - i;
		if (targets[i] < (size_b / 2 + 1))
			cost_b = targets[i];
		else
			cost_b = size_b - targets[i];
		cost_to_top[i] = cost_a + cost_b;
		temp = temp -> next;
		i++;
	}
	return (cost_to_top);
}
