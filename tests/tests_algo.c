/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:20:23 by jchartie          #+#    #+#             */
/*   Updated: 2026/01/27 11:14:07 by jchartie         ###   ########.fr       */
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
	
	#ifdef CREATE_TARGETS_TEST
	
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

	int *targets = create_targets(stack_a, stack_b);	
	// free(array_of_longs);
	
	i = 0;
	while (i < 4)
	{
		printf("number A: %ld --> %d (Target B)\n", stack_a -> head -> number, targets[i]);
		stack_a -> head = stack_a -> head -> next;
		i++;
	}

	#endif

	#ifdef COST_TO_TOP_TEST
	
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

	int *targets = create_targets(stack_a, stack_b);	
	int	*cost_to_top = cost_to_tops(targets, stack_a, len_a, len_b);

	i = 0;
	while (i < 4)
	{
		printf("number A: %ld --> %d (Index Target B) --> %d (Cost to top)\n", stack_a -> head -> number, targets[i], cost_to_top[i]);
		stack_a -> head = stack_a -> head -> next;
		i++;
	}

	#endif

}
