/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 18:27:11 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	find_max_target(int num, t_stack *stack)
{
	
}

int	find_target(int num, t_stack *stack)
{
	t_list	*temp;
	int		b_tar;
	int		index;
	int		max;
	int		found;

	temp = stack -> head;
	max = temp -> number;
	index = 0;
	found = 0;

	while (temp)
	{
		if (temp -> number > max)
			max = temp -> number;
		if ((temp -> number < num) && (!found || (temp -> number > b_tar)))
		{
			b_tar = temp -> number;
			found = 1;
		}
		temp = temp -> next;
	}
	if (!found)
		return (max);
	return (b_tar);
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
