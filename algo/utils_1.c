/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 15:28:01 by jchartie         ###   ########.fr       */
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

int	*find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		*targets;
	int		b_tar;
	int		max;
	int		found;
	int		targets_size;
	int		i;

	temp_a = stack_a -> head;
	
	targets_size = 0;
	i = 0;
	while (temp_a)
	{
		targets_size++;
		temp_a = temp_a -> next;
	}
	printf("Size of targets array: %d\n\n", targets_size);

	targets = (int *)ft_calloc(targets_size, sizeof(int));
	if (!targets)
		return (NULL);

	temp_a = stack_a -> head;

	while (temp_a)
	{
		temp_b = stack_b -> head;
		max = temp_b -> number;
		found = 0;
		while (temp_b)
		{
			if (temp_b -> number > max)
				max = temp_b -> number;
			if (((temp_b -> number) < (temp_a -> number))
				&& (!found || (temp_b -> number > b_tar)))
			{
				b_tar = temp_b -> number;
				found = 1;
			}
			temp_b = temp_b -> next;
		}
		if (!found)
			targets[i] = max;
		else
			targets[i] = b_tar;
		temp_a = temp_a -> next;
		i++;
	}
	return (targets);
}
