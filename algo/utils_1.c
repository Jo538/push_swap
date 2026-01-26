/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:37 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 14:46:51 by jchartie         ###   ########.fr       */
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

int	find_target(int num, t_stack *stack)
{
	t_list	*temp;
	int		b_tar;
	int		max;
	int		found;

	temp = stack -> head;
	max = temp -> number;
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
