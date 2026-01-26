/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:20:23 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 14:49:02 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 
#include <stdio.h>

int main(void)
{
	#ifdef IS_SORTED_TEST

	long list_of_longs[] = {1, 2, -2, -1};
	int len = 4;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	t_stack *stack = create_stack(array_of_longs, len);

	int j = is_sorted(stack);

	if (j == 0)
		printf("%s\n", "The list is not sorted");
	else
		printf("%s\n", "The list is sorted");

	#endif


	
	#ifdef FIND_TARGET_TEST

	int num = -10;
	long list_of_longs[] = {-3, -1, 0, -2};
	int len = 4;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	t_stack *stack = create_stack(array_of_longs, len);

	int j = find_target(num, stack);

	printf("The target for %d is %d\n", num, j);
	
	#endif

}
