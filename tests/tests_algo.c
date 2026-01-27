/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:20:23 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/27 13:38:52 by jchartie         ###   ########.fr       */
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

	int num = 2;	
	long list_of_longs[] = {-3, 7, 3, 211};
	int len = 4;

	long *array_of_longs = ft_calloc(len, sizeof(long));

	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	
	t_stack *stack = create_stack(array_of_longs, len);

	int target = find_target(num, stack);	

	printf("number A: %d --> %d (B target)\n", num, target);

	#endif
	


	#ifdef COST_TO_TOP_TEST
	
	int index_a = 2;
	int index_target = 1;
	int size_a = 4;
	int size_b = 4;

	printf("%d\n", cost_to_top(index_target, index_a, size_a, size_b));
	
	#endif


	#ifdef FIND_CHEAPEST_TEST

	int size = 4;
	int cost_to_top[] = {1, 4, 0, 10};

	int result = find_cheapest(cost_to_top, size);
	printf("%d\n", result);
	

	#endif

	#ifdef TURK_TEST

	
	long list_of_longs_a[] = {10, -5, 100, 2};
	int len_a = 4;

	long list_of_longs_b[] = {-3, 7, 3, 211};
	int len_b = 4;
	
	long *array_of_longs_a = ft_calloc(len_a, sizeof(long));
	long *array_of_longs_b = ft_calloc(len_b, sizeof(long));

	int i = 0;
	while (i < len_a)
	{
		array_of_longs_a[i] = list_of_longs_a[i];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		array_of_longs_b[i] = list_of_longs_b[i];
		i++;
	}
	
	t_stack *stack_a = create_stack(array_of_longs_a, len_a);
	t_stack *stack_b = create_stack(array_of_longs_b, len_b);
	
	turk(stack_a, stack_b);

	#endif
}
