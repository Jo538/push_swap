/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:20:23 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/26 15:39:49 by jchartie         ###   ########.fr       */
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

	t_list *temp_from_head_a;
	t_list *temp_from_end_a;
	t_list *temp_from_head_b;
	t_list *temp_from_end_b;	

	
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

	int *targets;
	targets = find_targets(stack_a, stack_b);	
	// free(array_of_longs);
	
	temp_from_head_a = stack_a -> head;
	temp_from_end_a = stack_a -> tail;
	temp_from_head_b = stack_b -> head;
	temp_from_end_b = stack_b -> tail;

	i = 0;
	while (temp_from_head_a)
	{
		printf("number A: %ld --> %d (B target)\n", temp_from_head_a -> number, targets[i]);
		temp_from_head_a = temp_from_head_a -> next;
		i++;
	}

	#endif

}
